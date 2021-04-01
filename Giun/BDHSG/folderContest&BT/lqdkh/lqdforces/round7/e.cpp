// adidas thai den thien style style
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

cll maxn = 1e5 + 7;
ll n, m, num[maxn] = {0}, low[maxn] = {0}, Time = 0, cnt[maxn] = {0}, ans = 0;
vec(ll) g[maxn];

void dfs(ll u, ll p){
    low[u] = num[u] = ++Time;
    for(ll v : g[u]){
        if(v == p) continue;
        if(num[v] != 0) low[u] = min(low[u], num[v]);
        else{
            ++cnt[u];
            dfs(v, u);
            cnt[u] += cnt[v];
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[v]){
                // cerr <<u << ' ' << v << '\n';
                ans = max(ans, (cnt[v] + 1) * (n - cnt[v] - 1));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    // cerr << cnt[3];
    cout << ans;
}