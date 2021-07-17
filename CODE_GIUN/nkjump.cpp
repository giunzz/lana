#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const ll maxn = 1e4 + 7 ;
ll n , a[maxn] , ans = 0 , f[maxn] ;

bool check (ll x , ll i)
{

    if (a[i] == x) return ((i > 0 && a[i-1] == x) || (i <= n && a[i+1] == x));
    ll l = 1 , r = n ;
    while ( l <= r)
    {
        ll mid = (l+r) / 2;
        if (a[mid] == x) return true;
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1 , a + 1 + n);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j < i ; j++) 
            if ( check ( a[i] - a[j] , j) == true) f[i] = max(f[i] , f[j]);
        f[i]++;
        ans = max(ans,f[i]);
    }
    cout << ans;
}
