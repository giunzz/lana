#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll  n  , x , y ;
ll f[] = {1,2,3,5,1,6,0,6,6,5,4,2,6,1,0,1}; // pisano
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    while (n--)
    {
        cin >> x >> y;
        x-- , y--;
        ll sz = y - x + 1 , ans = -1;
        if (sz >=  32) ans = sz /16 * 16; // 16*k
        else 
        {
            for (int i = x ; i < y ; i++)
                if (f[i % 16] == f[(i + 1) % 16]) {ans = 2 ; break;}
        }
        cout << ans << endl;
    }
}