#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        for(int i=0;i<length;i++){
        	if(nums[i]==0){
        		int nextNoneZero = findNextNoneZero(nums, i);
        		if(nextNoneZero==length)	return;
        		swap(nums[i], nums[nextNoneZero]);
        	}
        }
    }

    int findNextNoneZero(vector<int> &nums, int index){
    	for(int i=index+1;i<nums.size();i++){
    		if(nums[i]!=0)	return i;
    	}
    	return nums.size();
    }
};

int main(){
	return 0;
}