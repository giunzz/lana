#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "transpo"
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

cll maxn = 1e5 + 7;
ll n, m, numnode[maxn], p[maxn];
vec(pp(ll, pp(ll, ll))) edge;
vec(pp(ll, ll)) g[maxn];

ll Get(ll u){
    if(p[u] == u) return u;
    return p[u] = Get(p[u]);
}

bool join(ll u, ll v){
    u = Get(u), v = Get(v);
    if(u == v) return 0;
    if(numnode[u] < numnode[v]) swap(u, v);
    numnode[u] += numnode[v];
    p[v] = u;
    return 1;
}

ll dfs(ll u, ll p){
    ll path = LLONG_MAX;
    for(pp(ll, ll) v : g[u]){
        if(v.first == p) continue;
        if(v.first == n) return v.second;
        ll tmp = dfs(v.first, u);
        if(tmp) path = min(tmp, v.second);
    }
    if(path == LLONG_MAX) path = 0;
    return path;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end(), greater<pp(ll, pp(ll, ll))>());
    ll cnt = 0;
    lp(i, 1, n) numnode[i] = 1, p[i] = i;
    for(pp(ll, pp(ll, ll)) e : edge){
        if(join(e.second.first, e.second.second)){
            ++cnt;
            g[e.second.first].push_back({e.second.second, e.first});
            g[e.second.second].push_back({e.second.first, e.first});
            // cerr << e.second.first << ' ' << e.second.second << ' ' << e.first << '\n';
        }
        if(cnt == n - 1) break;
    }
    cout << dfs(1, -1);
}

// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "transpo"
// using namespace std;

// template <typename T> inline void Read(T &x){
//     x = 0; char c;
//     while(!isdigit(c = getchar()));
//     do
//     {
//         x = x * 10 + c - '0';
//     } while (isdigit(c = getchar()));
// }

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// cll maxn = 1e5 + 7;
// ll n, m, dp[maxn] = {0};
// vec(pp(ll, ll)) g[maxn];

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     cin >> n >> m;
//     lp(i, 1, m){
//         ll u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }
//     lp(i, 2, n) dp[i] = LLONG_MIN / 10;
//     priority_queue<pp(ll, ll)> pq;
//     dp[1] = LLONG_MAX;
//     pq.push({dp[1], 1});
//     while(pq.size()){
//         ll u = pq.top().second, cu = pq.top().first;
//         pq.pop();
//         if(dp[u] != cu) continue; 
//         for(pp(ll, ll) &v : g[u]){
//             ll nmin = min(dp[u], v.second);
//             if(nmin > dp[v.first]){
//                 dp[v.first] = nmin;
//                 pq.push({nmin, v.first});
//             }
//         }
//     }
//     cout << dp[n];
// }