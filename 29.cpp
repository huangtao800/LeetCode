#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)  return INT_MAX;
        int result = 0;
        if(dividend>=0 && divisor>0){
            while(dividend>0){
                dividend -= divisor;
                result++;
                if(result < 0){
                    return INT_MAX;
                }
            }
            if(dividend<0)  result--;
        }else if(dividend<=0 && divisor<0){
            while(dividend<0){
                dividend -= divisor;
                result++;
                if(result<0){
                    return INT_MAX;
                }
            }
            if(dividend>0)  result--;
        }else if(dividend <=0 && divisor>0){
            while(dividend<0){
                dividend += divisor;
                result--;
                if(result>0){
                    return INT_MAX;
                }
            }
            if(dividend>0)  result++;
        }else if(dividend >=0 && divisor<0){
            while(dividend>0){
                dividend += divisor;
                result--;
                if(result>0){
                    return INT_MAX;
                }
            }
            if(dividend<0)  result++;
        }
        return result;
    }
};

int main(){
    Solution s;
    int r = s.divide(-2147483645,-1);
    cout <<r << endl;
}