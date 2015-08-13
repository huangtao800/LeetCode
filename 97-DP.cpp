#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        if(p!=m+n)  return false;

        bool f[n+1][m+1];   //f[i][j] = true means s3[i+j...n+m-1] is consist of s1[i...n-1] and s2[j...m-1] 
        for(int i=0;i<=m;i++){
            f[n][i] = s2.substr(i) == s3.substr(n+i);
        }
        for(int i=0;i<=n;i++){
            f[i][m] = s1.substr(i) == s3.substr(m+i);
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s3[i+j] && s2[j]==s3[i+j]){
                    f[i][j] = f[i+1][j] || f[i][j+1];
                }else if(s1[i]==s3[i+j]){
                    f[i][j] = f[i+1][j];
                }else if(s2[j]==s3[i+j]){
                    f[i][j] = f[i][j+1];
                }else{
                    f[i][j] = false;
                }
            }
        }
        return f[0][0];
    }
};

int main(){
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";

	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}