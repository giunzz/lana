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

cll mxn = 2e5 + 7;
ll n, a[mxn], mo[mxn] = {0}, cur = 0, good[mxn] = {0}, visit[mxn] = {0}, cnt, ans[mxn] = {0}, h[mxn] = {0};
vec(ll) g[mxn], need[mxn];
queue<ll> q;

void init(){
    mo[1] = 1;
    lp(i, 1, 2e5) for(ll j = i << 1; j <= 2e5; j += i) mo[j] -= mo[i];
}

ll bfs(ll r){
    cnt = 1;
    q.push(r);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : g[u]){
            if(good[a[v]] == cur && visit[v] != cur){
                visit[v] = cur;
                ++cnt;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    cin >> n;
    lp(i, 1, n) cin >> a[i], need[a[i]].push_back(i);
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll tmp;
    lpd(i, 2e5, 1){
        ++cur;
        for(ll j = i; j <= 2e5; j += i) good[j] = cur;
        for(ll j = i; j <= 2e5; j += i) for(ll u : need[j]){
            if(visit[u] == cur) continue;
            visit[u] = cur;
            tmp = bfs(u);
            h[i] += tmp * (tmp + 1) / 2; // (tmp ^ 2 - tmp + 2tmp) / 2 = (tmp ^ 2 + tmp) / 2
        }
        // ans[x] = sigma mo[i] * h[i * x]
        for(ll j = 1, x = i; x <= 2e5; ++j, x += i){
            ans[i] += mo[j] * h[x];
        }
    }
    lp(i, 1, 2e5) if(ans[i]) cout << i << ' ' << ans[i] << '\n';
}


// second algo
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

cll mxn = 2e5 + 7;
ll n, a[mxn], sz[mxn], p[mxn], cur, res[mxn] = {0};
vec(pp(ll, ll)) e[mxn];
vec(ll) g[mxn];

ll Get(ll u){
    return p[u] = (p[u] == u ? u : Get(p[u]));
}

void join(ll u, ll v){
    u = Get(u), v = Get(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    cur -= (sz[u] * (sz[u] + 1) / 2 + sz[v] * (sz[v] + 1) / 2);
    sz[u] += sz[v], p[v] = u;
    cur += sz[u] * (sz[u] + 1) / 2;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i], g[a[i]].push_back(i);
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        e[__gcd(a[u], a[v])].push_back({u, v});
    }
    lpd(i, 2e5, 1){
        cur = 0;
        for(ll j = i; j <= 2e5; j += i){
            for(ll v : g[j]) sz[v] = 1, p[v] = v, ++cur;
            res[i] -= res[j];
        }
        for(ll j = i; j <= 2e5; j += i)
            for(pp(ll, ll) ee : e[j]) join(ee.first, ee.second);
        res[i] += cur;
    }
    lp(i, 1, 2e5) if(res[i]) cout << i << ' ' << res[i] << '\n';
}