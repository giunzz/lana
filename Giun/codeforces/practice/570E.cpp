#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 5e2 + 7, MOD = 1e9 + 7;
ll n, m, dp[maxn / 2][maxn][maxn];
char a[maxn][maxn];

bool check(ll x1, ll y1, ll x2, ll y2){
    return (a[x1][y1] == a[x2][y2]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m; 
    lp(i, 1, n) lp(j, 1, m) cin >> a[i][j];
    memset(dp, 0, sizeof(dp));
    dp[1][1][n] = (a[1][1] == a[n][m]);
    lp(i, 1, (m + n) / 2) lp(x1, 1, n) lpd(x2, n, 1){
        ll y1 = i + 1 - x1, y2 = m + n - x2 + 1 - i, cur = dp[i][x1][x2];
        if(y1 < 1 || y1 > m || y2 < 1 || y2 > m) continue;
        // dp[i + 1][x1 + 1][x2]
        if(check(x1 + 1, y1, x2 - 1, y2)) (dp[i + 1][x1 + 1][x2 - 1] += cur) %= MOD;
        if(check(x1, y1 + 1, x2 - 1, y2)) (dp[i + 1][x1][x2 - 1] += cur) %= MOD;
        if(check(x1 + 1, y1, x2, y2 - 1)) (dp[i + 1][x1 + 1][x2] += cur) %= MOD;
        if(check(x1, y1 + 1, x2, y2 - 1)) (dp[i + 1][x1][x2] += cur) %= MOD;
    }// m - y2 + n - x2 + 1 = sl
    ll sl = (n + m) / 2, ans = 0;
    if((n + m) & 1){
        lp(i, 1, n) (ans += dp[sl][i][i] + dp[sl][i][i + 1]) %= MOD;
    } else{
        lp(i, 1, n) (ans += dp[sl][i][i]) %= MOD;
    }
    cout << ans;
}