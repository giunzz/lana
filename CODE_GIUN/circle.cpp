#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
#define pl pair<pair<ll,ll>,ll>
const ll MOD = 1000000007;
const ll maxn = 1e4 + 3;
ll n , cnt[5] = {0};
pl a[maxn];

ll kc (pl &u) 
{
    return  (u.first.first*u.first.first + u.first.second*u.first.second);
}
bool cmp(pl &u, pl &v)
{
    ll i = u.first.first*u.first.first + u.first.second*u.first.second;
    ll j = v.first.first*v.first.first + v.first.second*v.first.second;
	return ( i <= j );
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].first.first >> a[i].first.second , a[i].second = 0;
    for (int i = n+1 ; i <= n*2 ; i++) cin >> a[i].first.first >> a[i].first.second , a[i].second = 1;
    sort(a + 1 , a + 1 + n*2 , cmp);
    for (int i = 1 ; i <= 2*n ; i++)
    {
        ++cnt[a[i].second];
        if (cnt[a[i].second] == cnt[!a[i].second] && ((kc(a[i]) < kc(a[i+1])) or i == 2*n))
        {
            cout << fixed << setprecision(6) << sqrt(kc(a[i]));
            return 0;
        }
    }
}