#include <bits/stdc++.h>
using namespace std;
int t, n, k1, k2, m1 = 0, m2 = 0;

void enter(){
    int num;
    for (int i = 1; i <= k1; i++) cin >> num, m1 = max(m1, num);
    for (int i = 1; i <= k2; i++) cin >> num, m2 = max(m2, num);
    if (m1 > m2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("cardgame.inp", "r", stdin);
    //freopen("cardgame.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n >> k1 >> k2;
        enter();
        m1 = 0, m2 = 0;
    }
}