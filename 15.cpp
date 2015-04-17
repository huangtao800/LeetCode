#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
  		if(num.size()<3)	return vector<vector<int> >();
  		sort(num.begin(), num.end());
  		vector<vector<int> > result;
  		for(int i=0;i<num.size();i++){
  			if(num[i]>0){
  				return result;
  			}
  			if(i>=1){
  				if(num[i]==num[i-1]){
  					continue;
  				}
  			}
  			vector<vector<int> > index = twoSum(num, i);
  			for(int j=0;j<index.size();j++){
  				if(index[j][0]>i){
  					vector<int> triple;
  					triple.push_back(num[i]);
  					triple.push_back(num[index[j][0]]);
  					triple.push_back(num[index[j][1]]);
  					result.push_back(triple);
  				}
  			}
  		}
  		return result;
    }

private:
	vector<vector<int> > twoSum(const vector<int> &num, int index){
		int sum = -num[index];
		int left = 0, right = num.size()-1;
		int last = -1;
		vector<vector<int> > result;
		while(left<right){
			if(left==index){
				left++;
				continue;
			}
			if(right==index){
				right--;
				continue;
			}
			if(last!=-1){
				if(num[left]==num[last]){
					left++;
					continue;
				}
			}
			if(num[left] + num[right] == sum){
				vector<int> pair;
				pair.push_back(left);
				pair.push_back(right);
				result.push_back(pair);
				last = left++;
				right--;
			}else if(num[left] + num[right] < sum){
				last = left++;
			}else{
				right--;
			}
		}
		return result;
	}
};

int main(){
	int num[] = {0,0,0,0,0,0,0};
	vector<int> v(num, num+7);

	Solution s;
	vector<vector<int> > r = s.threeSum(v);

	for(int i=0;i<r.size();i++){
		vector<int> c = r[i];
		cout<<c[0]<<", "<<c[1]<<", "<<c[2]<<endl;
	}
	return 0;
}