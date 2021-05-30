#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e3+7 ;
ll n , m , f[maxn][maxn] ,a[maxn]  , b[maxn] ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= m ; i++) cin >> b[i];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            if (a[i] == b[j])
            {
                if (i == 1 || j == 1) f[i][j] = 1;
                else f[i][j] = 1 + f[i-2][j-2];
            }
            else f[i][j] = max(f[i-1][j] , f[i][j-1]);
        }
    }
    cout << f[n][m];
}