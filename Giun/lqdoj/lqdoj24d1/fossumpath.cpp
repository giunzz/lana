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

cll mxn = 1e5 + 4, MOD = 1e9 + 7;
ll n, m, cost[mxn], d[mxn] = {0}, t = 0;
pp(ll, ll) dp[mxn];
vec(ll) g[mxn];
bool ok = 1, root[mxn] = {0};

void sol(ll u){
    if(dp[u].second) return;
    for(ll v : g[u]){
        if(d[v] == t && !dp[v].second) ok = 0;
        if(d[v] == t) continue;
        d[v] = t;
        sol(v);
    }
    dp[u] = {cost[u], 1};
    for(ll v : g[u]){
        (dp[u].first += dp[v].first + dp[v].second * cost[u]) %= MOD;
        (dp[u].second += dp[v].second) %= MOD;
    }
}

// void dfs(ll u){

// }

// void check(){

// }

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) cin >> cost[i];
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        if(u == v){
            cout << "-1";
            return 0;
        }
        root[v] = 1;
    }
    // if(check()){
    //     cout << "-1";
    //     return 0;
    // }
    ll ans = 0;
    lp(i, 1, n){
        ++t;
        d[i] = t;
        sol(i);
        // cerr << dp[i].first << ' ' << dp[i].second << '\n';
        (ans += dp[i].first) %= MOD;
    }
    if(ok) cout << ans;
    else cout << "-1";
}