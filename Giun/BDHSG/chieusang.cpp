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

cll maxn = 1e5 + 107, MOD = 1e4 + 7;
ll n;
pp(ll, ll) f[maxn][2];
vec(ll) g[maxn];
bool d[maxn];

inline void init(){
    ll u, v;
    lp(i, 1, n - 1){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

#define cnt first
#define ways second

void dfs(ll u){
    // cerr << u << ' ';
    ll tmp1 = 1, cnt_tmp1 = 0, tmp0 = 1, cnt_tmp0 = 0;
    for(ll v : g[u]){
        if(d[v]) continue;
        d[v] = 1;
        dfs(v);
        cnt_tmp1 += f[v][1].cnt, tmp1 = (tmp1 * f[v][1].ways) % MOD;
        if(f[v][0].cnt < f[v][1].cnt) cnt_tmp0 += f[v][0].cnt, tmp0 = (tmp0 * f[v][0].ways) % MOD;
        else if(f[v][0].cnt == f[v][1].cnt) cnt_tmp0 += f[v][0].cnt, tmp0 = (tmp0 * (f[v][0].ways + f[v][1].ways)) % MOD;
        else cnt_tmp0 += f[v][1].cnt, tmp0 = (tmp0 * f[v][1].ways) % MOD;
    }
    if(cnt_tmp1) f[u][0] = {cnt_tmp1, tmp1};
    else f[u][0] = {0, 1};
    if(cnt_tmp0) f[u][1] = {cnt_tmp0 + 1, tmp0};
    else f[u][1] = {1, 1};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll t;
    cin >> t;
    while(t--){
        for(vec(ll) &v : g) v.clear();
        cin >> n;
        lp(i, 0, n){
            lp(j, 0, 1){
                f[i][j] = {0, 0};
            }
            d[i] = 0;
        }
        init();
        d[1] = 1;
        dfs(1); 
        if(f[1][0].cnt < f[1][1].cnt) cout << f[1][0].cnt << ' ' << f[1][0].ways << '\n';
        else if(f[1][0].cnt == f[1][1].cnt) cout << f[1][0].cnt << ' ' << f[1][0].ways + f[1][1].ways << '\n';
        else cout << f[1][1].cnt << ' ' << f[1][1].ways << '\n';
    }
}