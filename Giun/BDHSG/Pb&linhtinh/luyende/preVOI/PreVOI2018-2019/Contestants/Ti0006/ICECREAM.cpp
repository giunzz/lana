#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define maxn 1005
#define f first
#define s second
#define mp make_pair
using namespace std;
int n, NMAX;
long long res = 0;
void dequy(int dem, int x, int y, int z)
{
    if(dem == n) res ++;
    else
    {
        if(x < NMAX)
        {
            dequy(dem+1,x+1,y,z);
        }
        if(y < NMAX && x > 0)
        {
            dequy(dem+1,x-1,y+1,z);
        }
        if(z < NMAX)
        {
            if(y > 0 && x > 0) dequy(dem+1,x-1,y-1,z+1);
            else if(x > 2) dequy(dem+1,x-3,y,z+1);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
     cin >> n >> NMAX;
     int x, y, z;
     cin >> x >> y >> z;
     dequy(0,x,y,z);
    cout << res;
}
