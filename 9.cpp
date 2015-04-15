#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)	return false;
        int bits = getBits(x);
        int highestBit, lowestBit;
        while(bits>1){
        	highestBit = getHighestBit(x,bits);
        	lowestBit = getLowestBit(x);
        	if(highestBit==lowestBit){
        		x = removeHighestBit(x,highestBit,bits);
        		x = removeLowestBit(x);
        		bits-=2;
        	}else{
        		return false;
        	}
        }
        return true;
    }
private:
	int getBits(int x){
		if(x==0 || x==1)	return 1;
		return (int)(log10(x) + 1);
	}

	int getHighestBit(int x, int bits){
		return x / ((int)(pow(10,bits-1)));
	}
	
	int getLowestBit(int x){
		return x % 10;
	}

	int removeHighestBit(int x, int highestBit, int bits){
		return x - highestBit * pow(10,bits-1);
	}

	int removeLowestBit(int x){
		return x / 10;
	}
};

int main(){
	Solution s;
	bool r = s.isPalindrome(-2147447412);
	cout << r << endl;
	return 0;
}