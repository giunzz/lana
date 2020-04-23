#include <bits/stdc++.h>

using namespace std;
long long a, b, c, n, m, t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("xu.inp", "r", stdin);
    freopen("xu.out", "w", stdout);
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> a >> b >> c >> n;
        if ((a + b + c + n) % 3 == 0){
            t = (a + b + c + n) / 3;
            if (t < a || t < b || t < c) cout << "NO\n";
            else cout << "YES\n"; 
        }
        else cout << "NO\n";
    }
}