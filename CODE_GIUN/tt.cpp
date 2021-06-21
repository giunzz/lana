/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , m , t[(int) 1e6], sum = 0, ma = INT_MIN, ans = 0;

int main()
{
    // m người n bàn
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for (ll i = 1 ; i <= n ; i++) cin >> t[i], ma = max(ma,t[i]);
    ll l = 1 , r = ma*m ;
    while (l <= r)
    {
        ll mid = (l+r) / 2;
        sum = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            sum += mid / t[i];
        }
        if(sum >= m) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;    
}*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , k , a[5000] , dp[5000];

bool check (ll x)
{
    for (int i = 1; i <= n ; i++) dp[i] = 0 ;
    for (ll i = 1 ; i <= n ; i++)
        for (int j = i+1 ; j <= n ; j++) 
        {
            if (abs(a[i] - a[j]) <= x ) dp[i] = min (i - 1 , dp[j] + j-i-1);
            if (dp[i] > k) return 0;
        }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    ll l = 0 , r = 1e9 , ans ;
    while (l <= r)
    {
        ll mid = (l+r) >> 1;
        if (check(mid)) ans = mid , r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}