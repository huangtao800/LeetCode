#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if(days<=1) return 0;
        int f[days];
        
        f[0] = 0;
        for(int i=1;i<days;i++){
            f[i] = max(f[i-1], prices[i] - prices[i-1] + f[i-1]);
        }
        
        return f[days-1];
    }
};