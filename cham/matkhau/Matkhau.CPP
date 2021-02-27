#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
ll n , t , r[(int) 1e4+7], b[(int)1e4+7] , m , ri , bi;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> r[1];
        ri = 0;
        ll s = r[1];
        for (int i = 2 ; i <= n ; i++) 
        {
            cin >> r[i];
            s += r[i];
            ri = max(ri,s);
        }   
        cin >> m >> b[1];
        s = b[1];
        bi = 0;
        for (int i = 2 ; i <= m ; i++) 
        {
            cin >> b[i];
            s += b[i];
            bi = max(bi,s);
        }   
        cout << ri+bi << endl;
    }
    

}