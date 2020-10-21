#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "distk"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5e4 + 7, maxk = 207;
ll n, k, f[maxn][maxk] = {{0}}, ans = 0, d[maxn] = {0};
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
        d[v] = u;
        dfs(v);
        lp(i, 0, k){
            f[u][i + 1] += f[v][i];
        }
    }
    ans += f[u][k];
    // for(ll i = 1; k - i >= 0; ++i){
    //     if(f[u][i] && f[u][k - 1] && )
    // }
    ll tmp = 0;
    // cerr << u << ' ' << ans << '\n';
    for(ll &v : g[u]){
        if(d[v] != u) continue;
        lp(i, 0, k - 2){
            if(k - (i + 2) < 0) break;
            if(f[u][k - (i + 1)] - f[v][k - (i + 1) - 1] > 0) 
                tmp += f[v][i] * (f[u][k - (i + 1)] - f[v][k - (i + 1) - 1]);
            // cerr << u << ' ' << v << ' ' << i << ' ' << ans << '\n';
        }
    }
    ans += tmp>>1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> k;
    init();
    lp(i, 1, n) f[i][0] = 1;
    d[1] = -1;
    dfs(1);
    // lp(i, 1, n){ lp(j, 0, k) cerr << f[i][j] << ' '; cerr << '\n';}
    cout << ans;
}