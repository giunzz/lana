#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".ans").c_str(), "w", stdout);
}

cll MOD = 998244353;
ll n, m;
vec(vec(pp(ll, pp(ll, ll)))) g;
vec(ll) f;
vec(bool) d;

#define se second.first
#define th second.second
#define fi first

ll cnt = 0;

void dfs(ll u, ll prec, ll prev){
    for(pp(ll, pp(ll, ll)) v : g[u]){
        if(prec < v.se && prev < v.th) ++cnt, dfs(v.fi, v.se, v.th);
    }
}

void bruce(){
    cin >> n >> m;
    g.resize(n + 1);
    f.resize(n + 1);
    // d.resize(n + 1);
    for(ll &i : f) i = 0;
    // lp(i, 1, n) d[i] = 0;
    ll u, v, tc, ts;
    lp(i, 1, m){
        cin >> u >> v >> tc >> ts;
        g[u].push_back({v, {tc, ts}});
    }
    ll ans = 0;
    lp(i, 1, n){
        // lp(i, 1, n) d[i] = 0;
        // lp(i, 1, n) f[i] = 0;
        cnt = 0;
        // d[i] = 1;
        dfs(i, 0, 0);
        // cerr << cnt << '\n';
        (ans += cnt) %= MOD;
    }
    cout << ans;
}

int main(){
    // file("dnprevoib");
    ll cs;
    cin >> cs;
    if(cs == 1 || cs == 2) bruce();
}