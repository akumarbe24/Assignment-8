#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& a, int n, int i) {
    int l = 2*i + 1, r = 2*i + 2, m = i;
    if (l < n && a[l] > a[m]) m = l;
    if (r < n && a[r] > a[m]) m = r;
    if (m != i) { 
        swap(a[i], a[m]); heapify(a, n, m); 
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) heapify(a, n, i);   
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);                                 
        heapify(a, end, 0);                                 
    }
}


int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    heapSort(a);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i+1<n?' ':'\n');
    }
    return 0;
}