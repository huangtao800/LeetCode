#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():val(0),endHere(false) {
        next = new TrieNode*[26]();
    }
    
    TrieNode(char c):val(c),endHere(false){
        next = new TrieNode*[26]();
    }

    char val;
    
    TrieNode** next;
    bool endHere;   // there exists a word ends here
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(word.size()==0)  return;
        int firstDiffPos = 0;
        TrieNode* lastCommon = findLastCommon(word, firstDiffPos);
        string toInsert = word.substr(firstDiffPos);
        insertString(lastCommon, toInsert);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int firstDiffPos = 0;
        TrieNode *lastCommon = findLastCommon(word, firstDiffPos);
        return lastCommon->endHere && firstDiffPos==word.size();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int firstDiffPos = 0;
        findLastCommon(prefix, firstDiffPos);
        return firstDiffPos == prefix.size();
    }

private:
    TrieNode* root;

    TrieNode* findLastCommon(string word, int &firstDiffPos){
        if(word.size()==0)  return root;
        TrieNode* current = root;
        TrieNode** currentNext = current->next;
        while(firstDiffPos<word.size() && currentNext[word[firstDiffPos]-'a']!=NULL){
            current = currentNext[word[firstDiffPos]-'a'];
            firstDiffPos++;
            currentNext = current->next;
        }
        return current;
    }

    void insertString(TrieNode* start, string word){
        TrieNode *current = start;
        for(int i=0;i<word.size();i++){
            TrieNode* newNode = new TrieNode(word[i]);
            TrieNode** currentNext = current->next;
            currentNext[word[i]-'a'] = newNode;
            current = newNode;
        }
        current->endHere = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        if(board.empty() || board[0].empty())   return vector<string>();
        int row = board.size(), col = board[0].size();
        Trie t;
        for(int i=0;i<words.size();i++){
            t.insert(words[i]);
        }

        unordered_set<string> unique_result;
        vector<vector<bool> > flag(row, vector<bool>(col, true));
        string already = "";
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                findWordsSub(board, flag, unique_result, t, already, i, j);
            }
        }

        vector<string> result(unique_result.begin(), unique_result.end());
        return result;
    }

    void findWordsSub(vector<vector<char> >& board, vector<vector<bool> >& flag, unordered_set<string>& result, Trie& t, string already, int row, int col){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return;
        if(!flag[row][col]) return;

        string newString = already+board[row][col];
        if(t.startsWith(newString)){
            if(t.search(newString)) result.insert(newString);
            flag[row][col] = false;
            findWordsSub(board, flag, result, t, newString, row+1, col);
            findWordsSub(board, flag, result, t, newString, row-1, col);
            findWordsSub(board, flag, result, t, newString, row, col+1);
            findWordsSub(board, flag, result, t, newString, row, col-1);
            flag[row][col] = true;
        }
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
    Trie t;
    t.insert("a");
    cout<<t.search("a")<<endl;
    cout<<t.startsWith("a")<<endl;
    return 0;
}