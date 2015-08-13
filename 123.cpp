#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)	return 0;
        if(prices.size()==2)	return max(0, prices[1] - prices[0]);

        int mini = prices[0];
        int secondMini = prices[1];
        int minResult = 0;
        int secondResult = 0;

        for(int i=1;i<prices.size();i++){
        	
        }
    }
};