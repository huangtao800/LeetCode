#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        map<int, vector<vector<string> > > record;
        return partitionSub(s, 0, record);
    }

    vector<vector<string> > partitionSub(string s, int startIndex, map<int, vector<vector<string> > > &record){
        vector<vector<string> > result;
        int length = s.size() - startIndex;
        if(length==0)	return result;
        
        for(int i=startIndex+1;i<=s.size();i++){
    		string former = s.substr(startIndex,i-startIndex);
    		if(isPalindrome(former)){
    			vector<vector<string> > subResults = record[i];
    			if(subResults.empty()){
    				record[i] = partitionSub(s, i, record);
    				subResults = record[i];
    				if(subResults.empty()){
    					result.push_back(vector<string>(1, former));
    					return result;
    				}
    			}

    			for(int j=0;j<subResults.size();j++){
    				vector<string> tmpResults = subResults[j];
    				tmpResults.insert(tmpResults.begin(), former);
    				result.push_back(tmpResults);
    			}
    		}
        }

        return result;
    }


    bool isPalindrome(string s){
    	if(s.size()==0)	return true;
    	for(int i=0,j=s.size()-1;i<j;i++,j--){
    		if(s[i]!=s[j])	return false;
    	}
    	return true;
    }
};

int main(){
	Solution s;
	vector<vector<string> > r = s.partition("bb");

	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}