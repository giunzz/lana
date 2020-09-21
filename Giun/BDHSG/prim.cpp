#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

cll maxn = 1e5 + 7;
ll n, m;
vec(pp(ll, ll)) g[maxn];

void init(){
    ll u, v, w;
    lp(i, 1, m){
        cin >> u >>v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
}

#define fi first
#define se second

bool c[maxn] = {0};

ll prim(){
    ll tw = 0;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, 1});
    ll u, du;
    while(q.size()){
        u = q.top().se;
        du = q.top().fi;
        q.pop();
        if(c[u]) continue;
        c[u] = 1;
        tw += du;
        for(pp(ll, ll) v : g[u]){
            q.push(v);
        }
    }
    return tw;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("f"".inp", "r", stdin);
    // freopen("f"".out", "w", stdout);
    cin >> n >> m;
    init();
    cout << prim();
}