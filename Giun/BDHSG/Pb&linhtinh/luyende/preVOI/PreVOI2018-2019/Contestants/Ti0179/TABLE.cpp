#include<bits/stdc++.h>
const int N = 305;
const int inf = 1e9;
using namespace std;

int n, m, k;
int dp[N][N][2], x[N][N];

void maximize(int& a, int b){
    if (a < b) a = b;
}

void minimize(int& a, int b){
    if (a > b) a = b;
}

void solve(int a, int b, int c, int d){
    for (int i = a; i <= c; i++){
        for (int j = b; j <= d; j++){
            if (i != a || j != b){
                dp[i][j][0] = -inf;
                if (i > a) maximize(dp[i][j][0], dp[i-1][j][0] + x[i][j]);
                if (j > b) maximize(dp[i][j][0], dp[i][j-1][0] + x[i][j]);
                int ans = inf, cur = -inf;
                if (i > a) maximize(cur, dp[i-1][j][1] + x[i][j]);
                if (j > b) maximize(cur, dp[i][j-1][1] + x[i][j]);
                minimize(ans, cur);
                if (i > a && (i-1 != a || j != b)) minimize(ans, dp[i-1][j][0] + x[i][j]);
                if (j > b && (i != a || j-1 != b)) minimize(ans, dp[i][j-1][0] + x[i][j]);
                dp[i][j][1] = ans;
            }
            else{
                dp[i][j][0] = x[i][j];
                dp[i][j][1] = inf;
            }
        }
    }
    printf("%d\n", dp[c][d][1]);
}

int main(){
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &x[i][j]);
    while (k--){
        int x, y, u, v;
        scanf("%d%d%d%d", &x, &y, &u, &v);
        solve(x, y, u, v);
    }
}
