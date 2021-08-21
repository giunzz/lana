#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define x first
#define y second
const ll oo = 1e18 ;
const ll maxn = 3e6 + 7;
using namespace std;
ll n ;
pl a[maxn];

double tich( pl p1 , pl p2, pl p3) 
{
    double p = (p1.y + p2.y) * (p2.x - p1.x) + (p2.y + p3.y) * (p3.x - p2.x) - (p3.y + p1.y)*(p3.x - p1.x);
    return p/2.0;
}
bool cmp (pl &p1 , pl &p2)
{
    pl O;
    O.x = O.y = 0 ;
    double dt1 = tich(O , p1 , p2);
    double dt2 = tich(O , p2 , p1);
    return (dt1 > dt2);
}
int main()
{
    giuncute;
    freopen("POLYLINES.inp","r",stdin);
    freopen("POLYLINES.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i].x >> a[i].y ;
    sort(a + 1 , a + 1+ n , cmp);
    for (int i = 1 ; i <= n ; i++) cout << a[i].x<< " " << a[i].y << endl;
}
