#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool negative = x < 0;
        if(negative){
        	s = s.substr(1);
        }
        reverseString(s);
        int result = 0;
        try{
        	result = stoi(s);
        }catch(const out_of_range& e){
        	result = 0;
        }
        return result;
    }
private:
	void reverseString(string &s){
		int length = s.length();
		if(length==0){
			return;
		}

		int left = 0, right = length-1;
		while(left<right){
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;

			left++;
			right--;
		}
	}
};

int main(){
	Solution s;
	int r = s.reverse(1000000003);
	cout << r << endl;
}