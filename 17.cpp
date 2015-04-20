#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)  return vector<string>();
        
        map<string, vector<string> > combination;
        map<char, vector<string> > letter;
        string two[] = {"a","b","c"};
        string three[] = {"d","e","f"};
        string four[] = {"g","h","i"};
        string five[] = {"j","k","l"};
        string six[] = {"m","n","o"};
        string seven[] = {"p","q","r","s"};
        string eight[] = {"t","u","v"};
        string nine[] = {"w","x","y","z"};
        letter['2'] = vector<string>(two,two+3);
        letter['3'] = vector<string>(three,three+3);
        letter['4'] = vector<string>(four,four+3);
        letter['5'] = vector<string>(five,five+3);
        letter['6'] = vector<string>(six,six+3);
        letter['7'] = vector<string>(seven,seven+4);
        letter['8'] = vector<string>(eight,eight+3);
        letter['9'] = vector<string>(nine,nine+4);

        combination[digits.substr(0,1)] = letter[digits[0]];

        for(int i=1;i<digits.size();i++){
            char c = digits[i];
            vector<string> currentChars= letter[c];
            vector<string> lastCombination = combination[digits.substr(0,i)];
            vector<string> newCombination;
            for(int x=0;x<lastCombination.size();x++){
                string current = lastCombination[x];
                for(int y=0;y<currentChars.size();y++){
                    newCombination.push_back(current + currentChars[y]);
                }
            }
            combination[digits.substr(0,i+1)] = newCombination;
        }

        return combination[digits];
    }
};

int main(){
    Solution s;
    vector<string> r = s.letterCombinations("23");
    for(int i=0;i<r.size();i++){
        cout << r[i] << endl;
    }
    return 0;
}