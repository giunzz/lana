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

cll mx = 103, mxa = 3e4 + 7, MOD = 1e9;
ll m, n, dp[mx][mx], a[mx][mx];

inline ll sol(ll x, ll y){
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    if(y == 1) ++dp[x][y];
    lp(i, 1, x) lp(j, 1, y) if(j < n && i + j < x + y && __gcd(a[i][j], a[x][y]) != 1) 
        (dp[x][y] += sol(i, j)) %= MOD;  
    return dp[x][y];
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> m >> n;
    lp(i, 1, m) lp(j, 1, n) cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    dp[1][1] = 1;
    ll ans = 0;
    lp(i, 1, m) (ans += sol(i, n)) %= MOD;
    cout << ans;
}