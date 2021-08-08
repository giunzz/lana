#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

ll n ;
pl d[maxn] , a , b, c;

ll getS(pl &a1, pl &b1, pl &c1)
{
    ll tmp = (b1.fi - a1.fi) * (c1.se - a1.se) -  (c1.fi - a1.fi) * (b1.se - a1.se);
    return abs(tmp);
}

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    giuncute;
    cin >> a.fi  >> a.se >> b.fi  >> b.se >> c.fi >> c.se;
    cin >> n;
    for (int i = 1 ; i <= n  ; i++) cin >> d[i].fi >> d[i].se;
    ll ans = getS(a,b,c) , cnt = 0 ;
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
    for (int i = 1 ; i <= n ; i++)
    {
        if (getS(a,b,d[i]) + getS(b,c,d[i]) + getS(a,c,d[i]) == getS(a,b,c)) cnt++;
    }
    cout << cnt;
}