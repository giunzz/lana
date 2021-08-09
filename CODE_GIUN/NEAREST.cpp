#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e6 + 7;
using namespace std;

ll  n ;
double ans = 1e9 ;
pd a[maxn];

double kc(pd x, pd y) 
{
    double d = (x.fi - y.fi ) * (x.fi - y.fi )  + (x.se - y.se) * (x.se - y.se) ;
    return sqrt(d);
}
int main()
{
    freopen("nearest.inp","r",stdin);
    freopen("nearest.out","w",stdout);
    giuncute;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (i == j) continue;
            ans = min(ans , kc(a[i],a[j]));
        }
    }
    printf("%.3lf", ans);
}
