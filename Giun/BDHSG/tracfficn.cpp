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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7, maxk = 307;
ll n, m, k, s, t, ds[maxn] = {0}, dt[maxn] = {0}, ans = 0;
vec(pp(ll, ll)) g[maxn];

struct strgk{
    ll u, t, v;
}gk[maxk];

void ent(){
    ll u, v, t;
    lp(i, 1, m){
        cin >> u >> v >> t;
        g[u].push_back({t, v});
    }
    lp(i, 1, k){
        cin >> u >> v >> t;
        gk[i] = {u, t, v};
    }
}

void dk(ll r, ll res[]){
    lp(i, 1, n) if(i != r) res[i] = INT_MAX;
    bool fr[maxn] = {0};
    ll u, ts;
    while(1){
        u = 0, ts = INT_MAX;
        lp(i, 1, n)
            if(!fr[i] and ts > res[i]) u = i, ts = res[i];
        if(!u) break;
        fr[u] = 1;
        for(pp(ll, ll) v : g[u])
            res[v.se] = min(res[v.se], res[u] + v.fi);
    }
}

ii main(){
    opt;
    file;
    cin >> n >> m >> k >> s >> t;
    ent();
    dk(s, ds);
    dk(t, dt);
    ll dd[2];
    ans = ds[t];
    lp(i, 1, k){
        dd[0] = ds[gk[i].u] + dt[gk[i].v] + gk[i].t;
        dd[1] = ds[gk[i].v] + dt[gk[i].u] + gk[i].t;
        ans = min(ans, min(dd[1], dd[0]));
    }
    if(ans==INT_MAX) cout << "-1";
    else cout << ans;
}
