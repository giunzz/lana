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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 207;
ll n, m, par[mxn], size[mxn], far1, ans = 0, dis[mxn];
vec(pp(ll, pp(ll, ll))) edge;
vec(pp(ll, ll)) g[mxn];

ll _get(ll u){
    return par[u] == u ? u : _get(par[u]);
}

bool _join(ll u, ll v){
    u = _get(u), v = _get(v);
    if(u == v) return 0;
    if(size[u] < size[v]) swap(u, v);
    par[v] = u, size[u] += size[v];
    return 1;
}

void dfs(ll u, ll p){
    for(pp(ll, ll) v : g[u]){
        if(v.second == p) continue;
        dis[v.second] = dis[u] + v.first;
        dfs(v.second, u);
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end());
    lp(i, 1, n) par[i] = i, size[i] = 1;
    for(pp(ll, pp(ll, ll)) i : edge) if(_join(i.second.first, i.second.second)){
        g[i.second.first].push_back({i.first, i.second.second});
        g[i.second.second].push_back({i.first, i.second.first});
    }
    lp(i, 1, n) dis[i] = 0;
    dfs(1, -1);
    far1 = 1;
    lp(i, 1, n) if(dis[i] > dis[far1]) far1 = i;
    lp(i, 1, n) dis[i] = 0;
    dfs(far1, -1);
    lp(i, 1, n) ans = max(ans, dis[i]);
    // cout << ans / 2 << '.' << (ans & 1) * 5 << "0\n";
    cout << setprecision(2) << fixed << ans / 2.0 << '\n';
}