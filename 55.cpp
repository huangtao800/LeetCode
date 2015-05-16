#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size()==1)  return true;
        int length = nums[0];
        int begin = 0;
        int end = begin + length;
        int maxi = INT_MIN;
        while(true){
            for(int i=end;i>=begin;i--){
                if(nums[i] + i >= nums.size() - 1)  return true;
                maxi = max(maxi, nums[i] + i);
            }
            if(maxi<=end)   break;
            begin = end+1;
            end = maxi;
        }
        return false;
    }
};

int main(){
    Solution s;
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    cout << s.canJump(v)<< endl;
}