#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "substr"
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
    dp[0][0] = dp[1][0] = 1;
    lp(i, 1, n) lp(j, 1, k){
        (dp[i & 1][j] = dp[~i & 1][j] - (j - i >= 0 ? dp[~i & 1][j - i] : 0) + dp[i & 1][j - 1] + MOD) %= MOD;
    }
    cout << dp[n & 1][k];
}