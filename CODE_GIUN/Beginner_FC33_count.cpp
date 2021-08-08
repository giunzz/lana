#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

ll t , n ;

ll phi(ll n) 
{
    ll res = n;
    for (int i = 2; i * i <= n; ++i) 
    {
        if (n % i == 0) 
        {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n != 1) res -= res / n;
    return res;
}
int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << phi(n) << endl;
    }
}