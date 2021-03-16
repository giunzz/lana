#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast")
ll n, k,  x[30]  ,  ans ;

inline bool check(ll dis)
{
    vector<ll> dp(n + 1, 0);
    ll j = 1, res = 0;
    for(ll i = 1; i <= n; i++)
    {
        while(x[i] - x[j + 1] >= dis) ++j;
        if(x[i] - x[j] >= dis) dp[i] = dp[j] + 1;
        else dp[i] = 1;
        res = max(res, dp[i]);
    }
    return res >= c;
}
void cnp ( )
{
    int l = 1  , r = 1000;
    while ( l <= r)
    {
        ll mid = (l+r)/2;
        if (check(mid) == true)
        {
            ans = mid ;
            r = mid-1;
        }
        else l = mid+1;
    }
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    cnp();
    cout << ans;
}