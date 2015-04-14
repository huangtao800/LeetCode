/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have
security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
Solution: let robSum[j] be the max number of robbing house 0 to house j,
then robSum[j] equals: if house j is rubbed, robSum[j] = robSum[j-2] + num[j];
if house j is not rubbed, then robSum[j] = robSum[j-1].
Thus, robSum[j] = max(robSum[j-2] + num[j], robSum[j-1]);
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rob(vector<int> &num) {
        int length = num.size();
        int robSum[length];
        if(length==0){
            return 0;
        }
        if(length==1){
            return num[0];
        }
        if(length==2){
            int result = num[0]>num[1]?num[0]:num[1];
            return result;
        }
        robSum[0] = num[0];
        robSum[1] = num[0]>num[1]?num[0]:num[1];
        
        int i = 2;
        for(;i<length;i++){
            robSum[i] = max(robSum[i-2]+num[i], robSum[i-1]);
        }
        
        return robSum[length-1];
    }
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(5);
    num.push_back(3);
    num.push_back(9);
    num.push_back(12);
    num.push_back(4);

    Solution s;
    int r = s.rob(num);
    cout<<r<<endl;
    return 0;
}