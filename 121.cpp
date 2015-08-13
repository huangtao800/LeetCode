#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size()<=1)    return result;
        int mini = prices[0];
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] - mini > result)   result = prices[i] - mini;
            mini = min(mini, prices[i]);
        }
        
        return result;
    }
};

int main(){
    return 0;
}