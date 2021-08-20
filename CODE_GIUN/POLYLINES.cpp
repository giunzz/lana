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

bool ccw (pl &a, pl &b, pl &c) 
{ 
    return(b.x- a.x) * (c.y - b.y ) - (b.y - a.y ) * (c.x - b.x) < 0;
}
bool cmp (pl &i , pl &j)
{
    return ccw( a[1] , i , j);
}

int main()
{
    giuncute;
    freopen("POLYLINES.inp","r",stdin);
    freopen("POLYLINES.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i].x >> a[i].y ;
        if (a[i] < a[1] && i > 1) swap(a[i] , a[1]); 
    }
    sort(a + 2 , a + 1+ n , cmp);
    for (int i = 1 ; i <= n ; i++) cout << a[i].x<< " " << a[i].y << endl;
}
