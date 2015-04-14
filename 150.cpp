#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int result = 0;
        for(int i=0;i<tokens.size();i++){
        	if(!(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")){
        		int number = stoi(tokens[i]);
        		s.push(number);
        	}else{
        		int b = s.top();
        		s.pop();
        		int a = s.top();
        		s.pop();
        		int c = calculate(a,b,tokens[i]);
        		s.push(c);
        	}
        }

        return s.top();
    }

private:
	int calculate(int a, int b, string opt){
		if(opt=="+"){
			return a+b;
		}
		if(opt=="-"){
			return a-b;
		}
		if(opt=="*"){
			return a*b;
		}
		return a/b;
	}
};

int main(){
	vector<string> v;
	v.push_back("3");
	v.push_back("-4");
	v.push_back("+");

	Solution s;
	int r=s.evalRPN(v);
	cout << r << endl;
	return 0;
}