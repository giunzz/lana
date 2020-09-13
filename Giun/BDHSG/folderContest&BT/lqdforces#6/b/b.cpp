#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "b"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".out", "w", stdout);
}

ll n;
cll maxn = 1e5 + 7;
cll MOD = 1e9+7;
vec(ll) g[maxn];

void init(){
    ll u, v;
    lp(i, 1, n - 1){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool d[maxn] = {0};
pp(ll, ll) f[maxn];
#define w first
#define b second

void dfs(ll u){
    // cerr << u << ' ';
    ll t = 1, td = 1;
    // if(g[u].empty()) {f[u] = {1, 1}; return;}
    for(ll v : g[u]){
        if(d[v]) continue;
        d[v] = 1;
        dfs(v);
        t = (t * f[v].w) % MOD;
        td =  (td *(f[v].w + f[v].b)) % MOD;
    }
    // for(ll v : g[u])  
    f[u].w = (td) % MOD;
    f[u].b = (t) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File();
    cin >> n;
    init();
    d[1] = 1;
    dfs(1);
    // lp(i, 1, n){
    //     cerr << i << ' ' << f[i].w << ' ' << f[i].b << endl;
    // }
    cout <<( (f[1].w + f[1].b) % MOD);
}

//em bi ngu cai mod :( 