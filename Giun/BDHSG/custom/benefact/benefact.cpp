#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "benefact"
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

cll maxn = 5e4 + 7;
ll n, dp[maxn] = {0}, ans;
vec(pp(ll, ll)) g[maxn];
bool d[maxn];

void dfs(ll u){
    ll max1, max2;
    max1 = max2 = INT_MIN;
    for(pp(ll, ll) i : g[u]){
        ll v = i.first, w = i.second;
        if(d[v]) continue;
        d[v] = 1;
        dfs(v);
        ll tot = dp[v] + w;
        if(tot > max1) max2 = max1, max1 = tot;
        else if(tot > max2) max2 = tot;
    }
    if(max1 == INT_MIN) return;
    dp[u] = max1;
    if(max2 != INT_MIN) ans = max(ans, max1 + max2);
}

void sol(){
    cin >> n;
    lp(i, 1, n) g[i].clear(), dp[i] = d[i] = 0; ans = INT_MIN;
    lp(i, 1, n - 1){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}