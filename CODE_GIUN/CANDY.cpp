#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  a[(int) 1e6+7], n , f[(int) 1e3 + 7][(int) 1e3+7] ={{0}} , sum = 0 ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
    cerr << sum <<  " ";
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= sum/2 ; j++)
        {
            if (a[i] > j) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
        }
    }
    cerr << f[n][sum/2];
    cout <<  (sum -f[n][sum/2]) - f[n][sum/2];
}
