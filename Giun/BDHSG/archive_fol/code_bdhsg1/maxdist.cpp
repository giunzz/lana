#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
// #define Fname "f"
#define Fname "maxdist"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, k, res[maxn] = {0}, dsu[maxn], cnt[maxn] = {0}, a;
bool d[maxn] = {0}, dd[maxn] = {0};
vec(pp(ll, ll)) g[maxn];
vec(pp(ll, pp(ll, ll))) e;

ll Get(ll u){
    if(dsu[u] == u) return u;
    return dsu[u] = Get(dsu[u]);
}

bool Join(pp(ll, pp(ll, ll)) E){
    ll u = Get(E.second.first), v = Get(E.second.second);
    if(u == v) return 0;
    if(cnt[u] > cnt[v]) swap(u, v);
    cnt[u] += cnt[v], dsu[v] = u;
    return 1;
}

ll dfs(ll u){
    ll tmp = 0;
    for(auto &v : g[u]){
        if(dd[v.second]) continue;
        dd[v.second] = 1;
        ll tt = dfs(v.second);
        if(tt > 0 || d[v.second]) tmp = max(tmp, max(v.first, tt));
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> k;
    lp(i, 1, k){
        ll tmp;
        cin >> tmp;
        a = tmp;
        d[tmp] = 1;
    }
    lp(i, 1, n) dsu[i] = i, cnt[i] = 1;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        e.push_back({c, {u, v}});
    }
    sort(e.begin(), e.end());
    ll c = 0;
    for(pp(ll, pp(ll, ll)) ee : e) if(Join(ee)){
        g[ee.second.first].push_back({ee.first, ee.second.second});
        g[ee.second.second].push_back({ee.first, ee.second.first});
        if(++c == n - 1) break;
    }
    dd[a] = 1;
    ll res = dfs(a);
    lp(i, 1, k) cout << res << ' '; 
}