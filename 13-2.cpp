#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int result = 0;
        for(int i=0;i<s.size()-1;i++){
            if(roman[s[i]]>=roman[s[i+1]]){
                result += roman[s[i]];
            }else{
                result -= roman[s[i]];
            }
        }
        result += roman[s[s.size()-1]];
        return result;
    }
};
int main(){
    Solution s;
    int r = s.romanToInt("MDCCCXCIX");
    cout << r << endl;
}