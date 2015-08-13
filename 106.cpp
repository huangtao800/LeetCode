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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeSub(inorder, inorder.begin(), inorder.end(), postorder, postorder.begin(), postorder.end());
    }
    
    TreeNode* buildTreeSub(vector<int>& inorder, vector<int>::iterator inStart, vector<int>::iterator inEnd,
        vector<int>& postorder, vector<int>::iterator postStart, vector<int>::iterator postEnd){
        if(postStart==postEnd) return NULL;
        int rootNumber = *(postEnd-1);
        TreeNode *root = new TreeNode(rootNumber);
        
        vector<int>::iterator itr = find(inStart, inEnd, rootNumber);
        int leftTreeSize = itr - inStart;
        root->left = buildTreeSub(inorder, inStart, itr, postorder, postStart, postStart+leftTreeSize);
        root->right = buildTreeSub(inorder, itr+1, inEnd, postorder, postStart+leftTreeSize, postEnd-1);
        return root;
    }
};

int main(){
    int arr[] = {1, 2, 3};
    vector<int> pre(1, 1);
    vector<int> in(1, 1);
    Solution s;
    TreeNode *result = s.buildTree(pre, in);
    return 0;
}