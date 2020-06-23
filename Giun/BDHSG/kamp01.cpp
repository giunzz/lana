#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
cll esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e5 + 7;
ll tg[maxn] = {0}, trace[maxn] = {0}, d[maxn] = {0}, l, n, k;
vec(pp(ll, ll)) g[maxn];

bool check(ll u, ll v){
    lp(i, 0, g[u].size() - 1){
        if(g[u][i].first == v) return 1;
    }
    return 0;
}

void dfs(ll u){
    lp(i, 2, n){
        if(!d[i] && check(u, i)){
            d[i] = u;
            dfs(i);
        }
    }
}   

int main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, n - 1){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
    lp(i, 1, k) cin >> tg[i];
    dfs(1);
    lp(i,1,k){
        ll j = tg[i];
        
    }
}
