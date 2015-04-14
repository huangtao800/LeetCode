#include <stack>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *current = root;
        while(current!=NULL){
            s.push(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = s.top();
        int result = top->val;
        s.pop();
        
        TreeNode *rightSub = top->right;
        while(rightSub!=NULL){
            s.push(rightSub);
            rightSub = rightSub->left;
        }
        return result;
    }
};

int main(){
    TreeNode a1(1);
    TreeNode a2(3);
    TreeNode a3(6);

    a1.right = &a2;
    a2.right = &a3;

    BSTIterator i = BSTIterator(&a1);
    while (i.hasNext()) cout << i.next() << " ";
    cout << endl;
    return 0;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */