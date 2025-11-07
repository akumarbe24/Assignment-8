#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) {
        data = v;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int x) {
    if (!root) return new TreeNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

TreeNode* minNode(TreeNode* root){
    while(root && root->left) root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int x){
    if(!root) return NULL;
    if(x < root->data) root->left = deleteNode(root->left, x);
    else if(x > root->data) root->right = deleteNode(root->right, x);
    else{
        if(!root->left && !root->right){ delete root; return NULL; }
        if(!root->left){ TreeNode* r = root->right; delete root; return r; }
        if(!root->right){ TreeNode* l = root->left; delete root; return l; }
        TreeNode* s = minNode(root->right);
        root->data = s->data;
        root->right = deleteNode(root->right, s->data);
    }
    return root;
}

int maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(TreeNode* root){
    if(!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    if(!root->left || !root->right) return 1 + L + R;
    return 1 + min(L, R);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 4);

    inorder(root);
    cout << "\n";

    root = deleteNode(root, 3);

    inorder(root);
    cout << "\n";

    cout << maxDepth(root) << "\n";
    cout << minDepth(root) << "\n";

    return 0;
}
