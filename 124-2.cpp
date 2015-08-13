/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfsMax(root, maxPath);
        return maxPath;
    }
    
    // return the max path starts from root and ends in one of its substree or itself.
    int dfsMax(TreeNode* root, int& maxPath){
        if(root==NULL)  return 0;
        int l = max(0, dfsMax(root->left, maxPath));
        int r = max(0, dfsMax(root->right, maxPath));
        maxPath = max(maxPath, l+root->val+r);
        
        return  root->val + max(l, r);
    }
};