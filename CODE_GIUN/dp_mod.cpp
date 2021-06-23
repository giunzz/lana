#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 1e4+7;
ll n , a[maxn] , ans = 0 , k ;
bool dp[maxn][200] = false;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    dp[1][a[i] % k] = true;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j < k ; j++)
            if (dp[i][j] == true)  dp[i+1][((((j%k-a[i]%k)%k)+k)%k)] = dp[i+1][(j%k+a[i]%k)%k] = true;
    if (dp[n][0] == true) cout << "YES";
    else cout << "NO";
}
