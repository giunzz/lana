#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
vec(ll) g[maxn];
ll n, m, s, t, trace[maxn], c[maxn][maxn] = {{0}}, ans = 0, f[maxn];

#define ver second
#define cs first

inline ll dfs(ll u, ll sink){
    ll tmp;
    if(u == sink) return LLONG_MAX;
    for(ll v : g[u]){
        if(!trace[v] && c[u][v]){
            trace[v] = u;
            if(tmp = dfs(v, sink)) return min(tmp, c[u][v]);
        }
    }
    return 0;
}

// inline ll pfs(ll r, ll sink){
//     priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<(pp(ll, ll))>> q;
//     q.push({0, r});
//     lp(i, 1, n) f[i] = LLONG_MAX;
//     f[r] = 0;
//     while(q.size()){
//         ll u = q.top().second, cu = q.top().first;
//         q.pop();
//         if(cu != f[u]) continue;
//         if(u == sink) break;
//         for(ll v : g[u]){
//             if(c[u][v] > f[u] && !trace[u]){

//             }
//         }
//     }
// }

inline void bfs(ll r, ll sink){
    queue<ll> q;
    q.push(r);
    f[r] = LLONG_MAX, f[t] = 0;
    while(q.size()){
        ll u = q.front();
        q.pop();
        if(u == sink) break;
        for(ll v : g[u]){
            if(c[u][v] && !trace[v]){
                trace[v] = u;
                f[v] = min(f[u], c[u][v]);
                q.push(v);
            }
        }
    }
}

inline ll findpath(){
    memset(trace, 0, sizeof(trace));
    trace[s] = -1;
    bfs(s, t);
    return f[t];
}

inline void increase(ll cost){
    ans += cost;
    ll v = t;
    while(trace[v] != -1){
        ll u = trace[v];
        c[u][v] -= cost, c[v][u] += cost;
        v = u;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> s >> t;
    lp(i, 1, m){
        ll u, v, cost;
        cin >> u >> v >> cost;
        g[u].push_back(v), g[v].push_back(u);
        c[u][v] = cost;
    }

    ll cost;
    while(cost = findpath()){
        increase(cost);
    }
    cout << ans;
}