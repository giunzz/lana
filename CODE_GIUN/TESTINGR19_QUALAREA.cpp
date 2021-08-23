#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n , ans = 0 ;
pl x[maxn];
ll getS(pl &a, pl &b, pl &c)
{
    ll tmp = (b.fi - a.fi) * (c.se - b.se) - (b.se - a.se) * (c.fi - b.fi);
    return tmp;
}
int main()
{
    giuncute;
    // freopen("giun.inp","r",stdin);
    // freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i].fi >> x[i].se;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i + 1 ; j <= n ; j++)
        {
            ll s1 = 0 , s2 = 0 ;
            for (int z = 1 ; z <= n ; z++)
            {
                ll s = getS(x[i],x[j],x[z]);
                if ( abs(s) == 0) continue;
                if (s < 0 ) s1 = max(s1 , abs(s));
                else s2 = max(s2 , abs(s));
            }
            if (s1 != 0 && s2 != 0 ) ans = max(ans , s1 + s2);
        }
    }
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
    
}