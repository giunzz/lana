#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "wires"
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

#define point pp(ll, ll)
#define x first
#define y second

cll mxn = 1e3 + 7;
ll n, numNode[mxn], pa[mxn];
vec(pp(ll, ll)) p;
vec(pp(ll, pp(ll, ll))) E;

inline ll dist(point &u, point &v){
    return __gcd(abs(u.x - v.x), abs(u.y - v.y)) - 1;
}

inline ll Get(ll u){
    if(pa[u] == u) return u;
    return pa[u] = Get(pa[u]);
}

inline bool join(ll u, ll v){
    u = Get(u), v = Get(v);
    if(u == v) return 0;
    if(numNode[u] < numNode[v]) swap(u, v);
    numNode[u] += numNode[v];
    pa[v] = u;
    return 1;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        ll u, v; 
        cin >> u >> v;
        p.emplace_back(u, v);
    }
    lp(i, 0, p.size() - 1) lp(j, i + 1, p.size() - 1){
        ll dis = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) - 1 - dist(p[i], p[j]);
        E.push_back({dis, {i + 1, j + 1}});
    }
    sort(E.begin(), E.end());
    ll cnt = 0, ans = 0;
    vec(pp(ll, ll)) res;
    lp(i, 1, n) pa[i] = i, numNode[i] = 1;
    for(auto &i : E){
        if(cnt == n - 1) break;
        if(join(i.second.first, i.second.second)) ++cnt, ans += i.first, res.push_back(i.second);
    }
    cout << ans << '\n';
    for(auto &i : res) cout << i.first << ' ' << i.second << '\n';
}