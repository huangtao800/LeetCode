#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
    	if(s.size()==0)	return "";

        unordered_map<char, int> tAppear;	// number of appearance in string t
        unordered_map<char, int> tMap;	// convert string t to a hashmap
        list<int> matchIndexList;		// indexes in string s which matchs characters in string t

        for(int i=0;i<t.size();i++){
        	tAppear[t[i]] = 0;
        	tMap[t[i]]++;
        }

        int minWindowLength = INT_MAX;
        int start = 0;
        int end = 0;
        int left = 0;
        int right = 0;

        for(left=0;left<s.size();left++){	// Let left be the first match index
        	if(tMap[s[left]]){
        		tAppear[s[left]]++;
        		matchIndexList.push_back(left);
        		break;
        	}
        }

        if(findAllCharacter(tAppear, tMap))	return string(1, s[left]);	// t contains only one character

        for(right = left+1; right<s.size();right++){
        	if(tMap[s[right]] == 0)	continue;

        	// find a match
        	tAppear[s[right]]++;
        	matchIndexList.push_back(right);

        	if(findAllCharacter(tAppear, tMap)){	// check if all chars are found
        		if(right-left+1 < minWindowLength){
        			start = left;
        			end = right;
        			minWindowLength = end - start + 1;
        		}

        		int firstMatch = 0;	
        		while(true){
        			firstMatch = matchIndexList.front();	// iteratively remove the first matched char until at least one char is missing
        			tAppear[s[firstMatch]]--;
        			matchIndexList.pop_front();

        			if(tAppear[s[right]] == tMap[s[right]] && findAllCharacter(tAppear, tMap)){	// check if all chars are found (the first if statement is used to cut off unnecessarily call findAllCharacter)
        				firstMatch = matchIndexList.front();
        				left = firstMatch;
        				if(right - left + 1 < minWindowLength){
        					start = left;
        					end = right;
        					minWindowLength = end - start + 1;
        				}
        			}else{
        				firstMatch = matchIndexList.front();
        				left = firstMatch;
        				break;
        			}
        		}
        	}
        }

        string result;
        if(end>start){
        	result = s.substr(start, minWindowLength);
        }
        return result;
    }

    /* Check if all characters have been found
    */
    bool findAllCharacter(unordered_map<char, int>& tAppear, unordered_map<char, int> &tMap){
    	for(unordered_map<char,int>::iterator itr = tMap.begin(); itr!=tMap.end(); ++itr){
    		char c = itr->first;
    		if(tAppear[c] < tMap[c])	return false;
    	}
    	return true;
    }
};

int main(){
	string s = "abcabdebac";
	string t = "cda";
	Solution solution;
	string result = solution.minWindow(s, t);
	cout << result << endl;
	return 0;
}