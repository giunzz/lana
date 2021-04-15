#include <bits/stdc++.h>
using namespace std;

const int mxn = 203, inf = -1e9;
int a[256], dp[4][mxn][mxn][mxn]; 
string s;

int cal_dp(int c, int n, int i, int j){
    if(i == j){
        if(n == 1) 
            return inf;
        return n * n;
    } 
    if(dp[c][n][i][j] != -1) 
        return dp[c][n][i][j];
    if(c == a[s[i]]){
        if(i == j - 1) 
            return (n + 1) * (n + 1);
        return dp[c][n][i][j] = cal_dp(c, n + 1, i + 1, j);
    } 
    int cur = inf;
    for(int k = i + 2; k <= j; ++k) 
        cur = max(cur, cal_dp(a[s[i]], 1, i + 1, k) + 
        cal_dp(c, n, k, j));
    return dp[c][n][i][j] = cur; 
}

void sol(){
    cin >> s;
    for(int i = 1; i <= s.size(); ++i)
        for(int j = 1; j <= s.size(); ++j)
            for(int n = 1; n <= s.size(); ++n)
                for(int k = 0; k <= 3; ++k)
                    dp[k][n][i][j] = -1; 
    cout << max(0, cal_dp(a[s[0]], 1, 1, s.size())) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("baloon.inp", "r", stdin);
    freopen("baloon.out", "w", stdout);
    a['R'] = 0, a['B'] = 1, a['G'] = 2, a['Y'] = 3;
    int cases;
    cin >> cases;
    while(cases--) sol();
}