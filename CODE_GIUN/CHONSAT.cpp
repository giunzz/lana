#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "CHONSAT";
const int maxn = 1e5;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

long long n , a[maxn +7] , vt = 1 , dem = -1 , ans = INT_MIN; 
int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort (a+1, a+1+n);
    for (int i = 1 ; i <= n ; i++)
    {
        if (a[i] != a[i+1]) 
        {
            if (dem  <  vt ) ans = a[i] , dem = vt;
            else if ( dem == vt )
            {
                if (ans < a[i]) ans = a[i] , dem = vt;
            } 
            vt = 1;
        }
        else vt++;
    }
    cout << dem << endl << ans;
    return 0;
}
