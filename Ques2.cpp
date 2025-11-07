#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v){
            data = v;
            left = right = NULL;
        }
};

static int idx = -1;
TreeNode* buildTree(vector<int> nodes){
    idx++;
    if (idx >= (int)nodes.size() || nodes[idx] == -1) return NULL;
    TreeNode* curr_node = new TreeNode(nodes[idx]);
    curr_node->left = buildTree(nodes);
    curr_node->right = buildTree(nodes);
    return curr_node;
}

bool search_el(TreeNode* root, int key){
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key > root->data) return search_el(root->right, key);
    return search_el(root->left, key);
}

bool search_el_iter(TreeNode* root, int key) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->data == key) return true;
        if (key > cur->data) cur = cur->right;
        else cur = cur->left;
    }
    return false;
}

TreeNode* minNode(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

TreeNode* maxNode(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* cur = root;
    while (cur->right) cur = cur->right;
    return cur;
}

TreeNode* findNode(TreeNode* root, int key) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        if (key > cur->data) cur = cur->right;
        else cur = cur->left;
    }
    return nullptr;
}

TreeNode* inorderSuccessor(TreeNode* root, int key) {
    TreeNode* target = findNode(root, key);
    if (!target) return nullptr;
    if (target->right) return minNode(target->right);
    TreeNode* succ = nullptr;
    TreeNode* cur = root;
    while (cur) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

TreeNode* inorderPredecessor(TreeNode* root, int key) {
    TreeNode* target = findNode(root, key);
    if (!target) return nullptr;
    if (target->left) return maxNode(target->left);
    TreeNode* pred = nullptr;
    TreeNode* cur = root;
    while (cur) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

int main() {
    vector<int> nodes = {20, 10, 5, -1, -1, 15, -1, -1, 30, 25, -1, -1, 35, -1, -1};
    idx = -1;
    TreeNode* root = buildTree(nodes);
    cout << boolalpha;
    cout << "search_el(15): " << search_el(root, 15) << '\n';
    cout << "search_el_iter(17): " << search_el_iter(root, 17) << '\n';
    cout << "min: " << minNode(root)->data << '\n';
    cout << "max: " << maxNode(root)->data << '\n';
    int key = 25;
    TreeNode* succ = inorderSuccessor(root, key);
    TreeNode* pred = inorderPredecessor(root, key);
    cout << "key = " << key << '\n';
    cout << "successor: " << (succ ? succ->data : -1) << '\n';
    cout << "predecessor: " << (pred ? pred->data : -1) << '\n';
    return 0;
}
