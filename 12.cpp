#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string *roman[4];
        string single[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundreds[] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[9] = {"M","MM","MMM"};
        roman[0] = single;
        roman[1] = tens;
        roman[2] = hundreds;
        roman[3] = thousands;

        int i = 0;
        int current = 0;
        string result = "";
        while(num>0){
        	current = num % 10;
        	if(current!=0){
        		result = roman[i][current-1] + result;
        	}
        	num /= 10;
        	i++;
        }
        return result;
    }
};

int main(){
	Solution s;
	string str = s.intToRoman(1990);
	cout << str << endl;
	return 0;
}