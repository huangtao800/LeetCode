#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> already;
        int start=0, end=0;
        int maxLength = 0;
        for(int i=0;i<s.length();i++){
            map<char,int>::iterator itr = already.find(s[i]);
            if(itr==already.end()){
                already[s[i]] = i;
                end = i;
            }else{
                maxLength = max(maxLength,end-start+1);
                start = max(start,already[s[i]]+1);
                already[s[i]] = i;
                end = i;
            }
        }
        maxLength = max(maxLength,end-start+1);
        return maxLength;
    }
};

int main(){
    Solution s;
    int r = s.lengthOfLongestSubstring("dvdf");
    cout << r << endl;
    return 0;
}