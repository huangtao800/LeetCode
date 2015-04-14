<<<<<<< HEAD
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
#include <string>
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        /*
        Consider n as a three-char string;
        n = a * 26^2 + b * 26 + c; 1 <= (a,b,c) <= 26
        */
        string s;
        while(n>0){
            int tail = n % 26; // tail represents c;
            if(tail == 0){
                tail = 26;  //c must be 26, thus last char mush be 'Z'; 
                s = 'Z' + s;
            }else{
                char c = 'A' + tail - 1;
                s = c + s;
            }
            
            n = n - tail;   // Remove last number and divided by 26;
            n = n / 26;     // In this way, b will be the last number.
        }
        return s;
    }
};

int main(){
    Solution s;
    string r = s.convertToTitle(676);
    cout << r << endl;

    return 0;

}