#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

bool isBSTUtil(TreeNode* root, long long low, long long high){
    if(!root) return true;
    if(root->val <= low || root->val >= high) return false;
    return isBSTUtil(root->left, low, root->val)
        && isBSTUtil(root->right, root->val, high);
}

bool isBST(TreeNode* root){
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    cout << (isBST(root) ? "BST" : "Not BST");
}
