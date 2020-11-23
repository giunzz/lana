#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
ll n ,  f[1008]= {0} , d, w , h;
using namespace std;
struct giun
{
    ll x,y ,z;
}  a[(int) 1e3 + 7];

bool giunzz (giun &a , giun &b )
{
    return (a.y*a.z <= b.y*b.z);
}
int main()
{
    giuncute;
    freopen("boxstack.inp","r",stdin);
    freopen("boxstack.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> h >> w >> d;
        a[i].x = h;
        a[i].y = min(w,d);
        a[i].z = max(w,d);
    }
    sort (a+1,a+1+n,giunzz);
 //   for (int i = 1 ; i <= n ; i++) cerr << a[i].x << " " << a[i].y << " " << a[i].z << endl;
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j < i ; j++)
        {
            if (a[i].y >= a[j].y &&  a[i].z >= a[j].z) f[i] = max(f[i],f[j]);
        }
        f[i] += a[i].x , ans = max( f[i] , ans); 
    }
    cout << ans ;
}