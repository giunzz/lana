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

cll mxn = 103, mn = 100, s = 0, t = 201;
ll n, m, a[mxn], b[mxn], c[mxn * 2][mxn * 2] = {{0}}, sum, d[mxn * 2] = {0};
vec(ll) g[mxn * 2];

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
    if(u == t) return mi;
    ll cost;
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
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) cin >> b[i];
    if((sum = accumulate(a + 1, a + 1 + n, 0)) != accumulate(b + 1, b + 1 + n, 0)){
        cout << "NO";
        return 0;
    }
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        c[u][v + mn] = b[v];
        c[v][u + mn] = b[u];
        g[u].push_back(v + mn), g[v + mn].push_back(u);
        g[u + mn].push_back(v), g[v].push_back(u + mn);
    }
    lp(u, 1, n){
        c[u + mn][t] = c[u][u + mn] = b[u];
        c[s][u] = a[u];
        g[s].push_back(u), g[u].push_back(s);
        g[t].push_back(u + mn), g[u + mn].push_back(t);
        g[u].push_back(u + mn), g[u + mn].push_back(u);
    }
    // lp(i, s, t){
    //     if(g[i].empty()) continue;
    //     for(ll v : g[i]) if(i < v) cerr << i << ' ' << v << ' '  << c[i][v] << '\n';
    // }
    ll tmp = 0;
    while(find_path()){
        tmp += inc(s, 1e18);
    }
    if(tmp != sum){
        cout << "NO";
    } else{
        cout << "YES\n";
        lp(i, 1, n){ 
            lp(j, 1 + mn, n + mn) cout << c[j][i] << ' ';
            cout << '\n';
        }
    }
}