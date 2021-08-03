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
ll dau (ll x ,ll y)
{
    if (x == 0) 
    {
        if (y >= 0) return 0;
        else return 1;
    }
    else if (x > 0) return 0;
    else return 1;
}
bool check ( ll xu , ll yu , ll xv , ll yv , ll xi , ll yi)
{
    ll xui = xi - xu  , yui = yi - yu , xvi = xi - xv , yvi = yi - yv;
    if ((xui == 0 && yui == 0) || (xvi == 0 && yvi == 0)) return true;
    else if ( (xui * yvi - yui * xvi == 0) && (dau (xui , yui) !=  dau(xvi , yvi)) ) return true;
    else return false;

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
        if (check(xa , ya , xb , yb , xc , yc) == true) cout << "YES" << endl;
        else if (check(xa , ya , xb , yb , xd , yd) == true) cout << "YES" << endl;
        else if (check(xc , yc , xd , yd , xa , ya) == true) cout << "YES" << endl;
        else if (check(xc , yc , xd , yd , xb , yb) == true) cout << "YES" << endl;
        else if ( (ccw(xc,yc,xd,yd,xa,ya) != ccw(xc,yc,xd,yd,xb,yb)) &&  (ccw(xa,ya,xb,yb,xc,yc) != ccw(xa,ya,xb,yb,xd,yd))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
