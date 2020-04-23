#include <bits/stdc++.h>
using namespace std;
const int maxa = 2e5 + 7, maxb = 2e3 + 7;
int t, a[maxa], b[maxb], dp[maxa][maxb] = {{0}}, n, m;

void enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
}

void sol(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i] != b[j]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else if (a[i] == b[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n][m] << endl;;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("spc1.inp", "r", stdin);
    freopen("spc1.out", "w", stdout);
    cin >> t;
    for (int i = 1; i<= t; i++){
        enter();
        sol();
    }
    cerr << clock() << " ms";
}
