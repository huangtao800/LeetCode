#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size())	return false;
        if(s1.size()==0)	return s2==s3;
        if(s2.size()==0)	return s1==s3;

        if(s3[0]==s1[0] && s3[0]==s2[0]){
        	return isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
        }else if(s3[0]==s1[0]){
        	return isInterleave(s1.substr(1), s2, s3.substr(1));
        }else if(s3[0]==s2[0]){
        	return isInterleave(s1, s2.substr(1), s3.substr(1));
        }else{
        	return false;
        }
    }
};

int main(){
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";

	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}