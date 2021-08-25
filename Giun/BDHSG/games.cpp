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

cll mxn = 1e3 + 7;
ll n, m, s, t, a, b;
vec(pp(ll, ll)) g[mxn];
vec(ll) d_a, d_b;

void dijkstra(ll r, vec(ll) &d){
    d.assign(n + 1, 1e17);
    d[r] = 0;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, r});
    while(q.size()){
        ll u = q.top().second, ru = q.top().first;
        q.pop();
        if(ru != d[u]) continue;
        for(pp(ll, ll) i : g[u]){
            ll v = i.first, uv = i.second;
            if(d[v] > ru + uv){
                d[v] = ru + uv;
                q.push({d[v], v});
            }
        }
    }
}

int main(){
    giuncute();
    cin >> n >> m >> s >> t >> a >> b;
    ll u, v, c;
    lp(i, 1, m){
        cin >> u >> v >> c;
        if((u == a && v == b) || (u == b && v == a)) continue;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    dijkstra(a, d_a); dijkstra(b, d_b);
    ll ans = min(d_a[s] + d_b[t], d_a[t] + d_b[s]);
    if(ans >= 1e17) cout << "-1";
    else cout << ans;
}