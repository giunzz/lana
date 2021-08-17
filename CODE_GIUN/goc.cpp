#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e9 + 7;
const ll maxn = 2e3 +7;
using namespace std;

ll n , k , a[maxn] , x;
bool dd[maxn] = {0};

void sol (ll num)
{
    ll t ;
    for (int i = 1 ; i <= n ; i++)
    {
        t = num + a[i];
        if (t > 360) t -= 360;
        if (dd[t] != 0) continue;
        dd[t] = dd[360 - t] = 1;
        sol(t);
        sol(360 - t);
    }
    for (int i = 1 ; i <= n ; i++)
    {
        t = num - a[i];
        if (t < 0) t -= t;
        if (dd[t] != 0) continue;
        dd[t] = dd[360 - t] = 1;
        sol(t);
        sol(360 - t);
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , dd[a[i]] = 1 , sol(a[i]);
    for (int i = 0 ; i <= 360 ; i++)
        if (dd[i] != 0) sol(i);
    for (int i = 1 ; i <= k ; i++)
    {
        cin >> x;
        if (dd[x] != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}