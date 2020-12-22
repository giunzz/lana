#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, totin, totout;
vec(ll) g[maxn], tin, tout, a, p;
vec(bool) check;

void dfs(ll u){
    tin[u] = ++totin;
    a[totin] = u;
    for(ll v : g[u]){
        p[v] = u;
        dfs(v);
    }
    tout[u] = ++totout;
}

ll cnp(ll l, ll r, ll u, ll v){
    if(l == r) return r;
    if(tout[u] >= tout[v]) return u;
    ll mid = (l + r) >> 1;
    if(mid >= tin[u]) return cnp(l, mid - 1, u, v);
    ll i = a[mid];
    // tin u < tin v & tout u < tout v
    if(tout[i] > tout[v]) return cnp(mid, r, u, v);
    // tout i <= tout v
    if(tout[i] > tout[u]) return cnp(l, mid - 1, i, v);
    // tout i <= tout u < tout v
    return cnp(l, r, p[u], p[v]);
}

void solve(){
    cin >> n;
    totin = totout = 0;
    tin.resize(n + 1); tout.resize(n + 1); a.resize(n + 1); p.resize(n + 1); check.assign(n + 1, 0);
    p[1] = 1;
    lp(u, 1, n){
        g[u].clear();
        ll num, v;
        cin >> num;
        lp(j, 1, num){
            cin >> v;
            check[v] = 1;
            g[u].push_back(v);
        }
    }
    // lp(u, 1, n){
    //     for(ll v : g[u]) cerr << u << ' ' << v << '\n';
    // }
    ll r;
    lp(i, 1, n) if(!check[i]) r = i;
    dfs(r);
    // lp(i, 1, n) cerr << i << ' ' << tin[i] << ' ' << tout[i] << '\n';
    ll qr;
    cin >> qr;
    while(qr--){
        ll u, v;
        cin >> u >> v;
        if(tin[u] > tin[v]) swap(u, v);
        cout << cnp(1, n, u, v) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll cs;
    cin >> cs;
    lp(i, 1, cs){
        cout << "Case " << i << ":\n";
        solve();
    }
}