#include <string>       // std::string
#include <iostream>     // std::cout
#include <vector>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool hasDot = false;
        bool hasExp = false;
        string current;
        vector<string> split;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]) || s[i]=='+' || s[i]=='-')   current+=s[i];
            else if(s[i]=='.'){
                if(hasDot || hasExp) return false;
                else{
                    hasDot = true;
                    split.push_back(current);
                    current.clear();
                }
            }else if(s[i]=='e'){
                if(hasExp)    return false;
                else{
                    hasExp = true;
                    split.push_back(current);
                    current.clear();
                }
            }else if(s[i]==' '){
                if(allSpaceNext(s, i))   break;
                else if(i==0 || s[i-1]==' ')  continue;
                else    return false;
            }else{
                return false;
            }
        }
        split.push_back(current);

        if(split.size()==3){
        	return isDouble(split[0], split[1]) && isInteger(split[2]);
        }else if(hasDot){
        	return isDouble(split[0], split[1]);
        }else if(hasExp){
        	return isInteger(split[0]) && isInteger(split[1]);
        }else{
        	return isInteger(split[0]);
        }
    }
    
    // check whether a.b is a valid double
    bool isDouble(string a, string b){
    	if(a.size()==0 && b.size()==0)	return false;
    	if(b.size()>0 && (b[0]=='+' || b[0]=='-'))	return false;
    	if(a.size()>0 && (a=="+" || a=="-") && b.size()==0)	return false;
    	return (isInteger(a) || a.size()==0 || a=="+" || a=="-") && (isInteger(b) || b.size()==0);
    }
    
    // check wheter input string can be converted into an integer
    bool isInteger(string s){
        if(s.size()==0) return false;
        bool hasSign = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-'){
                if(!hasSign && i==0)    continue;
                else    return false;
            }else if(isdigit(s[i])) continue;
            else    return false;
        }
        if(s=="-" || s=="+")	return false;
        return true;
    }
    
    // check whether all chars behind index are space
    bool allSpaceNext(string s, int index){
        for(int i=index+1; i<s.size();i++){
            if(s[i]!=' ')   return false;
        }
        return true;
    }
};

int main () {
  Solution s;
  cout << s.isNumber("1  ") << endl;
  return 0;
}