#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

string s;
ll qr;

struct Node{
    ll opt, open, close;
    Node(ll opt, ll open, ll close){
        this -> opt = opt;
        this -> open = open;
        this -> close = close;
    }
    Node(){
        this -> opt = this -> open = this -> close = 0;
    }
};

Node operator+(const Node &x, const Node &y){
    Node res = Node();
    ll tmp = min(x.open, y.close);
    res.opt = x.opt + y.opt + 2 * tmp;
    res.open = x.open + y.open - tmp;
    res.close = x.close + y.close - tmp;
    return res;
}

struct ST{
    vec(Node) st;
    ll n;
    ST(ll n){
        this -> n = n;
        st.resize(4 * n + 1);
    }
    void build(ll id, ll l, ll r){
        if(l == r){
            if(s[l] == '(') this -> st[id] = Node(0, 1, 0);
            else this -> st[id] = Node(0, 0, 1);
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build((id << 1) | 1, mid + 1, r);
        st[id] = st[id << 1] + st[(id << 1) | 1];
    }
    Node query(ll id, ll l, ll r, ll u, ll v){
        if(r < u || v < l) return Node();
        if(u <= l && r <= v) return st[id];
        ll mid = (l + r) >> 1;
        return query(id << 1, l, mid, u, v) + query((id << 1) | 1, mid + 1, r, u, v);
    }
    Node query(ll u, ll v){
        return query(1, 0, n - 1, u, v);
    }
    void build(){
        build(1, 0, n - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> s >> qr;
    ST segtree = ST(s.size());
    segtree.build();
    while(qr--){
        ll l, r;
        cin >> l >> r;
        Node res = segtree.query(l - 1, r - 1);
        cout << res.opt << '\n';
    }
}