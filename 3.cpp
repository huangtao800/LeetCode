#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        list<char> already;
        int maxLength = 0;
        int currentLength = 0;
        for(int i=0;i<s.length();i++){
            char current = s[i];
            list<char>::iterator itr = find(already.begin(),already.end(),current);
            if(itr == already.end()){
                already.push_back(current);
                currentLength++;
            }else{
                if(currentLength>maxLength){
                    maxLength = currentLength;
                }
                already.erase(already.begin(),++itr);
                already.push_back(current);
                currentLength = already.size();
            }
        }
        maxLength = max(currentLength, maxLength);
        return maxLength;
    }
};

int main(){
    Solution s;
    int r = s.lengthOfLongestSubstring("dvdf");
    cout << r << endl;
    return 0;
}