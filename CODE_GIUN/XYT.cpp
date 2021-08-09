#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll a[maxn], m , n , ans = 0 , ok = 0 ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i] ;
        if (a[i] <= m) 
        {
            ok = 1;
            ans = max(ans , a[i]);
        }
    }
    if (ok == 0) {cout << -1 ; return 0;}
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            for (int z = 1 ; z <= n ; z++)
            {
                if (i == j || i == z || j == z) continue;
                if (a[i] + a[j] + a[z] <= m ) ans = max(ans , a[i] + a[j] + a[z]);
                if (a[i] + a[j] <= m ) ans = max( ans , a[i] + a[j]);
                if (a[i] + a[z] <= m ) ans = max( ans , a[i] + a[z]);
                if (a[j] + a[z] <= m ) ans = max( ans , a[j] + a[z]);
            }
        }
    }
    cout << ans;
}