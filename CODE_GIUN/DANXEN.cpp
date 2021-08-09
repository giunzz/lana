#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll a[maxn], color[maxn] , n ,t , dp[maxn][5] ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) cin >> color[i] , --color[i];
    dp[0][1] = dp[0][0] = -MOD;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= 1 ; j++) 
        {
            dp[i][j] = dp[i-1][j];
            if (color[i] == j)
                dp[i][j] = max({dp[i-1][j] , dp[i-1][!j] + a[i] , a[i]});
        }
    }
    cout << max(dp[n][1] , dp[n][0]);
}

