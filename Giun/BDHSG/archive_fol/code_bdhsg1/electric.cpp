#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "electric"
// #define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 4e3 + 7;
ll n, m, s = 0;
vec(pp(ll, ll)) g[maxn], t[maxn];
vec(pp(ll, pp(ll, ll))) edge;
vec(ll) dsu;
map<pp(ll, ll), ll> ed;

void init(){
    ll u, v, c;
    lp(i, 1, m){
        cin >> u >> v >> c;
        // g[u].push_back({c, v});
        // g[v].push_back({c, u});
        edge.push_back({c, {u, v}});
    }
}

#define cost first
#define fi second.first
#define se second.second

inline ll Get(ll u)
{
    if(dsu[u] < 0) return u;
    return Get(dsu[u]);
}

bool Merge(pp(ll, pp(ll, ll)) e)
{
    ll u, v;
    if((u = Get(e.fi)) == (v = Get(e.se))) return 0;
    if(dsu[u] > dsu[v]) swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    return 1;
}

void initT()
{
    ll cnt = 0;
    sort(edge.begin(), edge.end());
    for(auto &e : edge){
        if(Merge(e)){
            s += e.cost; 
            ed[{e.fi, e.se}] = e.cost;
            ed[{e.se, e.fi}] = e.cost;
            ++cnt;
            t[e.fi].push_back({e.cost, e.se});
            t[e.se].push_back({e.cost, e.fi});
        }
        if(cnt == n - 1) break;
    }
}

ll ck[maxn] = {0}, f[maxn][maxn] = {{0}};

void dfs(ll u, ll &r){
    for(auto &v : t[u]){
        if(ck[v.second]) continue;
        ck[v.second] = 1;
        f[r][v.second] = max(f[r][u], v.cost);
        dfs(v.second, r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    dsu.resize(n + 1);
    for(ll &i : dsu) i = -1;
    init();
    initT();
    lp(i, 1, n){
        memset(ck, 0, sizeof(ck));
        ck[i] = 1, f[i][i] = -1;
        dfs(i, i);
    }
    ll q, a, b, res1, res2;
    cin >> q;
    while(q--){
        cin >> a >> b;
        // res1 = s - ed[{b, f[a][b]}];
        // res2 = s - ed[{a, f[b][a]}];
        cout << (s - f[a][b]) << '\n';
    }
}