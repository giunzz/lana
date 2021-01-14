#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n, m, _a, _b, g0, x, y, mod;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> _a >> _b >> g0 >> x >> y >> mod;
    vec(vec(ll)) adj(n + 1, vec(ll)(m + 1));
    lp(i, 1, n) lp(j, 1, m) adj[i][j] = g0, g0 = (g0 * x + y) % mod;
    lp(i, 1, n){
        lp(j, 1, m) cerr << adj[i][j] << ' ';
        cerr << '\n';
    }
}