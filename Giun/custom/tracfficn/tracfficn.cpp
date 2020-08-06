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
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "tracfficn";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7, maxk = 307;
ll n, m, k, s, t, ans = 0, f[maxn] = {0}, ds[maxn] = {0}, dd[maxn] = {0};
vec(pp(ll, ll)) g[maxn];

struct strgk{
    ll u, w, v;
}gk[maxk];

void ent(){
    ll u, v, w;
    lp(i, 1, m){
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    lp(i, 1, k){
        cin >> u >> v >> w;
        gk[i] = {u, w, v};
    }
}

void dk(ll r, ll p, ll res[]){
    ll u;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) res[i] = INT_MAX; res[r] = 0;
    q.push({0, r});
    pp(ll, ll) tmp;
    while(!q.empty()){
        tmp = q.top();
        u = tmp.se;
        q.pop();
        if(tmp.fi == res[u] && u == p) break;
        if(tmp.fi != res[u]) continue;
        for(pp(ll, ll) v : g[u])
            if(res[v.se] > res[u] + v.fi)
                res[v.se] = res[u] + v.fi, q.push({res[v.se], v.se});
    }
}

ii main(){
    opt;
    file;
    cin >> n >> m >> k >> s >> t;
    ent();
    lp(i, 1, n)
        if(i != t){
            dk(i, t, dd);
            f[i] = dd[t];
        }
    dk(s, 0, ds);
    ll ddt[2], ans = ds[t];
    lp(i, 1, k){
        ddt[1] = ds[gk[i].u] + f[gk[i].v] + gk[i].w;
        ddt[0] = ds[gk[i].v] + f[gk[i].u] + gk[i].w;
        ans = min(ans, min(ddt[1], ddt[0]));
    }
    if(ans==INT_MAX) cout << "-1";
    else cout << ans;
}