#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline bool check (ll x , ll y)
{
    ll sum = 0 , tich = 1;
    if (x % y != 0 ) return false;
    else 
    {
        while (x != 0 )
        {
            sum += x % 10 ;
            tich*= (x % 10) ;
            x /= 10;
        }
    }
    if (sum % y != 0 || tich % y != 0 ) return false;
    return true;
}
ll n , k , MOD = 1000000007, t, ans = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> k;
        if (k == 1 ) cout << n % MOD << endl ;
        else 
        {
            for (ll i = 1 ; i <= n ; i++)
            {
                if (check (i,k) == true) 
                {
                    ans = (ans + 1 ) % MOD;
                }
            }
            cout << ans % MOD << endl;
        }
    }
}
