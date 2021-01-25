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

cll maxn = 1e3 + 7;
ll n, m, s, t, a, b, res[maxn];
vec(pp(ll, ll)) g[maxn];

void ent(){
    ll u, v, w;
    cin >> n >> m >> s >> t >> a >> b;
    lp(i, 1, m){
        cin >> u >> v >> w;
        if ((u == a && v == b) || (u == b && v == a)) continue;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
}

ll dk(ll r, ll s){
    lp(i, 1, n) res[i] = INT_MAX;
    res[r] = 0;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, r});
    ll u, du;
    while(q.size()){
        u = q.top().se;
        du = q.top().fi;
        q.pop();
        if(res[u] == du && u == s) break;
        if(res[u] != du) continue;
        for(pp(ll, ll) v : g[u])
            if(res[v.se] > res[u] + v.fi) res[v.se] = res[u] + v.fi, q.push({res[v.se], v.se});
    }
    return res[s];
}

ii main(){
    opt;
    file;
    ent();
    ll ans = min(dk(s, a) + dk(b, t), dk(s, b) + dk(a, t));
    if(ans >= INT_MAX) cout << "-1";
    else cout << ans;
}
