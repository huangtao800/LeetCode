/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/
#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int result = n / 5;
        int logResult = log(n) / log(5);
        int maxPow = pow(5, logResult);
        int temp = 25;
        for(;temp<=maxPow;temp=temp*5){
        	result += (n/temp);
        }
        return result;
    }

};

int main(){
	Solution s;
	int n = 250;
	int r = s.trailingZeroes(n);
	cout<<r<<endl;
}