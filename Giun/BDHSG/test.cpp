#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #pragma GCC optimize("Ofast")
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

template <typename T> inline void read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
    
}

template <typename T> inline void write(T x){
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

cll maxn = 5e3 + 7;
ll n, k, f[maxn];
pp(ll, ll) a[maxn];
vec(pp(ll, ll)) g[maxn];
vec(ll) gg[maxn];

#define c first
#define d second

#define fi first
#define se second.first.first
#define th second.first.second
#define fo second.second

void init(){
    ll u, v;
    lp(i, 1, k){
        read(u); read(v);
        // cin >> u >> v;
        gg[u].push_back({v});
        gg[v].push_back({u});
    }
}

ll dd[maxn] = {0};

void bfs(ll &r){
    memset(dd, -1, sizeof(dd));
    queue<ll> q;
    q.push(r);
    dd[r] = 0;
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll &v : gg[u]){
            if(dd[v] != -1) continue;
            dd[v] = dd[u] + 1;
            if(dd[v] > a[r].d) break;
            g[r].push_back({a[r].c, v});
            q.push(v);
        }
    }
}

void dijkstra(ll r){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> pq;
    pq.push({0, r});
    lp(i, 1, n) f[i] = LLONG_MAX;
    f[r] = 0;
    while(pq.size()){
        pp(ll, ll) u = pq.top();
        pq.pop();
        if(f[u.second] != u.first) continue;
        if(u.second == n) break;
        for(pp(ll, ll) &v : g[u.second]){
            ll tmp = u.first + v.first;
            if(tmp < f[v.second]) f[v.second] = tmp, pq.push({f[v.second], v.second});
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // OF();
    // cin >> n >> k;
    read(n); read(k);
    lp(i, 1, n){
        // cin >> a[i].c >> a[i].d;
        read(a[i].c); read(a[i].d);
    }
    init();
    lp(i, 1, n){
        bfs(i);
    }
    dijkstra(1);
    // cout << f[n];
    write(f[n]);
}