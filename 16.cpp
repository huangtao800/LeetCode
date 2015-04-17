#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
  		sort(num.begin(), num.end());
  		int distance = INT_MAX;
  		int result = 0;
  		for(int i=0;i<num.size();i++){
  			int currentDis = twoSum(num,i,target-num[i]);
  			if(abs(currentDis)<abs(distance)){
  				distance = abs(currentDis);
  				result = target + currentDis;
  			}
  		}
  		return result;
    }

private:
	int twoSum(const vector<int> &num, int index, int target){
		int left = 0, right = num.size()-1;
		int distance = INT_MAX;

		while(left<right){
			if(left==index){
				left++;
				continue;
			}
			if(right==index){
				right--;
				continue;
			}
			
			int sum = num[left]+num[right];
			if(sum==target){
				return 0;
			}
			if(sum<target){
				left++;
			}else{
				right--;
			}

			int currentDis = sum - target;
			if(abs(currentDis) < abs(distance)){
				distance = currentDis;
			}
		}
		return distance;
	}
};

int main(){
	int num[] = {1,1,-1,-1,3};
	vector<int> v(num, num+5);

	Solution s;
	int r = s.threeSumClosest(v,-1);

	cout << r << endl;
	return 0;
}