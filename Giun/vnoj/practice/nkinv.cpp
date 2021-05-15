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

cll mxn = 6e4 + 2;
ll n, a[mxn];

struct ST{
    ll st[4 * mxn] = {0};
    inline ll update(ll id, ll l, ll r, ll u){
        if(u < l || u > r) return st[id];
        if(l == r) return ++st[id];
        ll mid = (l + r) >> 1;
        return st[id] = update(id << 1, l, mid, u) + update((id << 1) + 1, mid + 1, r, u);
    }
    inline ll get(ll id, ll l, ll r, ll u, ll v){
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        ll mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get((id << 1) + 1, mid + 1, r, u, v);
    } 
    void update(ll u){
        update(1, 1, 6e4, u);
    }
    ll get(ll u, ll v){
        return get(1, 1, 6e4, u, v);
    }
};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ST seg;
    cin >> n;
    ll ans = 0, ma = 0;
    lp(i, 1, n){
        cin >> a[i];
        if(ma > a[i]) ans += seg.get(a[i] + 1, ma);
        seg.update(a[i]);
        ma = max(ma, a[i]);
    }
    cout << ans;
}