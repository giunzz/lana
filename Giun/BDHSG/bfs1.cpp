#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "bfs1";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vec(ll) g[(int)1e5 + 7];
ll ans[(ll)1e5 + 7], n, m;
bool d[(ll)1e5 + 7];

void bfs(){
    ll u;
    queue<ll> qu;
    qu.push(1);
    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        d[u] = 1;
        lp(i, 0, g[u].size() - 1){
            if(d[g[u][i]]) continue;
            ans[g[u][i]] = ans[u] + 1;
            d[g[u][i]] = 1;
            qu.push(g[u][i]);
        }
    }
}

ii main(){
    opt;
    file;
    cin >> n >> m;
    ll u, v;
    lp(i, 1, m){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(ans, 0, sizeof(ans));
    bfs();
    cout << 0 << endl;
    lp(i, 2, n){
        if(!ans[i]) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
}
