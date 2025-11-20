#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(nullptr),right(nullptr){}
};

vector<int> rightView(Node* root){
    vector<int> res;
    if(!root) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* t=q.front(); q.pop();
            if(i==n-1) res.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    return res;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->right->right=new Node(4);
    vector<int> ans=rightView(root);
    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
