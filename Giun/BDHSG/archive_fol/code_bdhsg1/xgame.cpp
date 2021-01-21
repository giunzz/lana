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

cll maxn = 507;
ll n, m, dp[maxn][maxn * 6] = {{0}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n >> m;
    lp(i, 1, 6) dp[1][i] = 1;
    lp(i, 1, n)
        lp(j, i, i * 6)
            lp(x, 1, 6) dp[i + 1][j + x] += dp[i][j];
    cout << dp[n][m];
}