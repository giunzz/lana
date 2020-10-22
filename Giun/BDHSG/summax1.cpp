#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "summax1"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 2e5 + 7;
ll n, a[maxn], f[maxn] = {0};
bool d[maxn] = {0};
vec(ll) g[maxn];

void init(){
    ll v;
    cin >> v;
    lp(u, 2, n){
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(ll u){
    for(ll &v : g[u]){
        if(d[v]) continue;
        d[v] = 1;
        // cerr << u << a[u] << ' ' << v << a[v] << '\n';
        dfs(v);
        f[u] = max(f[u], f[v]);
    }
    f[u] += a[u];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    init();
    d[1] = 1;
    dfs(1);
    cout << f[1];
}