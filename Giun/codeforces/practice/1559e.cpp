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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 53, mxm = 1e5 + 3, MOD = 998244353;
ll n, m, mo[mxm] = {0}, nm, dp[2][mxm];
pp(ll, ll) a[mxn], b[mxn];

ll sol(ll r){
    lp(i, 1, n) b[i] = {(a[i].first + r - 1) / r, a[i].second / r};
    lp(i, 1, n) if(b[i].first > b[i].second) return 0;
    nm = m / r;
    // lp(i, 1, n) cerr << b[i].first << ' ' << b[i].second << '\n';
    lp(i, 0, 1) lp(j, 0, nm) dp[i][j] = 0;
    dp[0][0] = 1;
    lp(i, 1, n){
        lp(j, 1, nm){
            (dp[i & 1][j] = dp[i & 1][j - 1]) %= MOD;
            if(j - b[i].first >= 0) 
                (dp[i & 1][j] += dp[~i & 1][j - b[i].first]) %= MOD;
            if(j - b[i].second - 1 >= 0)
                (dp[i & 1][j] -= dp[~i & 1][j - b[i].second - 1]) %= MOD;
            // cerr << dp[i & 1][j] << ' ';
        }
        // cerr << '\n';
        dp[0][0] = 0;
    }
    ll res = 0;
    lp(i, 0, nm) (res += dp[n & 1][i]) %= MOD;
    return res;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    mo[1] = 1;
    lp(i, 1, 1e5) for(ll j = i * 2; j <= 1e5; j += i) mo[j] -= mo[i];
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i].first >> a[i].second;
    ll ans = sol(1);
    lp(i, 2, m){
        (ans += mo[i] * sol(i)) %= MOD;
    }
    // cerr << sol(2);
    cout << (ans + MOD) % MOD;
}   