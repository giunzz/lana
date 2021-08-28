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

cll mxn = 203, mxk = 2e3 + 7, MOD = 1e9 + 7;
ll n, tot, a[mxn], dp[2][mxn][mxk] = {{{0}}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> tot;
    lp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    dp[0][0][0] = 1;
    lp(i, 1, n) lp(j, 0, n) lp(k, 0, tot){
        ll &cur = dp[i & 1][j][k];
        cur = 0;
        if(k - j * (a[i] - a[i - 1]) >= 0) 
            (cur += dp[~i & 1][j][k - j * (a[i] - a[i - 1])] * (j + 1)) %= MOD;
        if(j - 1 >= 0 && k - (j - 1) * (a[i] - a[i - 1]) >= 0)
            (cur += dp[~i & 1][j - 1][k - (j - 1) * (a[i] - a[i - 1])]) %= MOD;
        if(j + 1 <= n && k - (j + 1) * (a[i] - a[i - 1]) >= 0)
            (cur += dp[~i & 1][j + 1][k - (j + 1) * (a[i] - a[i - 1])] * (j + 1)) %= MOD;
        // cerr << i << ' ' << j << ' ' << k << ' ' << cur << '\n';
    }
    ll ans = 0;
    lp(i, 0, tot) (ans += dp[n & 1][0][i]) %= MOD;
    cout << ans;
}