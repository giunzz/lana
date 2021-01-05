#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

struct Segment{
    ll n;
    vec(pp(ll, ll)) f;
    Segment(ll n): n(n), f(4 * (n + 1), make_pair(LLONG_MAX, 0)) {}
    void set(ll id, ll l, ll r, ll u, ll val){
        if(l > u || r < u) return;
        if(l == r){
            f[id] = {val, u};
            return;
        }
        ll mid = (l + r) >> 1;
        set(id << 1, l, mid, u, val);
        set(id << 1 | 1, mid + 1, r, u, val);
        f[id] = min(f[id << 1], f[id << 1 | 1]);
    }
    void set(ll i, ll val){set(1, 1, n, i, val);}
    pp(ll, ll) get(ll id, ll l, ll r, ll u, ll v){
        if(l > v || r < u) return make_pair(LLONG_MAX, 0);
        if(u <= l && r <= v) return f[id];
        ll mid = (l + r) >> 1;
        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
    pp(ll, ll) get(ll i) {return get(1, 1, n, 1, i);}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    cin >> cs;
    while(cs--){
        ll n, m, ans = 0;
        cin >> n >> m;
        vec(ll) a(n + 1), b(m + 1);
        Segment st(m);
        lp(i, 1, n) cin >> a[i];
        lp(i, 1, m){
            cin >> b[i];
            st.set(i, b[i]);
        }
        a[0] = 0;
        sort(a.begin() + 1, a.end(), [&](ll &x, ll &y){
            return b[x] > b[y];
        });
        lp(i, 1, n){
            pp(ll, ll) tmp = st.get(a[i]);
            if(tmp.first < b[a[i]]){
                ans += tmp.first;
                st.set(tmp.second, LLONG_MAX);
            }
            else ans += b[a[i]];
        }
        cout << ans << '\n';
    }
}