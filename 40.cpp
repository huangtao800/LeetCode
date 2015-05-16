#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        vector<int> already;
        findCombination(num, 0, target, result, already);
        return result;
    }
    
    void findCombination(vector<int> &num, int start, int target, vector<vector<int> > &result, vector<int> &already){
        vector<int> tmpAlready = already;
        for(int i=start; i<num.size();i++){
            if(i>start && num[i]==num[i-1]) continue;
            if(num[i] < target){
                already.push_back(num[i]);
                findCombination(num, i+1, target-num[i], result, already);
            }else if(num[i] == target){
                already.push_back(num[i]);
                result.push_back(already);
                return;
            }
            already = tmpAlready;
        }
    }
};

int main(){
    int num[] = {4,1,1,4,4,4,4,2,3,5};
    std::vector<int> v(num, num+10);
    Solution s;
    vector<vector<int> > r = s.combinationSum2(v, 10);
    for(int i=0;i<r.size();i++){
        for(int j=0; j<r[i].size();j++){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}