#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int start = 0, end = 0;
        for(;start<str.length();start++){
        	if(!isspace(str[start])){
        		break;
        	}
        }
        if(start>=str.length())	return 0;
        int isNegative = false;
        if(str[start] == '-'){
        	isNegative = true;
        	start++;
        }else if(str[start]=='+'){
        	start++;
        }
        if(!isdigit(str[start]))	return 0;
        while(start<str.length()){
        	if(str[start]=='0'){
        		start++;
        	}else{
        		break;
        	}
        }
        if(start>=str.length())	return 0;
        for(end=start;end<str.length();end++){
        	if(!isdigit(str[end])){
        		break;
        	}
        }
        string numString = str.substr(start,end-start);
        if(numString==(to_string(INT_MIN).substr(1)) && isNegative){
        	return INT_MIN;
        }
        if(numString.length()>to_string(INT_MAX).length()){
        	return isNegative?INT_MIN:INT_MAX;
        }
        if(numString.length()==(to_string(INT_MAX)).length()){
        	if(numString>(to_string(INT_MAX))){
        		return isNegative?INT_MIN:INT_MAX;
        	}
        }
        int result = 0;
        for(int i=end-1, j=0;i>=start;i--,j++){
        	result+= (str[i] - '0') * pow(10,j);
        }
        return isNegative?(-result):result;
    }
};

int main(){
	Solution s;
	int r = s.myAtoi("    +11191657170");
	cout << r << endl;
}