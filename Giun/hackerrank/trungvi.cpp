#include <bits/stdc++.h>
using namespace std;
int n, a[(int)1e7 + 7], k;

int qselect(int l, int h){
    swap(a[(l + h / 2)], a[h]);
    int pi = a[h], i = l; 
    for (int j = l; j <= h - 1; j++) 
    { 
        if (a[j] <= pi) 
        { 
            swap(a[i], a[j]); 
            i++; 
        } 
    } 
    swap(a[i], a[h]); 
    return i; 
}

int sol(int l, int r, int k){
    if (k > 0 && k <= r - l + 1){
        int pi = qselect(l , r);
        //for (int i = 1; i <= n; i++) cerr << a[i] << " ";
        //cerr << endl;
        if (pi - l == k - 1) return a[pi];
        if (pi - l > k - 1) return sol(l, pi - 1, k);
        return sol(pi + 1, r, l - pi - 1 + k); //tinh tien k neu vi tri pi+1 -> l
    }
    return 0; //return cho vui
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    k = n / 2 + 1;
    cout << sol(1, n, k);
}