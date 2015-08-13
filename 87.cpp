#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1.size()==0 && s2.size()==0)	return true;
    	if(s1==s2)	return true;

    	int length = s1.size();
        vector<int> c(26,0);
        for(int i=0;i<length;i++){
        	c[s1[i]-'a']++;
        	c[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
        	if(c[i]!=0)	return false;
        }


        for(int i=1;i<length;i++){
        	string s1Left = s1.substr(0, i);
        	string s1Right = s1.substr(s1Left.size());

        	string s2Left1 = s2.substr(0, i);
        	string s2Right1 = s2.substr(s2Left1.size());
        	if(isScramble(s1Left, s2Left1) && isScramble(s1Right, s2Right1))	return true;

        	string s2Left2 = s2.substr(0, length-i);
        	string s2Right2 = s2.substr(s2Left2.size());
        	if(isScramble(s1Left, s2Right2) && isScramble(s1Right, s2Left2))	return true;
        }
        return false;
    }

};

int main(){
	Solution s;
	string s1 = "abcd";
	string s2 = "bdac";
	cout << s.isScramble(s1, s2) << endl;
	return 0;
}