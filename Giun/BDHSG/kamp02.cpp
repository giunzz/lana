#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "kamp02"
#pragma GCC optimize("Ofast")
using namespace std;

void OF(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

ll n, k, q;
vec(vec(pp(ll, ll))) g;
vec(ll) tt, res;
vec(bool) d, x;

#define cost first 
#define p second

void init(){
    g.resize(n + 1); tt.resize(n + 1, 0); d.resize(n + 1); x.resize(n + 1, 0); res.resize(n + 1);
    // tt[1] = -1;
    ll u, v, c;
    lp(i, 1, n - 1){
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }
    lp(i, 1, k){
        cin >> u;
        d[u] = 1;
        q = u;
    }
}   

inline bool dfs(ll u){
    bool ok = 0;
    for(pp(ll, ll) v : g[u]){
        if(x[v.p]) continue;
        x[v.p] = 1;
        if(dfs(v.p)) tt[v.p] = u, ok = 1;
        else tt[v.p] = 0;
    }
    if(d[u]) return 1;
    return ok;
}

inline void dfs1(ll u){
    for(pp(ll, ll) v : g[u]){
        if(x[v.p]) continue;
        x[v.p] = 1;
        if(!tt[v.p]) res[v.p] = res[u] + v.cost;
        dfs1(v.p); 
    }
}

int main(){
    OF();
    cin >> n >> k;
    init();
    tt[q] = -1;
    x[q] = 1;
    dfs(q);
    // dp();
    fill(x.begin(), x.end(), 0);
    x[q] = 1;
    dfs1(q);
    // lp(i, 1, n) cerr << i << ' ' << tt[i] << '\n';
    lp(i, 1, n) cout << res[i] << '\n';
}