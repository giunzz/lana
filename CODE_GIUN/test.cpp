#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "giun"
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

cll mxn = 1e5 + 7;
ll n, q, a[mxn];

struct SEGMENT1{
    ll st[4 * mxn] = {0};
    void update(ll id, ll l, ll r, ll u){
        if(r < u || l > u) return;
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
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        ll mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
    void update(ll u){
        update(1, 1, n, u);
    }
    ll get(ll r){
        return get(1, 1, n, 1, r);
    }
    ll get_left(ll group){
        ll l = 1, r = n, res = -1;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(get(mid) >= group){
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return res;
    }
    ll get_right(ll group){
        ll l = 1, r = n, res = -1;
        while(l <= r){
            ll mid = (l + r) >> 1, tmp;
            if(get(mid) <= group){
                res = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return res;
    }
};

struct node{
    ll size, max;
};

struct SEGMENT2{
    node st[4 * mxn];
    void build(ll id, ll l, ll r){
        if(l == r){
            st[id].size = 1;
            st[id].max = a[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id].max = max(st[id << 1].max, st[id << 1 | 1].max);
        st[id].size = st[id << 1].size + st[id << 1 | 1].size;
    }
    ll erase(ll id, ll l, ll r, ll h){
        if(l == r){
            st[id].size = 0;
            st[id].max = -1;
            return l;
        }
        ll mid = (l + r) >> 1, pos;
        // l -> mid, mid + 1 -> r
        // st[id].size 
        if(st[id << 1].size < h) pos = erase(id << 1 | 1, mid + 1, r, h - st[id << 1].size);
        else pos = erase(id << 1, l, mid, h);
        st[id].size = st[id << 1].size + st[id << 1 | 1].size;
        st[id].max = max(st[id << 1].max, st[id << 1 | 1].max);
        return pos;
    }
    ll get_max(ll id, ll l, ll r, ll u, ll v){
        if(v < l || r < u) return -1;
        if(u <= l && r <= v) return st[id].max;
        ll mid = (l + r) >> 1;
        return max(get_max(id << 1, l, mid, u, v), get_max(id << 1 | 1, mid + 1, r, u, v));
    }
    void build(){
        build(1, 1, n);
    }
    ll erase(ll h){
        return erase(1, 1, n, h);
    }
    ll get_max(ll u, ll v){
        if(u < 0 || v < 0) return -1; 
        return get_max(1, 1, n, u, v);
    }
};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    cerr << 1;
    // SEGMENT1 tree1;
    // SEGMENT2 tree2;
    // tree2.build();
    // cin >> q;
    // char c;
    // ll x, y;
    // while(q--){
    //     cin >> c;
    //     if(c == 'S'){
    //         cin >> x;
    //         tree1.update(tree2.erase(x));
    //     } else{
    //         cin >> x >> y;
    //         if(x < 0) x = 0;
    //         if(y > n) y = n;
    //         ll ans = tree2.get_max(tree1.get_left(x), tree1.get_right(y)); 
    //         if(ans != -1) cout << ans << '\n';
    //         else cout << "NONE\n";
    //     }
    // }
}