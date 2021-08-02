#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll n , t , xa , ya , xb , yb , xc , yc;

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
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        ll xCA = xc - xa  , yCA = yc - ya , xCB = xc - xb , yCB = yc - yb;
        if ((xCA == 0 && yCA == 0) || (xCB == 0 && yCB == 0)) cout << "YES" << endl;
        else if ( (xCA * yCB - yCA * xCB == 0) && (dau (xCA , yCA) !=  dau(xCB , yCB)) ) cout << "YES" << endl;
            else cout << "NO"<< endl;
    }
}
