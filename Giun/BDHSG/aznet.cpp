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

cll mxn = 1e4 + 7, mxm = 1e5 + 7;
ll n, m, a[mxn] = {0}, b[mxn] = {0};
pp(pp(ll, ll), ll) e[mxm];

struct dsu{
    ll p[mxn], sz[mxn];
    void init(){
        lp(i, 1, n) p[i] = i, sz[i] = 1;
    }
    ll get(ll u){
        if(p[u] == u) return u;
        return p[u] = get(p[u]);
    }
    bool join(ll u, ll v){
        u = get(u), v = get(v);
        if(u == v) return 0;
        if(sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        return 1;
    }
};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    dsu d1, d2;
    ll mxa = 0, mna = 0, mxb = 0, mnb = 0, mnsum = 1e18, cnta, cntb;
    EACHCASE{
        mxa = 0, mna = 0, mxb = 0, mnb = 0, mnsum = 1e18;
        cin >> n >> m;
        d1.init(); d2.init();
        lp(i, 1, n - 1) cin >> a[i];
        lp(i, 1, n - 1) cin >> b[i];
        lp(i, 1, m){cin >> e[i].first.first >> e[i].first.second >> e[i].second; --e[i].second;}
        
        lp(i, 1, m)
            if(!e[i].second) {if(d1.join(e[i].first.first, e[i].first.second)) ++mxa;}
            else if(d2.join(e[i].first.first, e[i].first.second)) ++mxb;
        mna = n - 1 - mxb, mnb = n - 1 - mxa;
        lp(i, mna, mxa) if(a[i] + b[n - 1 - i] < mnsum && mna <= i && i <= mxa && mnb <= n - 1 - i && n - 1 - i <= mxb) mnsum = a[i] + b[n - 1 - i], cnta = i;
        cntb = n - 1 - cnta;
        d1.init();
        lp(i, 1, m) if(cnta && !e[i].second){
            if(!d2.join(e[i].first.first, e[i].first.second)) continue;
            d1.join(e[i].first.first, e[i].first.second);
            cout << i << ' ';
            --cnta;
        }
        lp(i, 1, m) if(cnta && !e[i].second) if(d1.join(e[i].first.first, e[i].first.second)) cout << i << ' ', --cnta;
        lp(i, 1, m) if(cntb && e[i].second) if(d1.join(e[i].first.first, e[i].first.second)) cout << i << ' ', --cntb;
        // cerr << cnta << ' ' << cntb << '\n';
        cout << '\n';
    }
}