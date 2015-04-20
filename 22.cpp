#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        findParenthesis(result, "",n,n);
        return result;
    }
private:
    void findParenthesis(vector<string> &result, string already, int leftNum, int rightNum){
        if(leftNum==0 && rightNum==0){
            result.push_back(already);
            return;
        }
        
        int sum = leftNum + rightNum;
        for(int i=0;i<sum;i++){
            if(leftNum>0){
                string update = already+'(';
                findParenthesis(result, update, leftNum-1, rightNum);
            }
            if(rightNum>0){
                string update = already+')';
                if(!violate(update)){
                    findParenthesis(result, update, leftNum, rightNum-1);
                }
            }
        }
    }
    
    bool violate(string str){
        int leftNum=0, rightNum=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                leftNum++;
            }else{
                rightNum++;
            }
            if(rightNum > leftNum)  return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    std::vector<string> v = s.generateParenthesis(3);
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    cout << v.size()<<endl;
    return 0;
}