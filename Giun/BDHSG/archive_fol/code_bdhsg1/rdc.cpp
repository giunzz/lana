#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "rdc"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7, maxk = maxn;
ll n, m, k, f[maxn][maxn] = {{0}};
pp(ll, ll) a[maxk];
vec(pp(ll, ll)) g[maxn], e;

#define x first 
#define y second

void init(){
    ll u, v, c;
    lp(i, 1, m){
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
        f[u][v] = f[v][u] = c;
        e.push_back({u, v});
    }
    lp(i, 1, k) cin >> a[i].x >> a[i].y;
}

void dijkstra(ll const &r, ll const &stt){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) f[stt][i] = LLONG_MAX;
    f[stt][r] = 0;
    q.push({0, r});
    while(q.size()){
        ll u = q.top().second;
        ll cu = q.top().first;
        q.pop();
        if(f[stt][u] != cu) continue;
        for(pp(ll, ll) &v : g[u]){
            if(f[stt][v.second] > f[stt][u] + v.first){
                f[stt][v.second] = f[stt][u] + v.first;
                q.push({f[stt][v.second], v.second});
            }
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> k;
    init();
    ll ans = LLONG_MAX;
    lp(i, 1, n){
        dijkstra(i, i);
    }
    for(pp(ll, ll) &E : e){
        ll sum = 0;
        lp(i, 1, k){
            sum += min(f[a[i].x][a[i].y], min(f[a[i].x][E.x] + f[E.y][a[i].y], f[a[i].x][E.y] + f[E.x][a[i].y]));
        }
        ans = min(sum, ans);
    }
    cout << ans;
}