#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
#define pl pair<pair<ll,ll>,ll>
#define fi first
#define se second
const ll MOD = 1000000007;
const ll maxn = 1e5 + 3;
ll n;
pl a[maxn];

bool ccw (pl &a, pl &b, pl &c) 
{ 
    return(b.fi.fi - a.fi.fi) * (c.fi.se - b.fi.se) - (b.fi.se - a.fi.se) * (c.fi.fi - b.fi.fi) < 0;
}
bool cmp (pl &i , pl &j)
{
    return ccw( a[1] , i , j);
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i].first.first >> a[i].first.second , a[i].second = i;
        if (a[i] < a[1] && i > 1) swap(a[i] , a[1]); // tim thang trai nhat
    }
    sort(a + 2 , a + 1+ n , cmp);
    cout << a[1].se << " " << a[(n+2)/2].se ;
    return 0;
}