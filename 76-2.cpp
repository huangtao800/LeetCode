#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;
/**
* General idea: If there are still more characters not matched (required > 0), increment right. Otherwise, increment left.
**/ 
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0) return "";
        int required = t.size();
        vector<int> remain(128,0);
        int minWindowLength = INT_MAX;
        for(int i=0;i<t.size();i++){
            remain[t[i]]++;
        }
        
        int left = 0, right = 0;
        int start = 0;
        while(right <= s.size() && left < s.size()){
            if(required){
                if(right ==s.size())    break;
                remain[s[right]]--;
                if(remain[s[right]] >= 0)   required--;
                right++;
            }else{
                if(right - left < minWindowLength){
                    start = left;
                    minWindowLength = right - left;
                }
                remain[s[left]]++;
                if(remain[s[left]] > 0)    required++;
                left++;
            }
        }
        
        return minWindowLength==INT_MAX?(""):s.substr(start, minWindowLength);
    }
};

int main(){
	string s = "cbbbbbbba";
	string t = "";
	Solution solution;
	string result = solution.minWindow(s, t);
	cout << result << endl;
	return 0;
}