#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 7, maxm = 2e3 + 7, maxa = 2e3 + 7;
int a[maxn], b[maxm], dp[maxm][maxa] = {{0}}, n, m, t, c[maxa] = {0};

void  enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
        ++c[b[i]];
    }
}

void sol(){
    for (int i = 1; i <= )
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("spc1.inp", "r", stdin);
    freopen("spc1.2.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        enter();
        sol();
    }
}