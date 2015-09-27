#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string extend = s + "#" + rev_s;
        vector<int> lps(extend.size(), 0);

        for(int i=1;i<extend.size();i++){
            int len = lps[i-1];
            if(extend[i] == extend[len]){
                lps[i] = len+1;
                continue;
            }
            while(len>0 && extend[i]!=extend[len]){
                len = lps[len-1];
            }
            lps[i] = (len += extend[i] == extend[len]);
        }
        
        string remain = rev_s.substr(0, s.size()-lps.back());
        string result = remain + s;
        return result;
    }

};

int main(){
	Solution s;
	string r = s.shortestPalindrome("aacecaaa");
	cout << r << endl;
	return 0;
}