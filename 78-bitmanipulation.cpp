class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        int size = nums.size();
        int length = static_cast<int> (pow(2,size));
        for(int i=0;i<length;i++){
            putSubset(result, nums, size, i);
        }
        return result;
    }
    
    void putSubset(vector<vector<int> > &result, vector<int>& nums, int size, int number){
        vector<int> subset;
        if(size==0){
            result.push_back(subset);
            return;
        }
        int current = 1 << (size - 1);
        int count = 0;
        while(count<size){
            if(current & number){
                subset.push_back(nums[count]);
            }
            count++;
            current = current >> 1;
        }
        result.push_back(subset);
    }
};