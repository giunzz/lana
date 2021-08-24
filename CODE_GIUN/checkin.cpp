#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 + 7;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , t[maxn] , m ;

bool check (ll time)
{
    ll sum = 0 ;
    for (int i = 1 ; i <= n ; i++) sum += time/t[i];
    if (sum >= m) return true;
    return false;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++) cin >> t[i];
    ll l = 0 , r = 1e18 , ans ;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid)) ans = mid , r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}