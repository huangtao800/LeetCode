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
        unordered_map<string, int> dist;
        dist[beginWord] = 1;
        queue<string> wordQue;
        wordQue.push(beginWord);

        while(!wordQue.empty()){
            string current = wordQue.front();   wordQue.pop();
            for(int i=0;i<current.size();i++){
                for(char c='a';c<='z';c++){
                    if(current[i]==c)   continue;
                    string newWord = current;
                    newWord[i] = c;
                    if(newWord == endWord)  return dist[current] + 1;

                    if(wordDict.count(newWord) && !dist.count(newWord)){
                        dist[newWord] = dist[current] + 1;
                        wordQue.push(newWord);
                    }
                }
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