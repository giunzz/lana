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

cll mxn = 1e5 + 7;
ll n, col[mxn], p[mxn], sz[mxn], nxt[mxn], cnt[mxn] = {0}, sum, one_col;
bool isBig[mxn] = {0};
vec(ll) g[mxn];
pp(ll, ll) res[mxn];

void init_dfs(ll u){
    sz[u] = 1, nxt[u] = -1;
    for(ll v : g[u]) if(v != p[u]) p[v] = u, init_dfs(v), sz[u] += sz[v], nxt[u] = (nxt[u] == -1 || sz[nxt[u]] < sz[v]) ? v : nxt[u];    
}

void add(ll u, ll num, bool haveDo){
    cnt[col[u]] += num;
    if(haveDo){
        if(cnt[col[u]] == cnt[col[one_col]]) sum += col[u];
        else if(cnt[col[u]] > cnt[col[one_col]]) sum = col[u], one_col = col[u];
    }
    for(ll v : g[u]) if(v != p[u] && !isBig[v]) add(v, num, haveDo);
}

void dfs(ll u, bool keep){
    for(ll v : g[u]) if(v != nxt[u] && v != p[u]) dfs(v, 0);
    if(nxt[u] != -1) dfs(nxt[u], 1), isBig[nxt[u]] = 1;
    one_col = res[nxt[u]].second, sum = res[nxt[u]].first;
    add(u, 1, 1);
    res[u] = {sum, one_col};
    if(nxt[u] != -1) isBig[nxt[u]] = 0;
    if(!keep) add(u, -1, 0);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> col[i];
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    p[1] = -1;
    init_dfs(1);
    dfs(1, 1);
    lp(i, 1, n) cout << res[i].first << ' ';
}