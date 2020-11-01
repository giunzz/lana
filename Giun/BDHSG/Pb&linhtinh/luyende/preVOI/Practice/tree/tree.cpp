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
const string tenfile = "tree";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e3 + 7;
ll n, a[maxn], cnt[maxn] = {0};
vec(ll) g[maxn];
bool d[maxn] = {0};

void init(){
    ll u, v;
    lp(i, 1, n - 1){
        cin >> u >> v;
        // cerr << u << ' ' << v << '\n';
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void cnt_leaf(ll u){
    if(g[u].size() == 1) cnt[u] = 1; 
    else for(ll &v : g[u]){
        if(d[v]) continue;
        d[v] = 1;
        cnt_leaf(v);
        cnt[u] += cnt[v];
    }
}

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    init();
    d[1] = 1;
    cnt_leaf(1);
    lp(i, 1, n) cerr << cnt[i] << ' ';
}
