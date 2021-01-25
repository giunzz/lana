#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "attack"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, a[maxn], p[maxn], cnt[maxn];
vec(pp(ll, pp(ll, ll))) e;

ll Get(ll u){
    if(p[u] == u) return u;
    return p[u] = Get(p[u]);
}

bool join(ll u, ll v){
    u = Get(u), v = Get(v);
    if(u == v) return 0;
    p[v] = u;
    cnt[u] += cnt[v];
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n){cin >> a[i]; cnt[i] = 1; p[i] = i;}
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        ll w = a[u] + a[v];
        e.push_back({w, {u, v}});
    }
    sort(e.begin(), e.end(), greater<pp(ll, pp(ll, ll))>());
    ll ans = 0, cnt = 0;
    for(pp(ll, pp(ll, ll)) i : e){
        if(!join(i.second.first, i.second.second)) ans += i.first;
    }
    cout << ans;
}