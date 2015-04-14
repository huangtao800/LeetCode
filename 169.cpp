#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int size = num.size();
        map<int,int> result;
        for(int i=0;i<num.size();i++){
            if(result.find(num[i]) != result.end()){
                result[num[i]]++;
            }else{
                result[num[i]] = 1;
            }
        }
        
        for(map<int,int>::iterator it=result.begin();it!=result.end();it++){
            if(it->second >= (size / 2.0)){
                return it->first;
            }
        }
    }
};

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    Solution s;
    int result = s.majorityElement(nums);
    cout<<result<<endl;
}