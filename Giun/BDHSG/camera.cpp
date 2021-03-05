#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
// #define Fname "f"
#define Fname "camera"
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

cll mxn = 1e4 + 7;
ll n, m, numNode[mxn], p[mxn];
vec(pp(ll, pp(ll, ll))) E;

inline ll Get(ll u){
    if(p[u] == u) return u;
    return p[u] = Get(p[u]);
}

inline bool join(ll u, ll v){
    u = Get(u), v = Get(v);
    if(u == v) return 0;
    if(numNode[u] < numNode[v]) swap(u, v);
    numNode[u] += numNode[v];
    p[v] = u;
    return 1;
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
        E.push_back({w, {u, v}});
    }
    ll ans = 0;
    sort(E.begin(), E.end(), greater<pp(ll, pp(ll, ll))>());
    lp(i, 1, n) numNode[i] = 1, p[i] = i;
    for(auto &i : E){
        if(!join(i.second.first, i.second.second))
            ans += i.first;
    }   
    cout << ans;
}