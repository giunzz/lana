#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll t , x, y ;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        cout << x*(x-1)*(x-2) +  y*(y-1)*(y-2) + x*(x-1)*y +  y*(y-1)*x << endl;
    }
}
