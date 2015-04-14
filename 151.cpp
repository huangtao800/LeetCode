#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s,ios_base::in);
        vector<string> wordList;
        string word;
        while(ss>>word){
        	wordList.push_back(word);
        }
        s = "";
        for(int i=wordList.size()-1;i>=0;i--){
        	s+=wordList[i];
        	if(i!=0){
        		s+=" ";
        	}
        }
    }
};

int main(){
	string a = "  I am  a   boy  ";
	Solution s;
	s.reverseWords(a);

	cout << a << endl;
	return 0;
}