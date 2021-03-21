#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "c"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".out", "w", stdout);
}

cll maxn = 2e5 + 7;
ll n, m, q, w[maxn] = {{0}}, s = 0;
vec(ll) g[maxn];
pp(ll, ll) o[maxn];

// struct quang{
//     char c;
//     ll a = -1, b = -1;
// }t[maxn];

ll d[maxn] = {0};

void dfs(ll u){
    d[u] += w[u];
    for(ll v : g[u]){
        if(!d[v]) {dfs(v); d[u] += d[v];}
    }
}

void init(){
    cin >> n >> m >> q;
    lp(i, 1, n) {cin >> w[i]; s += w[i];}
    ll u, v, cnt = 0;
    lp(i, 1, m){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        o[i] = {u, v};
    }
    ll a, b;
    char c;
    lp(i, 1, q){
        memset(d, 0, sizeof(d));
        // cin >> t[i].c >> t[i].a;
        // if(t[i].c == 'C') {cin > t[i].b; ++cnt; }
        cin >> c;
        if(c == 'D'){
            cin >> a;
            for(ll v = 0; v < g[o[a].first].size(); v++){
                if(g[o[a].first][v] == o[a].second) {
                    g[o[a].first].erase(g[o[a].first].begin() + v);
                    break;
                }
            }
            for(ll v = 0; v < g[o[a].first].size(); v++){
                if(g[o[a].second][v] == o[a].first) {
                    g[o[a].second].erase(g[o[a].second].begin() + v);
                    break;
                }
            }
        }
        if(c == 'C') {
            cin >> a >> b;
            w[a] = b;
        }
        lp(i, 1, n){
            if(!d[i]) dfs(i);
        }
        ll ans = 0;
        lp(i, 1, n){ ans = max(ans, d[i]); }
        cout << ans << endl;
        // cerr << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // File();
    init();
}