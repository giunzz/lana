#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll t , n , d , x;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while(t--)
    {
        ll s = 0 ;
        cin >> n >> d;
        for (int i = 1 ; i <= n ; i++) cin >> x , s += x;
        if (n % 2 == 0 )
        {
            if (n / 2 * d >= s) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else 
        {
            if ((n+1) / 2 * d >= s) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}