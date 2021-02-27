// #include <bits/stdc++.h>
#include <cstdio>
#include <string>
#define ii int
#define ll int
#define cii const int
#define cll const ll
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
using namespace std;
const string tenfile = "sum";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

struct node{
    ll lazy = 0, dg[10] = {0};
};

void inc(ll *d, ll val){
    static int tmp[10];
    lp(i, 0, 9) tmp[i] = d[i];
    lp(i, 0, 9) d[(i + val) % 10] = tmp[i];
}

cll maxn = 25e4;
string s;
node st[maxn * 4 + 7];

struct segment{
    ll n;
    segment(ll _n){
        this -> n = _n;
    }
    void build(ll id, ll l, ll r){
        if(l == r){
            st[id].dg[s[l] - '0'] = 1;
            return;
        } 
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        lp(i, 0, 9) st[id].dg[i] = st[id << 1].dg[i] + st[id << 1 | 1].dg[i];
    }
    void down(ll id){
        st[id << 1].lazy += st[id].lazy;
        st[id << 1 | 1].lazy += st[id].lazy;
        
        inc(st[id << 1].dg, st[id].lazy);
        inc(st[id << 1 | 1].dg, st[id].lazy);
        st[id].lazy = 0;
    }
    void update(ll id, ll l, ll r, ll u, ll v, ll val){
        if(l > v || r < u) return;
        if(u <= l && r <= v){
            st[id].lazy += val;
            inc(st[id].dg, val);
            return;
        }
        ll mid = (l + r) >> 1;
        down(id);
        
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        lp(i, 0, 9) st[id].dg[i] = st[id << 1].dg[i] + st[id << 1 | 1].dg[i];
    }
    ll get(ll id, ll l, ll r, ll u, ll v){
        if(l > v || r < u) return 0;
        if(u <= l && r <= v){
            ll sum = 0;
            lp(i, 0, 9) sum += st[id].dg[i] * i;
            return sum; 
        }
        ll mid = (l + r) >> 1;
        down(id);

        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
    void update(ll u, ll v, ll val){
        update(1, 1, n, u, v, val);
    }
    ll get(ll u, ll v){
        return get(1, 1, n, u, v);
    }
    void build(){
        build(1, 1, n);
    }
};

int main(){
    file;
    ll n, m;
    scanf("%d %d", &n, &m);
    char c = ' ';
    while(c == ' ') scanf("%c", &c);
    lp(i, 1, n){
        scanf("%c", &c);
        s.push_back(c);
    }
    s = '0' + s;
    segment st(n);
    st.build();
    lp(i, 1, m){
        ll u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", st.get(u, v));
        st.update(u, v, 1);
    }
}