#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)  return;
        
        TreeLinkNode *nextLineHead = NULL;
        TreeLinkNode *nextNullNode = NULL;  // record node whose next is NULL
        TreeLinkNode *current = root;
        root->next = NULL;
        bool isNextLineHeadNull = true, hasNextNull = false;
        
        while(current!=NULL){
            if(current->left){
                if(isNextLineHeadNull){
                    nextLineHead = current->left;
                    isNextLineHeadNull = false;
                }
                
                if(!isNextLineHeadNull && hasNextNull){
                    nextNullNode->next = current->left;
                    hasNextNull = false;
                }
                
                current->left->next = current->right;
                if(current->right == NULL){
                    hasNextNull = true;
                    nextNullNode = current->left;
                }                    
                
            }
            
            if(current->right){
                if(isNextLineHeadNull){
                    nextLineHead = current->right;
                    isNextLineHeadNull = false;
                }
                if(!isNextLineHeadNull && hasNextNull){
                    nextNullNode->next = current->right;
                    hasNextNull = false;
                }
                
                if(current->next){
                    current->right->next = current->next->left;
                    if(current->next->left==NULL){
                        nextNullNode = current->right;
                        hasNextNull = true;
                    }
                }else{
                    current->right->next = NULL;
                }
            }
            if(current->next==NULL){
                if(nextLineHead==NULL)  break;
                current = nextLineHead;
                nextLineHead = NULL;
                isNextLineHeadNull = true;
                hasNextNull = false;
                nextNullNode = NULL;
            }else{
                current = current->next;
            }
            
        }
    }
    
};

int main(){
    return 0;
}