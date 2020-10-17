#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "maxtree"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5e4 + 7;
vec(pp(ll, ll)) g[maxn];
ll n, d[maxn] = {0}, ans = LLONG_MIN;
bool ck[maxn] = {0};

void init(){
    ll u, v, c;
    lp(i, 1, n - 1){
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }
    // lp(i, 1, n) du[i] = i;
}

// ll gt(ll u){
//     if(du[u] != u) return du[u] = gt(du[u]);
//     return u;
// }

// void uni(ll u, ll v){
//     u = gt(u); v = gt(v);
//     if(u == v) return;

// }

void dfs(ll u){
    // cerr << u << ' ';
    for(pp(ll, ll) v : g[u]){
        if(ck[v.second]) continue;
        ck[v.second] = 1;
        dfs(v.second);
        if(v.first + d[v.second] > 0) d[u] += v.first + d[v.second];
    }
    ans = max(ans, d[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    init();
    // ll ans = LLONG_MIN;
    ck[1] = 1;
    dfs(1);
    cout << ans;
}