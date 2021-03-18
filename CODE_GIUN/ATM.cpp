#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast")
ll n, k, a[30], x[30]={0} , ans = INT_MAX , dp[30] ={0} , ok = 0;
ll dd[30]={0} , d = 0  , sum = 0;
void chon (int i)
{
    for (int j = 0 ; j <= 1 ; j++)
    {
            x[i] = j;
            d += j;
            sum += (a[i]*x[i]);
            if ( i == n )
            {
                if (sum == k && d < ans) ans = d , ok = 1;
            }
            else if (d + (k-sum)/dp[i+1] < ans) chon(i+1);
            sum -= (a[i]*x[i]);
            d-=j;
        cerr << sum << " " << ans << endl;
    }
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    dp[n] = a[n];
    for (int i = n ; i >= 1 ; i--) dp[i] = max(dp[i+1],a[i]);
    chon(1);
    if (ok == 0 ) cout << -1 ;
    else cout << ans;
}