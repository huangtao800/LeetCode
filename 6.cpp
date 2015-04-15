#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        vector<vector<char> > vRows;
        for(int i=0;i<nRows;i++){
        	vRows.push_back(vector<char>());
        }
        int start = 0;
        while(true){
        	for(int i=0;i<nRows&&start<s.length();i++,start++){
        		vRows[i].push_back(s[start]);
        	}
        	if(start>=s.length()){
        		break;
        	}
        	for(int i=vRows.size()-2;i>=1 && start<s.length();i--,start++){
        		vRows[i].push_back(s[start]);
        	}
        }
        string r = "";
        for(int i=0;i<vRows.size();i++){
        	vector<char> c = vRows[i];
        	for(int j=0;j<c.size();j++){
        		r = r+c[j];
        	}
        }
        return r;
    }
};

int main(){
	Solution s;
	string r = s.convert("PAYPALISHIRING",3);
	cout << r << endl;
	return 0;
}