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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vec(vec(pp(ll, ll))) g;
vec(ll) s;
ll n, t;

void enter(){
    ll u, v, c;
    lp(i, 1, n - 1){
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
}

void bfs(ll vt){
    queue<ll> qu;
    qu.push(vt);
    ll u, v;
    bool d[n + 1];
    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        lp(i, 0, g[u].size()-1){
            v = g[u][i].fi;
            if(d[v]) continue;
            s[v] = s[u] + g[u][i].second;
            qu.push(v);
        }
    }
}

ii main(){
    opt;
    file;
    cin >> t;
    while(t--){
        g.clear();
        s.clear();
        cin >> n;
        g.resize(n + 1);
        s.resize(n + 1);
        enter();
        s[1] = 0;
        bfs(1);
    }
}
