#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1000000007;
const ll maxn = 3e3 + 3;
ll n, a ;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    while (n--)
    {
        cin >> a;
        for (ll x = sqrt(a) ; x >= 1 ; x--)
        {
            if (a % (x*x) == 0)  
            {
                ll y = a/(x*x);
                cout << x << " " << y << endl;
                break;
            }
        }
    }
}
