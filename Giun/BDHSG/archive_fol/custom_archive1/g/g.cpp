#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "g"
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

struct Segment{
    vec(ll) st;
    ll n;
    Segment(ll _n){
        n = _n;
        st.assign(4 * _n + 7, LLONG_MAX);
    }
    void update(ll id, ll l, ll r, ll u, ll v, ll val){
        if(l > v || r < u) return;
        if(l == r){
            st[id] = min(st[id], val);
            return;
        }
        ll mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update((id << 1) | 1, mid + 1, r, u, v, val);
        st[id] = min(st[id << 1], st[(id << 1) | 1]);
    }
    void update(ll u, ll val){
        update(1, 1, n, u, u, val);
    }
    ll get(ll id, ll l, ll r, ll u, ll v){
        if(l > v || r < u) return LLONG_MAX;
        if(u <= l && r <= v) return st[id];
        ll mid = (l + r) >> 1;
        return min(get(id << 1, l, mid, u, v), get((id << 1) | 1, mid + 1, r, u, v));
    }
    ll get(ll u, ll v){
        return get(1, 1, n, u, v);
    }
};

cll maxn = 1e5 + 7;
ll n, k, h[maxn], s[maxn], f[maxn] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    Segment tree(1e5 + 1);
    lp(i, 1, n) cin >> h[i] >> s[i];
    f[1] = h[1];
    tree.update(s[1], f[1]);
    lp(i, 2, n){
        ll x1 = s[i] - k, x2 = s[i] + k;
        if(x1 <= 0) x1 = 1;
        if(x2 > 1e5) x2 = 1e5;
        ll tmp = tree.get(x1, x2);
        f[i] = tmp + h[i];
        tree.update(s[i], f[i]);
    }
    // lp(i, 1, n) cerr << f[i] << ' ';
    cout << f[n];
}