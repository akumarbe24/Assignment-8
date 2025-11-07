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

static int idx=-1;
TreeNode* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    TreeNode* curr_node = new TreeNode(nodes[idx]);
    curr_node->left = buildTree(nodes);
    curr_node->right = buildTree(nodes);
    return curr_node;

}

vector<int> preorder(TreeNode* root){
    vector<int> ans;
    if (root == NULL) return ans;
    ans.push_back(root->data);
    vector<int> left = preorder(root->left);
    vector<int> right = preorder(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

vector<int> inorder(TreeNode* root){
    vector<int> ans;
    if (root == NULL) return ans;
    vector<int> left = inorder(root->left);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.push_back(root->data);
    vector<int> right = inorder(root->right);
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

vector<int> postorder(TreeNode* root){
    vector<int> ans;
    if (root == NULL) return ans;
    vector<int> left = postorder(root->left);
    vector<int> right = postorder(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    ans.push_back(root->data);
    return ans;
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    idx = -1; 
    TreeNode* root = buildTree(nodes);
    vector<int> in = inorder(root);
    for (int v : in) cout << v << " ";
    cout << endl;
    vector<int> pre = preorder(root);
    for (int v : pre) cout << v << " ";
    cout << endl;
    vector<int> post = postorder(root);
    for (int v : post) cout << v << " ";
    cout << endl;
    return 0;
}
