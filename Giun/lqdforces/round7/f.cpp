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

cll maxn = 9;
ll w, a[3], b[3], n = 7, op[] = {4, 5, 6}, cl[] = {1, 2, 3}, c[maxn][maxn] = {{0}}, trace[maxn], f[maxn], ans = 0, s = 0, t = 7;
vec(ll) g[maxn];

ll test = 0;

inline void bfs(ll r, ll sink){
    queue<ll> q;
    vec(bool) dd(maxn, 0);
    q.push(r);
    f[r] = LLONG_MAX, f[t] = 0, dd[r] = 1;
    while(q.size()){
        ll u = q.front();
        q.pop();
        if(u == sink) break;
        for(ll v : g[u]){
            if(c[u][v] && !trace[v] && !dd[v]){
                trace[v] = u, dd[v] = 1;
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
    // if(test == 3) lp(i, 0, 7) cerr << i << ' ' << trace[i] << '\n';
    while(trace[v] != -1){
        ll u = trace[v];
        c[u][v] -= cost, c[v][u] += cost;
        v = u;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> w;
    lp(i, 0, 2) cin >> a[i];
    lp(i, 0, 2) cin >> b[i];
    lp(i, 0, 2){
        g[0].push_back(cl[i]), g[cl[i]].push_back(0);
        c[0][cl[i]] = a[i];
        g[7].push_back(op[i]), g[op[i]].push_back(7);
        c[op[i]][7] = b[i];
        lp(j, 0, 2){
            if(j == (i + 1) % 3) continue;
            g[cl[i]].push_back(op[j]), g[op[j]].push_back(cl[i]);
            c[cl[i]][op[j]] = min(a[i], b[j]);
        }
    }  
    ll cost;
    while(cost = findpath()){
        // ++test;
        // cerr << test<< ' ';
        increase(cost);
    }
    cout << (w - ans);
}