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

struct segment{
    ll n;
    vec(ll) st;
    segment(ll _n){
        n = _n;
        st.assign(4 * n + 1, 0);
    }
    void update(ll id, ll l, ll r, ll u){
        if(u < l || u > r) return;
        if(l == r){
            st[id] = 1;
            return;
        }
        ll mid = (l + r) >> 1;
        update(id << 1, l, mid, u);
        update(id << 1 | 1, mid + 1, r, u);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v){
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        ll mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
    void update(ll u){
        update(1, 1, n, u);
    }
    ll get(ll u){
        return get(1, 1, n, 0, u);
    }
};

struct fenwick{
    ll n;
    vec(ll) st;
    fenwick(ll _n) : n(_n), st(n + 3, 0) {}
    void update(ll u, ll val){
        for(; u <= n; u += u & (-u)) st[u] += val;
    }
    ll get(ll u){
        ll ans = 0;
        for(; u >= 1; u -= u & (-u)) ans += st[u];
        return ans;
    }
};

cll mxn = 1e5 + 3;
ll n, k, a[mxn], s[mxn] = {0};
vec(ll) nen;

vec(ll) comp(){
    set<ll> ss;
    lp(i, 1, n) ss.insert(s[i]);
    return vec(ll)(ss.begin(), ss.end());
}

bool check(ll val, fenwick &ST){
    ll ans = 0;
    lp(i, 1, n){
        ll v = upper_bound(nen.begin(), nen.end(), s[i] - val) - nen.begin();
        ans += ST.get(v);
        if(s[i] >= val) ++ans;
        // if(!val) cerr << s[i] << ' ' << ST.get();
        ST.update(lower_bound(nen.begin(), nen.end(), s[i]) - nen.begin() + 1, 1);
    }
    lp(i, 1, n) ST.update(lower_bound(nen.begin(), nen.end(), s[i]) - nen.begin() + 1, -1);
    // cerr << ans << ' ' << val << '\n';
    return ans >= k;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    lp(i, 1, n){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    nen = comp();
    fenwick ST(nen.size());
    // lp(i, 1, n) ST.update(lower_bound(nen.begin(), nen.end(), s[i]) - nen.begin() + 1);
    ll l = -1e17, r = 1e17, ans;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid, ST)) ans = mid, l = mid + 1; // sl >= k
        else r = mid - 1;
    }
    cout << ans;
}