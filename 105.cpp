#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeSub(preorder, preorder.begin(), preorder.end(), inorder, inorder.begin(), inorder.end());
    }
    
    TreeNode* buildTreeSub(vector<int>& preorder, vector<int>::iterator preStart, vector<int>::iterator preEnd,
        vector<int>& inorder, vector<int>::iterator inStart, vector<int>::iterator inEnd){
            if(preStart==preEnd)    return NULL;    // preorder empty
            int root = *preStart;
            TreeNode *result = new TreeNode(root);
            vector<int>::iterator itr = find(inStart, inEnd, root);
            
            int leftTreeSize = itr - inStart;
            result->left = buildTreeSub(preorder, preStart+1, preStart+leftTreeSize+1, inorder, inStart, itr);
            result->right = buildTreeSub(preorder, preStart+leftTreeSize+1, preEnd, inorder, itr+1, inEnd);
            return result;
        }
};

int main(){
    int arr[] = {1, 2, 3};
    vector<int> pre(arr, arr+3);
    vector<int> in(arr, arr+3);
    Solution s;
    TreeNode *result = s.buildTree(pre, in);
    return 0;
}