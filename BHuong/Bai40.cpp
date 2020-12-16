#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
int n , a[1000] , ans = 0 , f[1000][1000] ={{0}};
int main()
{
    giuncute;
    freopen("bai40.inp","r",stdin);
    freopen("bai40.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , f[i][i] = a[i];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i+1 ;j <= n ; j++)
        {
            f[i][j] = __gcd(a[j],f[i][j-1]);
            if (f[i][j] > 1 && j-i+1 > ans  ) ans = max (ans,j-i+1);
        }
    }
    cout << ans;
}