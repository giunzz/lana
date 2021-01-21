#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define mp(a, b) make_pair(a, b)
#define Fname "mgroup"
using namespace std;

void OF(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5e4 + 7;
ll n, m;
vec(ll) g[maxn];
map<pp(ll, ll), ll> e;
vec(pp(ll, ll)) ee;

void init(){
    ll u, v, c;
    lp(i, 1, m){
        cin >> u >> v >> c;
        g[u].push_back(v);
        g[v].push_back(u);
        e[make_pair(u, v)] = c;
        e[make_pair(v, u)] = c;
        ee.push_back({u, v});
        // ee.push_back({v, u});
    }
}

int main(){
    OF();
    cin >> n >> m;
    init();
    ll res = 0;
    for(pp(ll, ll) &te : ee){
        for(ll &i : g[te.first])
            if(e[mp(i, te.second)]){
                res = max(res, e[mp(te.first, i)] + e[mp(i, te.second)] + e[te]);
            }
    }
    cout << res;
}