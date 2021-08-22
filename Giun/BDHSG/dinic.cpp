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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e3 + 6;
ll n, m, s, t, c[mxn][mxn] = {{0}}, d[mxn] = {0};
vec(ll) g[mxn];

bool find_path(){
    memset(d, 0, sizeof d);
    d[s] = 1;
    queue<ll> q;
    q.push(s);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : g[u]) if(!d[v] && c[u][v]){
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return d[t];
}

ll inc(ll u, ll mi){
    ll cost;
    if(u == t) return mi;
    for(ll v : g[u]) if(d[v] == d[u] + 1 && (cost = inc(v, min(mi, c[u][v])))){
        c[u][v] -= cost, c[v][u] += cost;
        return cost;
    }
    return 0;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> s >> t;
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u][v] += w;
    }
    ll ans = 0;
    while(find_path()){
        ans += inc(s, 1e18);
    }
    cout << ans;
}   