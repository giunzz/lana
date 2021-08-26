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

cll mxn = 4e5 + 4;
ll a[mxn] = {0};

struct segment{
    ll st[mxn] = {0}, lazy[mxn] = {0}, m;
    segment(ll _m) : m(_m) {} 
    void down(ll id){
        st[id << 1] += lazy[id];
        st[id << 1 | 1] += lazy[id];
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
    void update(ll id, ll l, ll r, ll u, ll v, ll val){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            lazy[id] += val;
            st[id] += val;
            return;
        }
        ll mid = (l + r) >> 1;
        down(id);
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v){
        if(r < u || v < l) return -1e18;
        if(u <= l && r <= v){
            return st[id];
        }
        ll mid = (l + r) >> 1;
        down(id);
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
    void update(ll pos, ll val){
        update(1, 1, m, 1, pos, val);
    }
    ll get(ll pos){
        return get(1, 1, m, pos, m);
    }
    ll get_id(){
        ll l = 1, r = m, res = 0;
        while(l <= r){
            ll mid = (l + r) >> 1;
            // cerr << l << ' ' << r << ' ' << mid << ' ' << get(mid) << '\n';
            if(get(mid) >= 1) res = mid, l = mid + 1;
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};  

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs, x, pos, m;
    cin >> m;
    segment tree(m);
    lp(i, 1, m){
        cin >> pos >> cs;
        if(cs){
            cin >> x;
            a[pos] = x;
            tree.update(pos, 1);
        } else{
            tree.update(pos, -1);
        }
        // if(i == 3){
        //     cerr << tree.get_id() << "\n---------\n";

        //     cerr << tree.get_id() << "\n---------\n";
        // }
        ll val = a[tree.get_id()];
        // if(i == 1) cerr << tree.get(2) << ' ' << tree.get(1);
        cout << (val ? val : -1) << '\n';
    }
}