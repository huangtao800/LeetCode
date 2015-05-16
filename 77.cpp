#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if(k==0 || k>n)    return result;
        vector<int> r;
        pickNumber(1,n,k,r,result);
        return result;
    }
    
    void pickNumber(int start, int end, int remain, vector<int> &r, vector<vector<int> > &result){
        if(remain==0){
            result.push_back(r);
            return;
        }
        
        vector<int> tmp = r;
        for(int i=start;i<=end-remain+1;i++){
            r.push_back(i);
            pickNumber(i+1, end, remain-1, r, result);
            r=tmp;
        }
    }
};

int main(){
    Solution s;
    vector<vector<int> > r = s.combine(4,3);
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[i].size();j++){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
}