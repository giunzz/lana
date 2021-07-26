#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 3e3 + 3;
ll n, f[maxn][maxn] , m , ans = INT_MIN , a[maxn][maxn];

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> m >> n ;
    for (int i = 1 ; i <= m ; i++) 
        for (int j = 1 ; j <= n ; j++ ) 
            cin >> a[i][j] ,f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            for (int x = 1 ; x <= i ; x++)
            {
                for (int y = 1 ; y <= j ; y++) 
                    ans = max(ans, f[i][j] - f[x-1][j] - f[i][y-1] + f[x-1][y-1]);
            }
        }
    }
    cout << ans;
}