#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define out {ok = 0; break;}
#define no "NO\n"
#define yes "YES\n"

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    cin >> cs;
    while(cs--){
        ll n, k;
        cin >> n >> k;
        vec(pp(ll, ll)) dp(n + 1, make_pair(0, 0));
        vec(ll) a(n + 1);
        lp(i, 1, n) cin >> a[i];
        dp[1] = {a[1], a[1]};
        bool ok = 1;
        lp(i, 2, n){
            ll lo = a[i], hi = a[i] + k - 1;
            if(lo >= dp[i - 1].second + k || hi + k <= dp[i - 1].first) out;
            if(dp[i - 1].first >= lo + k) lo = dp[i - 1].first + 1 - k;
            if(dp[i - 1].second + k <= hi) hi = dp[i - 1].second + k - 1;
            if(lo > hi || lo > a[i] + k - 1 || hi < a[i]) out;
            dp[i] = {lo, hi};
        }
        if(dp[n].first != a[n]) ok = 0;
        if (ok) cout << yes;
        else cout << no;
    }
}