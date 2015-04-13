#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int high = (int) (log(n) / log(26));
        cout<<high<<endl;
        vector<char> result;
        
        for(int i=high;i>=1;i--){
            int base = pow(26, i);
            int time = n / base;
            char current = 'A' + time - 1;
            result.push_back(current);
            
            n = n - time * base;
        }
        
        if(n > 0){
            char tail = 'A' + n - 1;
            result.push_back(tail);
        }
        
        string s;
        for(int i=0;i<result.size();i++){
            s = s + result[i];
        }
        return s;
    }
};

int main(){
    Solution s;
    string r = s.convertToTitle(702);
    cout << r <<endl;
    return 0;
}