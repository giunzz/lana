#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1000000007;
const ll maxn = 1e5 + 3;
ll n, a[maxn] , b[maxn]  , l , r , x , q;

int main()
{
    giuncute;
    freopen("stones.inp","r",stdin);
    freopen("stones.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ,b[i] = a[i] , a[i] += a[i-1];
    sort( b + 1 , b + 1 + n);
    for (int i = 1 ; i <= n; i++) b[i] += b[i-1];
    cin >> q;
    while (q--)
    {
        cin >> x >> l >> r;
        if (x == 1) cout << a[r] - a[l-1] << endl;
        else cout << b[r] - b[l-1] << endl;
    }
}
