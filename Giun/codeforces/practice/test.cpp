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

cll MOD = 998244353, mxn = 20;
ll n, m, a[mxn][mxn], sum = 0, ans = 0;

ll Pow(ll u, ll v){
    if(!v) return 1;
    ll tmp = Pow(u, v >> 1);
    (tmp *= tmp) %= MOD;
    if(v & 1) return (tmp * u) % MOD;
    return tmp;
}

void sol(ll u, ll v, ll val, ll p){
    bool ok = 1;
    ll cnt = 0;
    lp(i, 1, n) lp(j, 1, m) if(a[i][j] < a[u][v]) ++cnt;
    lp(i, 1, n) lp(j, 1, m){
        if(a[i][j] < a[u][v]){
            ok = 0;
            sol(i, j, val + (u - i) * (u - i) + (v - j) * (v - j), p * cnt);
        }
    }
    if(ok){
        (ans += val * Pow(p, MOD - 2)) %= MOD;
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m) cin >> a[i][j];
    ll r, c;
    cin >> r >> c;
    sol(r, c, 0, 1);
    cout << ans % MOD;
}