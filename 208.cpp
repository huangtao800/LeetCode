#include <string>
#include <iostream>
#include <vector>

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