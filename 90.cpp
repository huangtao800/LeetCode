#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> subset;
        for(int i=0; i<=nums.size();i++){
            pickNumbers(nums, i, 0, result, subset);
        }
        
        return result;
    }
    
    void pickNumbers(vector<int> &nums, int n, int start, vector<vector<int> > &result, vector<int> &subset){
        if(n==0){
            result.push_back(subset);
            return;
        }
        
        vector<int> tmp = subset;
        int last = 0;
        for(int i=start;i<nums.size();i++){
            if(i>start){
                if(nums[i]== last)  continue;
            }
            last = nums[i];
            subset.push_back(nums[i]);
            pickNumbers(nums, n-1, i+1, result, subset);
            subset = tmp;
        }
    }
};

int main(){
    int n[] = {0,1,2,3,4,5,6,7,8,9,10};
    vector<int> v(n,n+11);
    // cout << v.size() << endl;
    Solution s;
    vector<vector<int> > r = s.subsetsWithDup(v);
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[i].size();j++){
            cout << r[i][j]<<" ";
        }
        cout << endl;
    }
}