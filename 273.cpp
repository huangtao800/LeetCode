#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if(num==0)   return "Zero";
        unordered_map<int, string> number;
        init(number);
        string result = "";
        int base = 1;
        while(num>0){
        	int remain = num % 1000;
        	num = num / 1000;
        	string words = convertToWords(remain, number);
            if(words.empty()){ base*=1000; continue;}
        	if(base>=1000){
        		words = words + " " + number[base];
        	}

        	if(result.empty()){
        		result = words;
        	}else{
        		result = words + " " + result;
        	}

        	base *= 1000;
        }

        return result;
    }

private:
	string convertToWords(int remain, unordered_map<int, string>& number){
		string result = "";
        if(remain==0)   return result;
        if(remain>=100){
            result = number[remain/100] + " Hundred";
            remain = remain % 100;
        }

        string tmpString = "";
        if(remain <= 20){
            tmpString = number[remain];
        }else{
            tmpString = number[remain/10*10];
            if(remain%10!=0){
                tmpString = tmpString + " " + number[remain%10];
            }
        }

        if(result.empty())  result = tmpString;
        else{
            if(!tmpString.empty())  result = result + " " + tmpString;
        }
        return result;
	}

	void init(unordered_map<int, string>& number){
        number[0] = "";
        number[1] = "One";
        number[2] = "Two";
        number[3] = "Three";
        number[4] = "Four";
        number[5] = "Five";
        number[6] = "Six";
        number[7] = "Seven";
        number[8] = "Eight";
        number[9] = "Nine";
        number[10] = "Ten";
        number[11] = "Eleven";
        number[12] = "Twelve";
        number[13] = "Thirteen";
        number[14] = "Fourteen";
        number[15] = "Fifteen";
        number[16] = "Sixteen";
        number[17] = "Seventeen";
        number[18] = "Eighteen";
        number[19] = "Nineteen";
        number[20] = "Twenty";
        number[30] = "Thirty";
        number[40] = "Forty";
        number[50] = "Fifty";
        number[60] = "Sixty";
        number[70] = "Seventy";
        number[80] = "Eighty";
        number[90] = "Ninety";
        number[100] = "Hundred";
        number[1000] = "Thousand";
        number[1000000] = "Million";
        number[1000000000] = "Billion";
	}
};

int main(){
	Solution s;
	cout << s.numberToWords(1000010)<< endl;
	return 0;
}