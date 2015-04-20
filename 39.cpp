#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>::iterator itr = unique(candidates.begin(),candidates.end());
        candidates.resize(distance(candidates.begin(),itr));
        vector<vector<int> > result;
        for(int i=0;i<candidates.size();i++){
            vector<int> already;
            findCombination(candidates, i, target, result, already);
        }
        return result;
    }
    
    void findCombination(vector<int> &candidates, int start, int target, vector<vector<int> > &result, vector<int> already){
        if(start>=candidates.size())    return;
        if(candidates[start] > target)  return;
        if(candidates[start]==target){
            already.push_back(candidates[start]);
            result.push_back(already);
            return;
        }
        already.push_back(candidates[start]);
        for(int i=start; i<candidates.size();i++){
            if(candidates[i] > target-candidates[start]){
                break;
            }
            findCombination(candidates,i, target-candidates[start], result, already);
        }
    }
};

int main(){
    return 0;
}