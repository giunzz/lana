#include <bits/stdc++.h>

using namespace std;
int n, r[110], b[110];

void sol(){
    int mi = 2147483647;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) mi = min(mi, r[i] xor b[i]);
    cout << mi << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cardgame.inp", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int t; 
    cin >> t;
    for (int i = 1; i <= t; i++){
        sol();
    }
}