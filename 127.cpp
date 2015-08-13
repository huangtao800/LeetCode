#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord==endWord)  return 1;
        
        unordered_map<string, int> color;
        
        int level = 1;
        list<string> currentLevel;
        list<string> nextLevel;
        currentLevel.push_back(beginWord);
        color[beginWord] = 1;

        while(!currentLevel.empty()){
            string current = currentLevel.front();    currentLevel.pop_front();
            for(int i=0;i<current.size();i++){
                for(char c='a';c<='z';c++){
                    if(current[i]==c)   continue;
                    string newWord = current;
                    newWord[i] = c;
                    if(newWord==endWord)    return level+1;

                    if(wordDict.count(newWord) && !color[newWord]){
                        nextLevel.push_back(newWord);
                        color[newWord] = 1;
                    }
                }
            }
            if(currentLevel.empty()){
                currentLevel = nextLevel;
                nextLevel.clear();
                level++;
            }
        }

        return 0;
    }

};

int main(){
    string list[]={"hot","cog","dot","dog","hit","lot","log"};
    unordered_set<string> wordDict(list, list+7);


    Solution s;
    cout << s.ladderLength("hit","cog",wordDict) << endl;
}