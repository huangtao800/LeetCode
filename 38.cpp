#include <string>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        else return readDigits(countAndSay(n-1));
    }
    
private:
    string readDigits(string n){
        string result;
        int count = 1;
        char last = n[0];
        for(int i=1; i<n.length();i++){
            if(n[i] == last)    count++;
            else{
                result = result + to_string(count) + last;
                count = 1;
                last = n[i];
            }
        }
        
        result = result + to_string(count) + last;
        return result;        
    }
};

int main(){
    Solution s;
    string r = s.countAndSay(10);
    cout <<r << endl;
    return 0;
}