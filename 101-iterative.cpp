/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //if a tree is symmetric tree then all elements in one level will be palindrome
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> nodeQueue;
        vector<TreeNode*> nextLevel;
        vector<TreeNode*> nodeList;
        nodeQueue.push_back(root);
        while(!nodeQueue.empty()){
            for(int i=0;i<nodeQueue.size();i++){
                nodeList.push_back(nodeQueue[i]);
                if(nodeQueue[i]!=NULL){
                    nextLevel.push_back(nodeQueue[i]->left);
                    nextLevel.push_back(nodeQueue[i]->right);
                }
            }
            if(isPalindrome(nodeList)){
                nodeList.clear();
                nodeQueue = nextLevel;
                nextLevel.clear();
            }else{
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(vector<TreeNode*> nodeList){
        if(nodeList.size()==0)  return true;
        int start = 0;
        int end = nodeList.size()-1;
        while(start<end){
            if(!isEqual(nodeList[start], nodeList[end]))    return false;
            start++;
            end--;
        }
        return true;
    }
    
    bool isEqual(TreeNode* t1, TreeNode *t2){
        if(t1==NULL && t2==NULL)    return true;
        if(t1==NULL || t2==NULL)    return false;
        return t1->val == t2->val;
    }
};