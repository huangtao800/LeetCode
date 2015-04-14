#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<=1){
        	return 0;
        }

        int n = num.size();
        int mini = num[0], maxi = num[0];
        for(int i=1;i<num.size();i++){
        	if(num[i]<mini){
        		mini = num[i];
        	}
        	if(num[i]>maxi){
        		maxi = num[i];
        	}
        }

        double bucketLen = (maxi - mini) * 1.0 / (n - 1);

        vector<int> buckets(2*n,-1);
        for(int i=0;i<n;i++){
        	int index = (int) ((num[i] - mini) / bucketLen);
        	int minIndex = index * 2;
        	if(buckets[minIndex]==-1 && buckets[minIndex+1]==-1){
        		buckets[minIndex] = num[i];
        		buckets[minIndex+1] = num[i];
        	}else{
        		buckets[minIndex] = min(buckets[minIndex], num[i]);
        		buckets[minIndex+1] = max(buckets[minIndex+1], num[i]);
        	}
        }

        int maxGap = 0;
        int lastBucketIndex = 0;
        for(int i=1;i<n;i++){
        	if(buckets[2*i] == -1){
        		continue;
        	}
        	maxGap = max(maxGap, buckets[2*i]-buckets[2*lastBucketIndex+1]);
        	lastBucketIndex = i;
        }

        return maxGap;
    }
};

int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(4);

	Solution s;
	int r = s.maximumGap(nums);
	cout << r << endl;
	return 0;
}