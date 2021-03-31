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

cll MOD = 1e9 + 7, mxn = 502, mxm = 2e4 + 3;
ll n, m, dp[mxn][mxn] = {{0}}, rta[mxm], cnt[mxn][mxn] = {{0}}; // i -> i + 1 -> j
vec(point) g, p;
bool onseg[mxn][mxn] = {{0}};

void inp(){
    cin >> n >> m;
    lp(i, 1, n){
        ll u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }
    lp(i, 0, m - 1){
        ll u, v;
        cin >> u >> v;
        p.push_back({u, v});
        rta[i] = 1;
    }
}

inline point getvector(point const &a, point const &b){
    return {b.X - a.X, b.Y - a.Y};
}

inline ll area(point a, point b, point c){
    point ba = getvector(b, a), bc = getvector(b, c);
    return ba.X * bc.Y - ba.Y * bc.X;
}

inline bool ccw(point a, point b, point c){
    return area(a, b, c) > 0;
}

inline bool straight(point a, point b, point c){
    return area(a, b, c) == 0;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    inp();
    lp(i, 0, n - 1){
        lp(j, 0, m - 1){
            while(rta[j] < n && !ccw(g[i], p[j], g[rta[j]])) ++rta[j];
            ++cnt[i][rta[j]];
            if(straight(g[i], p[j], g[rta[j] - 1])) onseg[i][rta[j] - 1] = 1;
        }
        lp(j, i + 1, n - 1) cnt[i][j] += cnt[i][j - 1];
    }
    lp(i, 0, n - 1) dp[i][i] = dp[i][i + 1] = 1;
    lp(dis, 2, n - 1) lp(i, 0, n - 1){
        ll j = i + dis;
        if(j >= n) break;
        if(straight(g[i], g[i + 1], g[j])) dp[i][j] = 1;
        else lp(k, i + 1, j - 1) if((~(cnt[i][j] - cnt[i][k] - cnt[k][j]) & 1) && !(onseg[i][k] | onseg[i][j] | onseg[k][j])) (dp[i][j] += (dp[i][k] * dp[k][j]) % MOD) %= MOD;
    }
    cout << dp[0][n - 1];
}