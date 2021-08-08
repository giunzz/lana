#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , ans = 0 ;
pl v[maxn];

ll ccw (pl &a, pl &b, pl &c) 
{ 
    ll a1 = b.fi - a.fi , b1 = b.se - a.se , a2 = c.fi - b.fi , b2 = c.se - b.se ;
    ll t  = a1*b2 - a2*b1;
    if (t == 0) return 0; // di thang
    else if (t < 0) return -1; // queo phai
    else return 1; // queo trai
}

bool cmp (pl &x , pl &y)
{
    return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

bool check[maxn] = {0};
ll vt[maxn];
void convexhull()
{
    ll  m = 1  ;
    for (int i = 1 ; i <= n ; i++)
    {   
        while (m > 2 && ccw(v[vt[m - 2]] , v[vt[m - 1]] , v[i]) < 0 ) m--;
        vt[m++] = i ;
    }
    ll t = m + 1;
    for(int i = n; i > 0 ; i--)
    {
        while (m > t && ccw(v[vt[m - 2]], v[vt[m - 1]], v[i]) < 0) m--;
        vt[m++] = i;
    }
    for (int i = 1 ; i <= n ; i++) check[i] = false;
    for(int i = 1; i < m; i++) check[vt[i]] = true;
    ll k = 0 ;
    for(int i = 1; i <= n ; i++) 
        if (!check[i]) v[++k] = v[i];
    n = k;
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    giuncute;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> v[i].fi >> v[i].se;
    sort(v + 1 , v + 1 + n , cmp);
    while (n > 2)
    {
        ans++;
        convexhull(); // monotone chain
    }
    cout << ans;
}