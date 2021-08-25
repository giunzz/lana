#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "transport"
using namespace std;

cll mxn = 1e5 + 5;
ll n, a;
vec(ll) g[mxn];

ll dfs(ll u, ll p){
    ll res = 0;
    for(ll v : g[u]) if(v != p){
        res = max(dfs(v, u) + 1, res);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    cin >> n >> a;
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << dfs(a, -1);
}
