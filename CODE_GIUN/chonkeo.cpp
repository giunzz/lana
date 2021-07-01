#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e3+7;
ll n , t , k , dp[maxn][maxn] = {0} , N = 1000;
ll MOD = 1e9;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    for (int i = 1 ; i <= N ; i++) dp[i][0] = 1;
    for (int i = 1 ; i <= N ; i++)
        for (int j = 1 ; j <= N ; j++) dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
    cin >> t ;
    while (t--)
    {
        cin >> n >> k;
        cout << dp[n][k] % MOD << endl;
    }
}