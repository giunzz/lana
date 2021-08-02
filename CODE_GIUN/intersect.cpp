#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
const double esp = 1e-9;
using namespace std;
ll n , t , xa , ya , xb , yb , xc , yc , xd , yd;

ll ccw (ll x , ll y , ll u , ll v , ll i , ll j)
{
    ll a1 = u - x , b1 = v - y , a2 = i - u , b2 = j - v ;
    ll t  = a1*b2 - a2*b1;
    if (t == 0) return 0;
    else if (t < 0) return -1;
    else return 1;
}
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        if ( (ccw(xc,yc,xd,yd,xa,ya) != ccw(xc,yc,xd,yd,xb,yb)) &&  (ccw(xa,ya,xb,yb,xc,yc) != ccw(xa,ya,xb,yb,xd,yd))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
