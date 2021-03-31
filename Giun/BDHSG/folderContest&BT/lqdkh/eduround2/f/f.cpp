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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define point pp(ll, ll)
#define X first
#define Y second

cll MOD = 1e9 + 7, mxn = 502;
ll n, m, dp[mxn][mxn] = {{0}};
vec(point) g, p;

void xoay(){
    vec(point) tmp;
    ll mi = 1e8, pos;
    lp(i, 0, n - 1)
        if(g[i].X < mi) mi = g[i].X, pos = i;
    lp(i, pos, n - 1) tmp.push_back(g[i]);
    lp(i, 0, pos - 1) tmp.push_back(g[i]);
    g = tmp;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n){
        ll u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        p.push_back({u, v});
    }
    xoay();
    sort(p.begin(), p.end());
    lp(dis, 1, n - 1){
        ll u = 0, v = 0;
        lp(i, 0, n - 1){
            ll j = i + dis;
            if(j >= n) break;
            
            lp(k, )
        }
    }
}