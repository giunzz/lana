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

cll maxn = 1e5 + 107;
ll n;
pp(ll, ll) f[maxn][2];
vec(ll) g[maxn];

inline void init(){
    ll u, v;
    lp(i, 1, n - 1){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
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
        }
        init(); 
    }
}