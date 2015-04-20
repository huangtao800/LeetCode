#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<=1)   return;
        int pos = 0;
        for(pos=num.size()-1;pos>=1;pos--){
            if(num[pos]>num[pos-1]) break;
        }
        if(pos==0){
            cout << "reverse" << endl;
            reverse(num.begin(),num.end()); 
        }
        int tmp = num[pos-1];
        num[pos-1] = num[pos];
        num[pos] = tmp;
        sort(num.begin()+pos, num.end());
    }
};

int main(){
    Solution s;
    std::vector<int> v(2,1);
    s.nextPermutation(v);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}