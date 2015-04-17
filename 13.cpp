#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string,int> roman;
        roman["I"] = 1;
        roman["IV"] = 4;
        roman["V"] = 5;
        roman["IX"] = 9;
        roman["X"] = 10;
        roman["XL"] = 40;
        roman["L"] = 50;
        roman["XC"] = 90;
        roman["C"] = 100;
        roman["CD"] = 400;
        roman["D"] = 500;
        roman["CM"] = 900;
        roman["M"] = 1000;
        
        int result = 0;
        for(int i=0;i<s.length();i++){
            if(i<s.length()-1){
                if(roman[s.substr(i,2)]!=0){
                    result += roman[s.substr(i,2)];
                    i++;
                }else{
                   result += roman[s.substr(i,1)]; 
                }
            }else{
                result += roman[s.substr(i,1)];
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    int r = s.romanToInt("MCM");
    cout << r << endl;
}