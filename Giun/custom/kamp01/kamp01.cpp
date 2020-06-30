#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
cll esf = 1e-9;
const string tenfile = "kamp01";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e5 + 7;
ll tg[maxn] = {0}, trace[maxn] = {0}, d[maxn] = {0}, l, n, k, s[maxn] = {0}, ans = 0;
vector<pair<ll, ll>> g[maxn];

void dfs(ll u){
    for (ll i = 0; !g[u].empty() && i < g[u].size(); i++){
        ll v = g[u][i].fi;
        if(d[v]) continue;
        s[v] = s[u] + g[u][i].se;
        d[v] = u;
        dfs(v);
    }
}

void enter(){
    cin >> n >> k;
    // cerr << n << " " << k << endl;
    ll u, v, c;
    lp(i, 1, n - 1){
        cin >> u >> v >> c;
        // cerr << u << " " << v << " " << c << endl;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
    lp(i, 1, k) cin >> tg[i];
}

int main(){
    opt;
    file;
    enter();
    // lp(i, 0, g[2].size() - 1){
    //     cerr << 2 << " " << g[2][i].fi << " " << g[2][i].se << endl;
    // }
    memset(d, 0, sizeof(d));
    d[tg[1]] = -1, s[tg[1]] = 0;
    dfs(tg[1]);
    lp(i, 1, n) if(d[i] == -1) d[i] = 0;
    memset(trace, 0, sizeof(trace));
    lp(i, 2, k){
        ll a = tg[i];
        while(a != tg[1] && !trace[a]){
            trace[a] = 1;
            a = d[a];
        }
        ans += s[tg[i]] - s[a];
    }
    cout << ans;
}
