#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
ll t , a , b , n;
using namespace std;

int main()
{
    giuncute;
    freopen("AC6.inp" , "r",stdin);
    freopen("AC6.out", "w" ,stdout);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        ll ans = INT_MAX , ok = 0 , y = 0 ;
        for (ll x = 0 ; x * a <= n ; x++)
        {
            if ((n - (x * a)) % b == 0)
            {
                y = (n - (x * a)) / b;  
                ok = 1 , ans = min(ans,x+y);
            }
        }
        if (ok == 0) cout << -1 << endl;
        else  cout << ans << endl;
    }
}