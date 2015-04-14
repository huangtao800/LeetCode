/**
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	string str;
    	if((numerator>0 && denominator <0)||(numerator<0 && denominator>0)){
    		str = '-';
    	}
    	long longNum=abs((long)numerator);
    	long longDenom=abs((long)denominator);
    	long r = longNum;
    	long q;
        vector<long> quotient;
        vector<long> remainder;

        int start=0;
        bool isCircle = false;
        while(true){
        	q = r / longDenom;
        	r = r % longDenom;
        	if(r==0){
        		quotient.push_back(q);
        		break;
        	}
        	if((start=findIndex(remainder,r))!=-1){
        		start++;
        		quotient.push_back(q);
        		isCircle = true;
        		break;
        	}
        	quotient.push_back(q);
        	remainder.push_back(r);
        	r = r * 10;
        }
        if(!isCircle){
        	for(int i=0;i<quotient.size();i++){
        		if(i==1){
        			str = str + '.';
        		}
        		str = str + to_string(quotient[i]);
        	}
        }else{
        	for(int i=0;i<quotient.size();i++){
        		if(i==1){
        			str = str + '.';
        		}
        		if(i==start){
        			str = str + '(';
        		}
        		str = str + to_string(quotient[i]);
        	}
        	str = str + ")";
        }
        
        return str;
    }
private:
	int findIndex(const vector<long>& v, long p){
		for(int i=0;i<v.size();i++){
			if(v[i]==p){
				return i;
			}
		}
		return -1;
	}
};

int main(){
	Solution s;
	string r = s.fractionToDecimal(1,-2147483648);
	cout<< r << endl;
}