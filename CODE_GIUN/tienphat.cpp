#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll oo = 1e18;
const ll maxn = 3e3 + 7;
using namespace std;

ll n , f[maxn] = {0};
pl a[maxn];

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
    sort (a + 1 , a + 1 + n );
    f[n + 1] = 0;
    for (int i = n ; i >=  1 ; i--)
    {
        ll kc = a[i].se;
        f[i] = oo;
        for (int j = i + 1 ; j <= n + 1 ; j++)
        {
            f[i] = min (f[i] , f[j] + kc);
            kc += a[j].fi - a[i].fi;
        }
    }
    cout << f[1];
}