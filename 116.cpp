/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)  return;
        
        TreeLinkNode *lineHead = root;
        TreeLinkNode *current = root;
        root->next = NULL;
        
        while(current!=NULL && lineHead->left!=NULL){
            if(current->next==NULL){
                current->left->next = current->right;
                current->right->next = NULL;
                current = lineHead->left;
                lineHead = current;
                continue;
            }
            current->left->next = current->right;
            current->right->next = current->next->left;
            current = current->next;
        }
    }
};