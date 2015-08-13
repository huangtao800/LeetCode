#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL)  return 0;
        unordered_map<TreeNode*, int> color;
        int maxPathSum = root->val;
        dfs(root, color, root->val, maxPathSum);
        return maxPathSum;
    }
    
    // return the max path sum from current node to one of its children
    int dfs(TreeNode* node, unordered_map<TreeNode*, int>& color, int maxTillCurrent, int& maxPathSum){
        color[node] = 1;
        int result = node->val;

        vector<TreeNode*> adjacentNodes;
        if(node->left)  adjacentNodes.push_back(node->left);
        if(node->right) adjacentNodes.push_back(node->right);
        
        
        for(int i=0;i<adjacentNodes.size();i++){
            if(adjacentNodes[i]==NULL)  continue;
            TreeNode* next = adjacentNodes[i];
            if(!color[next]){
                maxPathSum = max(maxPathSum, max(next->val, maxTillCurrent+next->val));
                int maxTillNext = max(maxTillCurrent+next->val, next->val);
                int nextResult = dfs(next, color, maxTillNext, maxPathSum);

                maxTillCurrent = max(maxTillCurrent, node->val+nextResult);
                result = max(result, node->val+nextResult);
            }
        }
        if(adjacentNodes.size()==1){    // Note if the binary tree is a straight line
            maxPathSum = max(maxPathSum, result);
        }
        
        return result;
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    t1.right = &t2;
    t2.right = &t3;
    t3.right = &t4;
    t4.right = &t5;

    Solution s;
    int result = s.maxPathSum(&t1);
    cout << result << endl;
    return 0;
}