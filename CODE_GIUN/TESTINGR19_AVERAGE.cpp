#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxn = 8e4 + 7;
using namespace std;

ll t , n , a , x[203] , dp[203][maxn];

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t ;
    while (t--)
    {
        cin >> n;
        ll sum = 0 ;
        memset(dp , 0 , sizeof dp);
        for (int i = 1 ; i <= n ; i ++) 
        {
            cin >> x[i] , x[i]-= a;
            if (x[i] < 0) sum += x[i];
        }
        dp[0][sum] = 1;
        for (int i = 1 ; i <= n ; i ++)
        {
            for (int j = 0 ; j <= sum ; j++)
            {
                ll tmp = 
            }
        }

    }
}