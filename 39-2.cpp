#include <vector>
#include <algorithm>
using namespace std;

//using backtracking
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>::iterator itr = unique(candidates.begin(),candidates.end());
        candidates.resize(distance(candidates.begin(),itr));
        vector<vector<int> > result;
        vector<int> already;
        findCombination(candidates, 0, target, result, already);
        return result;
    }
    
    void findCombination(vector<int> &candidates, int start, int target, vector<vector<int> > &result, vector<int> &already){
        vector<int> tmpAlready = already;
        for(int i=start;i<candidates.size();i++){
            if(candidates[i] < target){
                already.push_back(candidates[i]);
                findCombination(candidates, i, target-candidates[i], result,already);
            }else if(candidates[i] == target){
                already.push_back(candidates[i]);
                result.push_back(already);
            }
            already = tmpAlready;
        }
    }
};

int main(){
    return 0;
}