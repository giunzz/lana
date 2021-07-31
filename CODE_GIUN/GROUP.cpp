#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair <ll,ll>
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxn = 3e5 + 3;
ll n , k , x , a[maxn] ,b[maxn] ;
int main()
{
    giuncute;
    freopen("GROUP.inp","r",stdin);
    freopen("GROUP.out","w",stdout);
    cin >> n >> k >> x ;
    ll ans = n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort (a + 1 , a + 1 + n);
    for (int i = 1 ; i < n ; i++) b[i] = a[i+1] - a[i];
    sort (b + 1 , b + n);
    for (int i = 1 ; i < n ; i++) 
    {
        if (b[i] > x)
        {
            if ((b[i] -1) / x <= k) k -= (b[i]-1) / x;
            else break;
        }
        ans--;
    }
    cout << ans;
}
