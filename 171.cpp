/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;    
class Solution {
public:
    int titleToNumber(string s) {
    	int length = s.length();
        const char *c = s.c_str();
        int result = 0;
        for(int i=length-1;i>=0;i--){
        	result += pow(26,(length - i -1)) * (c[i] - 'A' + 1);
        }
    }
};


int main(){
	Solution s;
	int result = s.titleToNumber("ABC");
	cout << result << endl;
	return 0;
}