#include <bits/stdc++.h>
using namespace std;
int t, n, a[(int)2e5 + 7];//, mi = 1e9 + 1, ma = -1, vi, va;

void sol(){
    cin >> a[1];
    for (int i = 2; i <= n; i++){
        cin >> a[i];
        /*if (a[i] < mi){
            mi = a[i], vi = i;
        }
        if (a[i] > ma){
            ma = a[i], va = i;
        }
        //cerr << vi << " " << va  << " " << a[vi] << " " << a[va]<< endl;
        if (ma - mi >= va - vi + 1){ 
            cout << "YES\n";
            if (vi < va) cout << vi << " " << va << endl;
            else cout << va << " " << vi << endl;
            return;
        }*/
        if (abs(a[i] - a[i - 1]) >= 2){
            cout << "YES\n" << i - 1 << " " << i << endl;
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("subarray.inp", "r", stdin);
    //freopen("subarray.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        sol();
        //mi = 1e9 + 1, ma = -1, vi = 0, va = 0;
    }
}