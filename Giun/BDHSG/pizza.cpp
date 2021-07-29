#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "pizza"
using namespace std;

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

cll mxm = 22, mxn = 102, mxtot = 12;
ll tot, r, m, n, dp[mxtot][mxm][mxn] = {{{0}}}, ans = 0;
pp(ll, ll) food[mxm];
pp(pp(ll, ll), ll) house[mxn];

ll dis(pp(ll, ll) &a, pp(ll, ll) &b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> tot >> r >> m;
    r *= r;
    lp(i, 1, m) cin >> food[i].first >> food[i].second;
    cin >> n;
    lp(i, 1, n) cin >> house[i].first.first >> house[i].first.second >> house[i].second;
    lp(i, 1, tot) lp(j, i, m) lp(k, 1, n){
        dp[i][j][k] = dp[i][j][k - 1];
        if(dis(food[j], house[k].first) <= r){
            lp(z, i - 1, j - 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][z][k - 1]);
            dp[i][j][k] += house[k].second;
        }
        else 
            lp(z, i - 1, j - 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][z][k]);
        if(i == tot) ans = max(ans, dp[i][j][k]);
    }
    cout << ans;
}