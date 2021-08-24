#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "lulut"
using namespace std;

struct node{
    ll t, d, p;
};

cll mxn = 103, mxd = 2e3 + 2;
ll n, dp[mxn][mxd] = {{0}}, dd = 0;
node a[mxn];

bool cmp(node &a, node &b){
    return a.d < b.d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].t >> a[i].d >> a[i].p;
        dd = max(dd, a[i].d);
    }
    sort(a + 1, a + 1 + n, cmp);
    lp(i, 1, n) lp(j, 1, dd){
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if(j < a[i].d && j - a[i].t >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].t] + a[i].p);
    }
    cout << dp[n][dd];
}
