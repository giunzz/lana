#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1000000007;
const ll maxn = 3e3 + 3;
ll n, c, f[maxn][maxn] = {{0}};

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    
    cin >> n >> c;
    f[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) f[i][0] = 1 ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= min(c,(ll) (i*(i-1)/2)) ; j++)
        {
            ll s = 0 ;
            for (int z = max(0, j-i + 1) ; z <= j ; z++)
                s =( s % MOD +f[i-1][z] % MOD) % MOD;
            f[i][j] = s ;
            cerr << f[i][j] << " ";
        }
        cerr << endl;
    }
    cout << f[n][c] ;
}
