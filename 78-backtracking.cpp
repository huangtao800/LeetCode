class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        int length = nums.size();
        map<int, bool> alreadyPicked;
        vector<int> subset;
        for(int i=0;i<=length;i++){
            pickNumbers(i,subset, result,nums,-1,alreadyPicked);
        }
        return result;
    }
    
    void pickNumbers(int n, vector<int> subset, vector<vector<int> > &result, vector<int> &nums, int start, map<int, bool> alreadyPicked){
        if(n==0){
            result.push_back(subset);
            return;
        }
        // map<int,bool> tmpMap = alreadyPicked;
        vector<int> tmpSubset = subset;
        
        for(int i=start+1;i<nums.size();i++){
            if(!alreadyPicked[nums[i]]){
                alreadyPicked[nums[i]] = true;
                subset.push_back(nums[i]);
                pickNumbers(n-1,subset, result, nums,i, alreadyPicked);
                subset = tmpSubset;
            }
        }
    }
};