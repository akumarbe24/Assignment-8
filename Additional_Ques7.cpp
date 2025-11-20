#include <bits/stdc++.h>
using namespace std;

struct Node{
int val;
Node*left;
Node*right;
Node(int x):val(x),left(NULL),right(NULL){}
};

void inorder(Node*root,vector<int>&v){
if(!root)return;
inorder(root->left,v);
v.push_back(root->val);
inorder(root->right,v);
}

Node*makeDLL(vector<int>&v){
Node*head=NULL,*prev=NULL;
for(int x:v){
Node*temp=new Node(x);
if(!head)head=temp;
temp->left=prev;
if(prev)prev->right=temp;
prev=temp;
}
return head;
}

Node*mergeBST(Node*a,Node*b){
vector<int>v1,v2,v3;
inorder(a,v1);
inorder(b,v2);
merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
return makeDLL(v3);
}

int main(){
Node*a=new Node(3);
a->left=new Node(1);
a->right=new Node(5);

Node*b=new Node(4);
b->left=new Node(2);
b->right=new Node(6);

Node*h=mergeBST(a,b);
while(h){
cout<<h->val<<" ";
h=h->right;
}
}
