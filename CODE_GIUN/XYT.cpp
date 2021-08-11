#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll a[maxn];
ll  m , n , ans = 0;
int main()
{
    giuncute;
    freopen("XYT.inp","r",stdin);
    freopen("XYT.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    sort (a + 1 , a + 1 + n);
    ll j = 0 , k = 0 ;
    for (int i =  1; i <= n ; i++)
    {
        if (a[i] <= m ) ans = max (ans , a[i]);
        while (j < i - 1 && a[j+1] + a[i] <= m)  ++j;
        if (a[i] + a[j] <= m ) ans = max (ans , a[i] + a[j]);
        while (k < j - 1 && a[k+1] + a[j] + a[i] <= m )  ++k;
        if (a[i] + a[j] + a[k] <= m ) ans = max (ans ,a[k] + a[i] + a[j]) ;
        if (!k || !j) continue;
        ll tmp = m - a[i] , z1 = k;
        for (int z = j-1 ; z >= k ; z--)
        {
            while (z1 < z-1 && a[z1 + 1] + a[z] <= tmp) ++z1;
            if (a[z1] + a[z] + a[i] <= m ) ans = max (ans , a[z1]  + a[z] + a[i]);
        }
        //cerr << ans << " ";
    }
    cout << ans;
}