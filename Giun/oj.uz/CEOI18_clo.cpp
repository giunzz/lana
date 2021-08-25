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

cll mxn = 2e3 + 1;
ll n, m, dp[2][mxn * 50] = {{0}}, ans = 0;

struct obj{
    ll c, f, v;
    bool type;
    obj(ll _c, ll _f, ll _v, bool _type) : c(_c), f(_f), v(_v), type(_type) {}
    obj(){}
}a[mxn * 2];

bool cpr(obj &u, obj &v){
    return u.f != v.f ? u.f > v.f : u.type < v.type;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].c >> a[i].f >> a[i].v;
        a[i].type = 0;
    }
    cin >> m;
    lp(i, n + 1, n + m){
        cin >> a[i].c >> a[i].f >> a[i].v;
        a[i].type = 1;
    }
    sort(a + 1, a + n + m + 1, cpr);
    lp(i, 1, n * 50) dp[0][i] = -1e18;
    lp(i, 1, n + m) lp(j, 0, n * 50){
        dp[i & 1][j] = dp[~i & 1][j];
        if(a[i].type){ // rent
            if(j + a[i].c <= n * 50) 
                dp[i & 1][j] = max(dp[i & 1][j], dp[~i & 1][j + a[i].c] + a[i].v);
        } else{
            if(j - a[i].c >= 0) 
                dp[i & 1][j] = max(dp[i & 1][j], dp[~i & 1][j - a[i].c] - a[i].v);
        }
        ans = max(ans, dp[i & 1][j]);
    }
    cout << ans;
}