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

cll maxn = 5e4 + 7;
ll n, m, s, t;
vec(pp(pp(ll, ll), ll)) g[maxn];
ll dp[maxn][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> s >> t;
    lp(i, 1, m){
        ll c, u, v, w;
        cin >> c >> u >> v >> w;
        g[u].push_back({{w, c - 1}, v});
        g[v].push_back({{w, c - 1}, u});
    }
    // lp(u, 1, n) for(auto v : g[u]) cerr  << u << " -> " << v.second << "  " << v.first.first << ' ' << v.first.second << '\n';
    // cerr << s << ' ' << t;
    lp(i, 1, n) lp(j, 0, 2) dp[i][j] = LLONG_MAX;
    dp[s][2] = 0;
    // lp(i, 1, n) lp(j, 0, 1) dp[i][j] = -1;
    priority_queue<pp(ll, pp(pp(ll, ll), ll)), vec(pp(ll, pp(pp(ll, ll), ll))), greater<pp(ll, pp(pp(ll, ll), ll))>> q;
    q.push({0, {{LLONG_MAX, LLONG_MAX}, s}});
    while(q.size()){
        ll u = q.top().second.second, cu = q.top().first, d0 = q.top().second.first.first, d1 = q.top().second.first.second;
        q.pop();
        if(dp[u][2] != cu || d0 != dp[u][0] || d1 != dp[u][1]) continue;
        for(auto i : g[u]){
            ll w = i.first.first, t = i.first.second, v = i.second, nw = max(dp[u][t], w), pre = dp[u][!t];
            if(pre == LLONG_MAX) pre = 0;
            if(nw == LLONG_MAX) nw = w;
            // if(dp[u][t] == -1) nw = w;
            // else nw = min(dp[u][t], w); 
            if(nw + pre < dp[v][2]){
                dp[v][2] = nw + pre;
                dp[v][t] = nw;
                dp[v][!t] = dp[u][!t];
                if(t) q.push({dp[v][2], {{dp[v][!t], dp[v][t]}, v}});
                else q.push({dp[v][2], {{dp[v][t], dp[v][!t]}, v}});
            }
        }
    }
    // cerr << dp[4][1];   
    cout << dp[t][2];
}