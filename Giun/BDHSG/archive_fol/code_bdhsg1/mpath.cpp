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

cll maxn = 2e5 + 7;
ll m, dp[maxn] = {0};
vec(pp(ll, ll)) e;
vec(ll) g[maxn];
bool d[maxn];

#define x first 
#define y second

// inline bool cpr(pp(ll, ll) &q, pp(ll, ll) &p){
//     return q.x < p.x || (q.x == p.x && q.y >= p.y);
// }

// ll dfs(ll u){
//     ll tmp = -1, i = (ll)g[u].size() - 1;
//     while(i >= 0){
//         ll v = g[u][i];
//         d[v] = 1;
//         g[u].pop_back();
//         ll tt = dfs(v);
//         while(i > g[u].size()) --i;
//         if(tt > tmp) tmp = tt;
//         --i;
//     }
//     return tmp + 1;
// }

void init(){
    set<ll> compress;
    ll u, v;
    lp(i, 1, m){
        cin >> u >> v;
        if(u < v) swap(u, v);
        e.push_back({u, v});
        compress.insert(u);
        compress.insert(v);
    }
    vec(ll) tmp(compress.begin(), compress.end());
    // sort(e.begin(), e.end(), cpr);
    for(pp(ll, ll) &ee : e){
        ee.x = lower_bound(tmp.begin(), tmp.end(), ee.x) - tmp.begin();
        ee.y = lower_bound(tmp.begin(), tmp.end(), ee.y) - tmp.begin();
        // cerr << ee.x << ' ' << ee.y << '\n';
        // if(ee.x <= ee.y) g[ee.x].push_back(ee.y);
        // else g[ee.y].push_back(ee.x);
    }
    // lp(i, 0, 2 * m){
    //     sort(g[i].rbegin(), g[i].rend());
    // }
    // ll ans = 0;
    // lp(i, 0, 2 * m){
    //     if(!d[i] && g[i].size()){
    //         d[i] = 1;
    //         ll tmp = dfs(i);
    //         if(tmp > ans) ans = tmp;
    //     }
    // }
    ll ans = 0;
    sort(e.rbegin(), e.rend());
    for(pp(ll, ll) ee : e){
        // cerr << ee.x << ' ' << ee.y << '\n';
        dp[ee.y] = max(dp[ee.y], dp[ee.x] + 1);
        ans = max(ans, dp[ee.y]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> m;
    init();
}