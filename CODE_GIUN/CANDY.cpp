#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  a[(int) 1e5+7], n , f[(int) 1e3 + 7][(int) 2e5+7] ={{0}} , sum = 0 ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("candy.inp","r",stdin);
    freopen("candy.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
    //cerr << sum << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= sum ; j++)
        {
            if (a[i] > j) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
        }
    }
    ll ans = INT_MAX ;
    for (int i = 1 ; i <= sum ; i++)
        ans = min(abs( (sum-f[n][i]) - f[n][i] ),ans);
    cout << ans;
}
