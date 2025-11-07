#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

int sumLeft(TreeNode* root, bool isLeft){
    if(!root) return 0;
    if(!root->left && !root->right && isLeft) return root->val;
    return sumLeft(root->left, true) + sumLeft(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root){
    return sumLeft(root, false);
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sumOfLeftLeaves(root);
}
