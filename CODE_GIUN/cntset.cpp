#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxn = 4e4;
using namespace std;

ll n , t , m , a[maxn] , x , dd[maxn] , y;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        memset(dd , 0 , sizeof dd);
        cin >> n >> m ;
        for (int i = 1 ; i <= n ; i++)
        {
            a[i] = 0 ;
            cin >> y;
            for (int j = 1 ; j <= y ; j++) cin >> x , x-- , a[i] |= (1 << x);
        }
        for (int i = 1 ; i <= n ; i++) 
        {
            dd[a[i]] = 1;
            for (int j = 1 ; j <= (1 << m) - 1 ; j++)
                if (dd[j]) dd[j | a[i]] = 1;
        }
        for (int i = 1 ; i <= (1 << m) - 1 ; i++) ans += dd[i];
        cout << ans << endl;
    }
}