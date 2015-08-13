#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string alreadyProcess = "";
		string toProcess = s;
		splitIpAddress(result, alreadyProcess, toProcess, 0);
		return result;      
    }


    void splitIpAddress(vector<string> &result, string alreadyProcess, string toProcess, int index){
    	if(index==4){
    		if(toProcess.size()==0){
    			result.push_back(alreadyProcess);
    			return;
    		}else{
    			return;
    		}
    	}else{
    		if(toProcess.size()==0)	return;
    		
    		for(int i=0;i<toProcess.size();i++){
    			if(i>=3)	continue;
    			if(i==1){
    				if(toProcess[0]=='0')	break;
    			}
    			string toAppend = toProcess.substr(0,i+1);

    			string rest = toProcess.substr(toAppend.size());
    			string alreadyProcessCopy = alreadyProcess;
    			if(stoi(toAppend)>=0 && stoi(toAppend) <=255){

    				if(index==0){
    					alreadyProcess+=toAppend;
    				}else{
    					alreadyProcess = alreadyProcess + "." + toAppend;
    				}
    				splitIpAddress(result, alreadyProcess, rest, index+1);
    				alreadyProcess = alreadyProcessCopy;
    			}
    		}
    	}
    }
};

int main(){
	Solution s;
	string str = "010010";
	vector<string> result = s.restoreIpAddresses(str);
	for(int i=0;i<result.size();i++){
		cout<< result[i] << endl;
	}
	return 0;
}