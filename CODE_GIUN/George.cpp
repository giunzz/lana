#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 5e3 +  7;
ll n , a[maxn] ,  f[maxn][maxn]= {{0}}  , m , k;
using namespace std;

int main()
{
    giuncute;
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n  >> m >> k;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i] , a[i] += a[i-1];
    for (int i = 1 ; i <= k ; i++)
    {
        for (int j = i*m ; j <= n ; j++ )
        {
            f[i][j] = max(f[i][j - 1], f[i - 1][j - m] + a[j] - a[j - m]);
            cerr << f[i][j] << " ";
        }
        cerr << endl;

    }
    cout << f[k][n];
}
