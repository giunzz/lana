#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 1000;
ll n , m , a[maxn][maxn] , f[maxn][maxn] , ans = 0 , MOD = 1000000000;

inline ll sol (ll x , ll y)
{
    if (f[x][y] != -1) return f[x][y];
    f[x][y] = 0;
    for (int i = 1 ; i <= x ; i++)
        for (int j = 1 ; j <= y ; j++) 
            if (__gcd(a[x][y] , a[i][j]) != 1 && x + y > i+j && j < n ) 
                f[x][y] = (f[x][y] + (sol(i,j))) % MOD;
    if (y == 1) ++f[x][y];
    return f[x][y];
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> m >> n ;
    for (int i = 1 ; i <= m ; i++ )
        for (int j = 1 ; j <= n ; j++) cin >> a[i][j];
    memset(f , -1 , sizeof(f));
    f[1][1] = 1;
    for (int i = 1 ; i <= m ; i++) ans =  (ans + sol(i,n) ) % MOD;
    cout << ans;
}
