#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "tienphat"
using namespace std;

cll mxn = 3e3 + 6;
ll n, dp[mxn];
pp(ll, ll) a[mxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    lp(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    dp[n + 1] = 0;
    lpd(i, n, 1){
        ll totdis = a[i].second;
        dp[i] = 1e18;
        lp(j, i + 1, n + 1){
            dp[i] = min(dp[i], dp[j] + totdis);
            totdis += a[j].first - a[i].first;
        }
    }
    cout << dp[1];
}
