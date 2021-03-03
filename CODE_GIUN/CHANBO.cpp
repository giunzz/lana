#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 

ll n , c, x[(int) 1e5+7] , ans= 0 ;


// ll cnp(int n)
// {
//     int r = n ;
//     int l = 1;
//     while (r >= l)
//     {
//         int mid = (l+r)/2;
//         if (x[mid]-x[mid-1] > x[mid+1]-x[mid]) ans = max(ans,x[mid]-x[mid-1]),r = mid - 1;
//         if (x[mid]-x[mid-1] < x[mid+1]-x[mid]) ans = max(ans,x[mid+1]-x[mid]) ,l = mid + 1;
//     }
//     return ans;
// }

bool check(ll dis){
    vector<ll> dp(n + 1, 0);
    ll j = 1, res = 0;
    for(ll i = 1; i <= n; i++){
        while(x[i] - x[j + 1] >= dis) ++j;
        if(x[i] - x[j] >= dis) dp[i] = dp[j] + 1;
        else dp[i] = 1;
        res = max(res, dp[i]);
    }
    return res >= c;
}

ll cnp(){
    ll l = 1, r = x[n] - x[1], ans;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int main()
{
    giuncute;
    freopen("chanbo.inp","r",stdin);
    freopen("chanbo.out","w",stdout);
    cin >> n >> c;
    for (int i = 1; i <= n ; i++) cin >> x[i];
    sort(x+1,x+1+n);
    cout << cnp();
}