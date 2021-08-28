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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e5 + 4;
ll n, m, k, dp[20][mxn];
vec(ll) p[2], sub[mxn][2];
pp(ll, ll) path[mxn];
vec(pp(ll, ll)) g[mxn], ng[mxn], nng[mxn];

void init_dijk(){
    // unordered_map<ll, unordered_map<ll, bool>> e;
    vec(bool) d(n + 1, 0);
    priority_queue<pp(pp(ll, ll), pp(ll, ll)), vec(pp(pp(ll, ll), pp(ll, ll))), greater<pp(pp(ll, ll), pp(ll, ll))>> q;
    lp(i, 1, n) dp[1][i] = 1e18;
    dp[1][path[1].first] = 0;
    q.push({{0, 0}, {0, path[1].first}});
    while(q.size()){
        ll u = q.top().second.second, cu = q.top().first.first, pu = q.top().second.first, puu = q.top().first.second;
        q.pop();
        if(cu != dp[1][u]) continue;
        if(pu) ng[u].push_back({pu, puu});
        if(d[u]) continue;
        d[u] = 1;
        for(pp(ll, ll) v : g[u]){
            if(cu + v.second <= dp[1][v.first]){
                dp[1][v.first] = cu + v.second;
                q.push({{dp[1][v.first], v.second}, {u, v.first}});
            }
        }
    }   
}

void dijk(ll type, ll r, ll tt){
    lp(i, 1, n) nng[i].clear();
    vec(bool) d(n + 1, 0);
    priority_queue<pp(pp(ll, ll), pp(ll, ll)), vec(pp(pp(ll, ll), pp(ll, ll))), greater<pp(pp(ll, ll), pp(ll, ll))>> q;
    lp(i, 1, n) dp[tt][i] = 1e18;
    dp[tt][path[1].first] = 0;
    q.push({{0, 0}, {0, path[tt].first}});
    while(q.size()){
        ll u = q.top().second.second, cu = q.top().first.first, pu = q.top().second.first, puu = q.top().first.second;
        q.pop();
        if(cu != dp[tt][u]) continue;
        if(pu) nng[u].push_back({pu, puu});
        if(d[u]) continue;
        d[u] = 1;
        for(pp(ll, ll) v : g[u]){
            if(cu + v.second <= dp[tt][v.first]){
                dp[tt][v.first] = cu + v.second;
                q.push({{dp[tt][v.first], v.second}, {u, v.first}});
            }
        }
    }
    queue<ll> qq;
    qq.push(path[tt].second);
    while(qq.size()){
        ll u = qq.front();
        qq.pop();
        for(pp(ll, ll) v : nng[u]){
            sub[v.first][type].push_back(tt);
            qq.push(v.first);
        }
    }
}

void sol(){
    // ngay mai code tiep
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    cin >> path[1].first >> path[1].second;
    lp(i, 2, k){
        ll type;
        cin >> type >> path[i].first >> path[i].second;
        p[type].push_back(i);
    }
    init_dijk();
}