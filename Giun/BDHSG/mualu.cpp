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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e5 + 7;
ll n, m, x, sz[mxn], par[mxn];

ll _get(ll u){
    return par[u] = (par[u] == u ? u : _get(par[u]));
}

void _join(ll u, ll v){
    u = _get(u), v = _get(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

int main(){
    giuncute();
    cin >> n >> m >> x;
    lp(i, 1, n) sz[i] = 1, par[i] = i;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        if(c < x) continue;
        _join(u, v);
    }
    ll ans = 0;
    lp(i, 1, n) if(par[i] == i) ++ans;
    cout << ans;
}