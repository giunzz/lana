#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n , k ,a[1007][1007] , ans = INT_MIN , d[1007][1007];
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
            if (i >= k && j >= k) ans = max(ans , a[i][j]  - (a[i-k][j] + a[i][j-k] - a[i-k][j-k]) );
        }
    }
    cout << ans;
}   