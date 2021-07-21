#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxn = 300009;
ll n, m , color[maxn] , ma = -1;

inline bool check(ll x)
{
    color[1] = ma - x;
    ll remain = n-m-1;
    for (int i = 1 ; i <= m ; i++)
    {
        if (color[i] > x)
        {
            ll tmp = max (0LL, color[i] - x);
            //cerr << tmp % x << endl;
            if (tmp % x ) remain--;
            //cerr << tmp << " " << x << " " <<  remain << endl;
            remain -= tmp/x;
        }
    }
    if (remain >= 0) return true;
    else return false;
}
int main()
{
    giuncute;
    freopen("marble.inp","r",stdin);
    freopen("marble.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) cin >> color[i] , ma = max(ma , color[i]);
    sort(color+1, color+1+m, greater<ll>() );
    if (m == n) cout << ma;
    else 
    {
        ll l = 0 , r = ma , ans = 0 ;
        while (l <= r)
        {
            ll mid = (l+r)/2;
            if (check (mid) == true) ans = mid , r = mid-1;
            else l = mid + 1;
        }
        cout << ans;
    }
}
