#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)  return "";
        if(strs.size()==1)  return strs[0];
        
        string first = strs[0];
        string result = "";
        for(int i=0;i<first.length();i++){
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].length()){
                    return result;
                }
                if(first[i]!=strs[j][i]){
                    return result;
                }
            }
            result += first[i];
        }
        return result;
    }
};

int main(){
    return 0;
}