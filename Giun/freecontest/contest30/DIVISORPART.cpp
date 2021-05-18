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

cll mxn = 1e6 + 7;
ll n, q, a[mxn];

struct segment{
    ll st[mxn * 4] = {0};
    void down(ll id){
        if(st[id] == -1) return;
        st[id << 1] = st[id];
        st[id << 1 | 1] = st[id];
        st[id] = -1;
    }
    void update(ll id, ll l, ll r, ll u, ll v, ll x){
        if(v < l || r < u) return;
        if(u <= l && r <= v){
            st[id] = x;
            return;
        }
        ll mid = (l + r) >> 1;
        down(id);
        update(id << 1, l, mid, u, v, x);
        update(id << 1 | 1, mid + 1, r, u, v, x);   
    }
    ll get(ll id, ll l, ll r, ll u){
        if(r < u || u < l) return 0;
        if(l == r){
            return st[id];
        }
        ll mid = (l + r) >> 1;
        down(id);
        return max(get(id << 1, l, mid, u), get(id << 1 | 1, mid + 1, r, u));
    }
    void update(ll u, ll v, ll x){
        update(1, 0, n + 1, u, v, x);
    }
    ll get(ll u){
        return get(1, 0, n + 1, u);
    }
};

// #define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> q;
    lp(i, 1, n) cin >> a[i];
    a[n + 1] = a[0] = 1e9 + 7;
    segment top, bottom;
    ll i = 1;
    lp(j, 2, n + 1){
        if(a[j] % a[j - 1]){
            top.update(i, j - 1, i);
            bottom.update(i, j - 1, j - 1);
            i = j;
        }
    }
    bottom.update(n + 1, n + 1, n + 1);
    top.update(n + 1, n + 1, n + 1);
    cerr << top.get(0);
    ll ch, x, y;
    lp(i, 1, q){
        cin >> ch;
        if(ch == 1){
            cin >> x >> y;
            a[x] = y;
            ll u = top.get(x - 1), v = bottom.get(x + 1);
            if(a[x] % a[x - 1] == 0 && a[x + 1] % a[x] == 0) top.update(u, v, u), bottom.update(u, v, v);
            else if(a[x] % a[x - 1] == 0){
                top.update(u, x, u);
                bottom.update(u, x, x);
                top.update(x + 1, v, x + 1);
                // bottom.update(x + 1, v, v);
            } else if(a[x + 1] % a[x] == 0){
                bottom.update(u, x - 1, x - 1);
                // top.update(u, x - 1, x - 1);
                top.update(x, v, x);
                bottom.update(x, v, v);
            } else{
                bottom.update(u, x - 1, x - 1);
                top.update(x + 1, v, x + 1);
                bottom.update(x, x, x);
                top.update(x, x, x);
            }
        } else{
            cin >> x;
            cout << top.get(x) << '\n';
        }
    }
}