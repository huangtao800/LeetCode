#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)	return false;
        int xCopy = x;
        int reverse = 0;
        while(x>0){
        	reverse = 10 * reverse + x % 10;
        	x = x / 10;
        }
        return reverse == xCopy;
    }
};

int main(){
	Solution s;
	bool r = s.isPalindrome(2147447412);
	cout << r << endl;
	return 0;
}