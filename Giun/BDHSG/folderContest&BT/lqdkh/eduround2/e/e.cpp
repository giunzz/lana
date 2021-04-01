#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "e"
using namespace std;

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e5 + 7;
ll n, m, s, t, a, b, ans = 1e17;
pp(ll, ll) dpup[mxn], dpdown[mxn];
vec(pp(ll, ll)) g[mxn];
vec(ll) dag[mxn], dpa, dpb;
unordered_map<ll, unordered_map<ll, ll>> e;
bool d[mxn] = {0};

void dijkstra(vec(ll)& dp, ll root){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, root});
    dp[root] = 0;
    while(q.size()){
        ll u = q.top().second, cu = q.top().first;
        q.pop();
        if(cu != dp[u]) continue;
        for(pp(ll, ll) i : g[u]){
            ll v = i.second, cuv = i.first;
            if(cu + cuv < dp[v]){
                dp[v] = cu + cuv;
                q.push({dp[v], v});
            }
        }
    }
}

pp(ll, ll) dfs(ll u){
    if(dpdown[u] != pp(ll, ll)(-1, -1)) return dpdown[u];
    if(u == t) return dpdown[u] = {dpa[u], dpb[u]};
    dpdown[u] = {1e17, 1e17};
    for(ll v : dag[u]){
        pp(ll, ll) miv = dfs(v);
        dpdown[u] = {min(dpdown[u].first, miv.first), min(dpdown[u].second, miv.second)};
    }
    if(dpdown[u] != pp(ll, ll)(1e17, 1e17)) dpdown[u] = {min(dpdown[u].first, dpa[u]), min(dpdown[u].second, dpb[u])};
    return dpdown[u];
}

void bfs(){
    queue<ll> q;
    lp(i, 1, n) dpup[i] = {dpa[i], dpb[i]};
    dpup[s] = {dpa[s], dpb[s]};
    q.push(s);
    d[s] = 1;
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : dag[u]){
            dpup[v] = {min(dpup[v].first, dpup[u].first), min(dpup[v].second, dpup[u].second)};
            if(dpdown[v] != pp(ll, ll)(-1, -1)) ans = min({ans, dpup[u].first + dpdown[v].second, dpup[u].second + dpdown[v].first});
            if(!d[v]){
                d[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> s >> t >> a >> b;
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    priority_queue<pp(ll, pp(ll, ll)), vec(pp(ll, pp(ll ,ll))), greater<pp(ll, pp(ll, ll))>> q;
    q.push({0, {0, s}});
    vec(ll) dp(n + 1, 1e17);
    dp[s] = 0;
    vec(bool) dd(n + 1, 0);
    while(q.size()){
        ll u = q.top().second.second, pu = q.top().second.first, cu = q.top().first;
        q.pop();
        if(dp[u] != cu) continue;
        if(!e[pu][u]) dag[pu].push_back((e[pu][u] = 1, u));
        if(dd[u]) continue;
        dd[u] = 1;
        for(pp(ll, ll) i : g[u]){
            ll v = i.second, cuv = i.first;
            if(cu + cuv <= dp[v]){
                dp[v] = cu + cuv;
                q.push({dp[v], {u, v}});
            }
        }
    }
    dpa.assign(n + 1, 1e17); dpb.assign(n + 1, 1e17);
    dijkstra(dpa, a); dijkstra(dpb, b);
    lp(i, 1, n) dpdown[i] = {-1, -1};       
    dfs(s);
    bfs();
    cout << min(ans, dpa[b]);
}