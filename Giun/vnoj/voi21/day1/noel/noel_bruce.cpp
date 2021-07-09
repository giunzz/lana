#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "noel"

cll mxn = 1e3 + 7;
ll n, d, a[mxn], dp[mxn][mxn] = {{{0}}}, ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".ans", "w", stdout);
    cin >> n >> d;
    lp(i, 1, 2 * n) cin >> a[i];
    lp(i, 1, 2 * n) lp(j, i + 1, 2 * n){
        ll &cur = dp[i][j];
        cur = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        if(abs(a[i] - a[j]) <= d) cur = max(cur, dp[i - 1][j - 1] + 1);
        ans = max(ans, cur);
    }
    cout << ans;
}
