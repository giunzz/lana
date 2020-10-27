#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 2e5 + 7;
ll n, k = 0, ans = 0, tt = 0, db[maxn] = {0};
bool dC[maxn] = {0}, d[maxn] = {0}; 
vec(pp(ll, ll)) g[maxn], preg[maxn];

void init(){
    ll v, c;
    lp(u, 1, n){
        cin >> v >> c;
        cerr << u  << ' ' << v << ' ' << c << '\n';
        g[u].push_back({c, v});
        preg[v].push_back({c, u});
    }
}

#define pos second
#define cost first

#define fi first
#define se second

ll res;
vec(ll) vl, tg;

pp(ll, ll) dfs(ll &u, ll const &r){
    ll tmp = 0, tmp1 = 0;
    for(pp(ll, ll) &v : preg[u]){
        if(dC[v.pos]) continue;
        d[v.pos] = 1;
        tmp += dfs(v.pos, r).fi; //so thanh pho do vao
        tmp1 += v.cost; //so tien hien co
    }
    if(tmp1 < g[u].back().cost && u != r)  tmp += g[u].back().cost - tmp1;
    return {tmp, tmp1};
}

void getCycle(ll &r){
    bool ok = 0;
    ll mindb = LLONG_MAX;
    // cerr << r << '\n';
    vl.clear();
    ll u = r;
    while(!dC[u]){
        pp(ll, ll) v = g[u].back();
        vl.push_back(u);
        mindb = min(mindb, v.cost);
        dC[u] = 1;
        u = v.pos;
    }
    // cerr << ans << '\n';
    lp(i, 0, vl.size() - 1){
        // cerr << u << ' ';
        u = vl[i];
        if(preg[u].size() > 1){
            pp(ll, ll) tmp = dfs(u, u);
            db[u] = tmp.se;
            ans += tmp.fi;
        }
        ll tmp1 = db[u] + g[vl[(i - 1 + vl.size()) % vl.size()]].back().cost;
        // cerr << u << ' ' << db[u] << '\n';
        if(tmp1 < g[u].back().cost){
            ans += g[u].back().cost - tmp1;
            ok = 1;
        }
    }
    // cerr << mindb;
    if(!ok) ans += mindb;
    // cerr << '\n' << ans;
}

void findCycle(ll &r){
    ll u = r;
    res = 0;
    // pp(ll, ll) v = g[u];
    // if(d[v.pos]){
    //     if(dC[v.pos]) return;
    //     ++k;
    //     selectCycle(v.pos);
    // }
    while(g[u].size()){
        pp(ll, ll) v = g[u].back();
        if(d[v.pos]){
            getCycle(v.pos);
            break;
        }
        d[v.pos] = 1;
        u = v.pos;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    init();
    lp(i, 1, n){
        if(!d[i]) findCycle(i);
    }
    cout << ans;
}