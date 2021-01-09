#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define YES "YES\n"
#define NO "NO\n"
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

void dfs(ll u, const vec(vec(ll)) &g, vec(ll) &col, ll &n, bool color){
    for(ll v : g[u]){
        if(col[v] != -1) continue;
        col[v] = !color;
        if(!color){
            vec(ll) next;
            for(ll vv : g[v]){
                if(col[vv] == -1) col[vv] = color, next.push_back(vv);
            }
            for(ll vv : next) dfs(vv, g, col, n, color);
        }
    }
}

void sol(){
    ll n, m;
    cin >> n >> m;
    vec(vec(ll)) g(n + 1);
    vec(ll) col(n + 1, -1);
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    col[1] = 1;
    for(ll v : g[1]) col[v] = 0; 
    for(ll v : g[1]) dfs(v, g, col, n, 0);  
    bool ans = 1;
    vec(ll) trace;
    lp(i, 1, n){
        if(col[i] == 1) trace.push_back(i);
        else if(col[i] == -1) ans = 0;
    }
    if(ans){
        cout << YES << trace.size() << '\n';
        for(ll i : trace) cout << i << ' ';
        cout << '\n';
    }
    else cout << NO;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}