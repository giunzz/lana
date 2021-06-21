#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 1e4 + 7;
ll n , c[maxn] , t[maxn] , l[maxn] , r[maxn];

bool check (ll T)
{   
    for (int i = 0 ; i <= n ; i++) l[i] = r[i] = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        l[ max (1LL , c[i] - T/t[i]) ]++;
        r[ min (n   , c[i] + T/t[i]) ]++;
    }
    for (int i = 1 ; i <= n ; i++)
    { 
        l[i] += l[i-1] , r[i] += r[i-1];
        if ( i > l[i] || i < r[i]) return 0;
    }
    return 1;
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 0 ; i < n ; i++) cin >> c[i] >> t[i];
    ll left = 0 , right = 1e8 , ans = 0 , mid ;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (check(mid) ) ans = mid , right = mid - 1 ;
        else left = mid + 1;
    }
    cout << ans ;
}