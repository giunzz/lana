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
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e6 + 7;
ll n, f[maxn] = {0}, k = 0;
bool tt[maxn];
vec(ll) g[maxn];

void dfs(ll u){
    if(f[u]) return;
    if(tt[u]){
        f[u] = LLONG_MAX;
        for(ll &v : g[u]){
            dfs(v);
            f[u] = min(f[u], f[v]);
        }
    }
    else{
        for(ll &v : g[u]){
            dfs(v);
            f[u] += f[v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n;
    lp(i, 1, n) cin >> tt[i];
    lp(i, 2, n){
        ll t;
        cin >> t;
        g[t].push_back(i);
    }
    lp(i, 1, n){
        if(g[i].empty()){
            f[i] = 1;
            ++k;
        }
    }
    dfs(1);
    cout << (k + 1 - f[1]);
}