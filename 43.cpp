#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() < num2.length())   swap(num1, num2);
        int length1 = num1.length(), length2 = num2.length();
        if(num1=="0"||num2=="0")    return "0";
        vector<string> multiList;
        for(int i=length2-1;i>=0;i--){
            int progress = 0;
            string tmpMultiply(length2-1-i,'0');
            for(int j=length1-1;j>=0;j--){
                int tmpResult = (num2[i]-'0') * (num1[j]-'0') + progress;
                progress = tmpResult / 10;
                tmpResult = tmpResult % 10;
                tmpMultiply = to_string(tmpResult) + tmpMultiply;
            }
            if(progress>0)  tmpMultiply = to_string(progress) + tmpMultiply;
            multiList.push_back(tmpMultiply);
        }

        int i=0;
        string result;
        int progress = 0;
        while(true){
            int tmpResult = 0;
            bool toEnd = true;
            for(int x=0;x<multiList.size();x++){
                string cur = multiList[x];
                int curLength = cur.length();
                if(curLength-1-i>=0){
                    toEnd = false;
                    tmpResult+=(cur[curLength-1-i] - '0');
                }
            }
            if(toEnd)   break;
            tmpResult+=progress;
            progress = tmpResult / 10;
            tmpResult = tmpResult % 10;
            result = to_string(tmpResult) + result;
            i++;
        }
        if(progress>0)  result = to_string(progress) + result;
        return result;
    }
};

int main(){
    Solution s;
    string r = s.multiply("9","99");
    cout << r << endl;
    return 0;
}