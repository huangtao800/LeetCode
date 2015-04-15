#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        if(length==0||length==1)    return s;
        int start= 0, end = 0;
        int maxLength = 1;
        map<char,vector<int> > already;

        for(int i=0;i<length;i++){
        	map<char,vector<int> >::iterator it = already.find(s[i]);
        	if(it==already.end()){
        		already[s[i]] = vector<int>(1,i);
        	}else{
        		vector<int> v = already[s[i]];
        		for(int j=0;j<v.size();j++){
        			if(isPalindrome(s,v[j],i)){
        				if(i-v[j]+1 >= maxLength){
        					maxLength = i-v[j] + 1;
        					start = v[j];
        					end = i;
        				}
        			}
        		}
        		v.push_back(i);
        		already[s[i]] = v;
        	}
        }
        return s.substr(start, maxLength);
    }

private:
	bool isPalindrome(const string &s, int left, int right){
		while(left < right){
			if(s[left] != s[right]){
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};

int main(){
	Solution s;

	string r = s.longestPalindrome("bac1234321abc");
	cout << r << endl;
	return 0;
}