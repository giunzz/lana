#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll MOD = 1e9 + 7, maxn = 2, maxk = 1e5 + 7;
ll n, k, dp[maxn][maxk] = {{0}};

// #define ONLINE_JUDGE
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    // lp(i, 1, n) dp[i][0] = 1;
    dp[0][0] = dp[1][0] = 1;
    lp(i, 1, n){
        cerr << i << '\t' << dp[i & 1][0] << ' ';
        // (dp[i & 1][0] += dp[~i & 1][0]) %= MOD;
        lp(j, 1, k){
            dp[i & 1][j] = 0;
            lp(z, max(0LL, j - i + 1), j) (dp[i & 1][j] += dp[(i - 1) & 1][z]) %= MOD;
            // dp[i & 1][j] = dp[i & 1][j - 1] + dp[~i & 1][j];
            // if(j - i >= 0) dp[i & 1][j] -= dp[~i & 1][j - i];
            // dp[i & 1][j] %= MOD;
            // if(j > i * (i - 1) / 2) dp[i & 1][j] = dp[i & 1][j - 1];
            // (dp[i & 1][j] = dp[~i & 1][j] - (j - i >= 0 ? dp[~i & 1][j - i] : 0) + dp[i & 1][j - 1]) %= MOD;
            cerr << dp[i & 1][j] << ' ';
        }
        cerr << '\n';
    }
    ll ans = dp[n & 1][k] - dp[n & 1][k - 1];
    // if(k - n >= 0) ans -= dp[n][k - n];
    // lp(i, 0, n){
    //     cerr << i << '\t'; 
    //     lp(j, 0, k) cerr << dp[i][j] << ' ';
    //     cerr << '\n';
    // }
    cout << dp[n & 1][k];
}