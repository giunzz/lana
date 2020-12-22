#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

cll maxn = 17;
ll n, m, res = 0;
bool check[107] = {0};
vec(pp(ll, pp(ll, ll))) g[maxn];

void dfs(ll u, ll r, ll mi, ll ma){
    for(auto i : g[u]){
        if(check[i.second.second]) continue;
        check[i.second.second] = 1;
        ll nmi = min(mi, i.second.first), nma = max(ma, i.second.first);
        if(i.first == r){
            // cerr << nmi << ' ' << nma << '\n';
            res = max(nmi + nma, res);
        }
        else dfs(i.first, r, nmi, nma);
        check[i.second.second] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF("bgame");
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, {c, i}});
        g[v].push_back({u, {c, i}});
    }   
    ll ans = 0;
    lp(i, 1, n){
        // res = 0;
        lp(i, 1, m) check[i] = 0;
        dfs(i, i, INT_MAX, 0);
        // ans = max(ans, res);
    }
    cout << res;
}