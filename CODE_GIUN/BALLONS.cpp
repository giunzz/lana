#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e6 + 7 ;
using namespace std;
ll  n  ,  a[maxn] , dd[maxn] = {0};
int main()
{
    giuncute;
    freopen("BALLONS.inp","r",stdin);
    freopen("BALLONS.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i] ;
    ll ans = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        if (dd[a[i]] != 0) dd[a[i]] -= 1 , dd[a[i]-1] += 1;
        else ans++ , dd[a[i]-1] += 1;
    }
    cout << ans;
}
