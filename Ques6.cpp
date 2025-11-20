#include <bits/stdc++.h>
using namespace std;

struct MaxHeap {
    vector<int> a;
    MaxHeap() {}
    int size(){ return a.size(); }
    bool empty(){ return a.empty(); }
    int top(){ return a.front(); }
    void push(int v){
        a.push_back(v);
        int i = a.size()-1;
        while(i>0){
            int p = (i-1)/2;
            if(a[p] < a[i]) swap(a[p], a[i]);
            else break;
            i = p;
        }
    }
    void pop(){
        if(a.empty()) return;
        a[0] = a.back();
        a.pop_back();
        int n = a.size();
        int i = 0;
        while(true){
            int l = 2*i+1, r = 2*i+2, largest = i;
            if(l < n && a[l] > a[largest]) largest = l;
            if(r < n && a[r] > a[largest]) largest = r;
            if(largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }
};

int main(){
    MaxHeap pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(3);
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }
    cout<<"\n";
    return 0;
}
