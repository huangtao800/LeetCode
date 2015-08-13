#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m)	return 0;
        if(m==0)	return 1;

        int f[n][m];	// f[i][j] represents the number of distinct subsequences of T[j,...,m-1] in S[i,...,n-1]
        char tLast = t[t.size()-1];
        int tLastNum = 0;
        for(int i=n-1;i>=0;i--){
        	if(s[i] == tLast)	tLastNum++;
        	f[i][m-1] = tLastNum;
        }

        for(int i=m-2;i>=0;i--){
        	f[n-1][i] = 0;
        }

        for(int i=n-2;i>=0;i--){
        	for(int j=m-2;j>=0;j--){
        		if(s[i]==t[j]){ // check if s[i] match t[j]
        			f[i][j] = f[i+1][j] + f[i+1][j+1];	// We may delete s[i] or preserve s[i]
        		}else{
        			f[i][j] = f[i+1][j];	// We must delete s[i]
        		}
        	}
        }

        return f[0][0];
    }
};

int main(){
	Solution solution;
	string s= "aabbccd";
	string t = "abcd";
	int result = solution.numDistinct(s, t);
	cout << result << endl;
	return 0;
}