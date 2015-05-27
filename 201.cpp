#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n || m==0)    return m;
        int nums = n - m + 1;
        int highest = static_cast<int> (floor(log(m) / log(2)));
        int start = static_cast<int> (round(pow(2, highest)));
        int result = 0;
        
        for(int i=highest; i>=0; i--){
            if(nums > pow(2, i))    break;
            else{
                int offset1 = (m-start) / pow(2,i);
                int offset2 = (n-start) / pow(2,i);
                if(offset1==offset2){
                    result = result | (((m >> (i)) & 1) << i);
                }
            }
        }
        
        return result;
    }
};

int main(){
    Solution s;
    int m=4, n=6;
    int r = s.rangeBitwiseAnd(23,24);
    cout << r << endl;
}