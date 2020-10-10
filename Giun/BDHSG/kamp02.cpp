#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

cll maxn = 5e5 + 7;
ll n, k, a[maxn];
vec(pp(ll, ll)) g[maxn];

inline void OF(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

#define cost first
#define p second

inline void init(){
    ll u, v, c;
    lp(i, 1, n - 1){
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }
    lp(i, 1, k){
        cin >> a[i];
    }
}

int main(){
    OF();
    cin >> n >> k;
    init();
    
}