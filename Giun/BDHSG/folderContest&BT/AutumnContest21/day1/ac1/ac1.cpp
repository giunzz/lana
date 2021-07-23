#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "ac1"
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

cll mxn = 200;
string a, b, x;
ll n, change[mxn], trace[mxn], cost[mxn][mxn], f[mxn], d[mxn];
vec(ll) flow[mxn], V;

#define S 0
#define T mxn - 1

void pb(ll u, ll v){flow[u].push_back(v); flow[v].push_back(u); if(v != T) cost[u][v] = 1;}

void input(){
    V.clear();
    lp(i, S, T) flow[i].clear();
    memset(d, 0, sizeof d);
    memset(cost, 0, sizeof cost);
    cin >> a >> b >> x;
    a = '.' + a, b = '.' + b;
    for(char c : x) ++d[c];
    n = a.size();
    lp(i, 'A', 'Z') change[i] = i - 'A' + n, V.push_back(change[i]);
    V.push_back(S);
    lp(i, 1, n - 1){
        V.push_back(i);
        pb(S, i); pb(i, change[a[i]]);
        if(a[i] != b[i]) pb(i, change[b[i]]);
        if(d[a[i]]) pb(change[a[i]], T), cost[change[a[i]]][T] = d[a[i]], d[a[i]] = 0;
        if(d[b[i]]) pb(change[b[i]], T), cost[change[b[i]]][T] = d[b[i]], d[b[i]] = 0;
    }
    V.push_back(T);
}

ll bfs(){
    f[S] = 1e18, f[T] = 0;
    queue<ll> q;
    q.push(S);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : flow[u]) if(cost[u][v] && !trace[v]){
            trace[v] = u;
            f[v] = min(f[u], cost[u][v]);
            q.push(v);
        }
    }
    return f[T];
}

ll find_path(){
    for(ll u : V) trace[u] = 0;
    trace[S] = -1;
    return bfs();
}

void increase(ll c){
    ll v = T, u;
    while(~(u = trace[u]))
        cost[u][v] -= c, cost[v][u] += c;
}

ll max_flow(){
    ll c, res = 0;
    while(c = find_path()){
        res += c;
        increase(c);
    }
    return res;
}

void sol(){
    cout << (max_flow() == x.size() ? "YES\n" : "NO\n");
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{input(); sol();}
}