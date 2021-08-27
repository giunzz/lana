#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll f[20][20] , n;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    f[1][1] = 1;
    for (int i = 2 ; i <= 10 ; i++)
        for (int j = 1 ; j <= i ; j++) 
            f[i][j] += j * (f[i-1][j] + f[i-1][j-1]);
    while (scanf("%lld",&n) && n != -1)
    {
        ll ans = 0 ;
        for (int i = 1 ; i <= n ; i++) ans += f[n][i];
        printf("%lld\n", ans);
    }
    return 0;
}