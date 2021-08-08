#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

ll t , n ;
double r ;
pd a[maxn];

double kc(pd x, pd y) 
{
    double d = (x.fi - y.fi ) * (x.fi - y.fi )  + (x.se - y.se) * (x.se - y.se) ;
    return sqrt(d);
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    giuncute;
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        r = r / 2.0;
        for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
        pd b ;
        ll ans = 0 ;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                b = {(a[i].fi + a[j].fi)/2.0 ,(a[i].se + a[j].se)/2.0};
                ll ma = 0 ;
                for (int  z = 1 ; z <= n ; z++) 
                    if (kc(b , a[z]) <= r) ma++;
                ans = max(ans,ma);
            }
        }
        cout << ans << endl;
    }
}