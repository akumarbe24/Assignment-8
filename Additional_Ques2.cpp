#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val; TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

vector<vector<vector<TreeNode*>>> dp;

vector<TreeNode*> build(int lo, int hi){
    if(lo > hi) return {nullptr};
    auto &memo = dp[lo][hi];
    if(!memo.empty()) return memo;

    for(int i = lo; i <= hi; ++i){
        auto L = build(lo, i-1);
        auto R = build(i+1, hi);
        for(auto l : L)
            for(auto r : R){
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                memo.push_back(root);
            }
    }
    return memo;
}

vector<TreeNode*> generateTrees(int n){
    if(n == 0) return {};
    dp.assign(n+2, vector<vector<TreeNode*>>(n+2));
    return build(1, n);
}

void printPre(TreeNode* t){
    if(!t){ cout << "null "; return; }
    cout << t->val << " ";
    printPre(t->left);
    printPre(t->right);
}

int main(){
    int n = 3;
    auto trees = generateTrees(n);
    for(auto t : trees){ printPre(t); cout << "\n"; }
}
