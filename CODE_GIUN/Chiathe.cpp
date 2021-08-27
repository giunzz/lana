#include<stdio.h>
#include<iostream>
#define ll long long
const ll oo = 1e18;
const ll maxn = 507;
const ll maxnsum = 1e5 + 7;
using namespace std;
ll n , f[maxn][maxnsum] , x[maxn];
int main()
{
    freopen("chiathe.inp","r",stdin);
    freopen("chiathe.out","w",stdout);
    scanf("%lld" , &n);
    ll sum = 0 ;
    for (int i = 1 ; i <= n ; i++) scanf("%lld" , &x[i]) , sum += x[i];
    for (int i = 0 ; i <= n ; i++)
        for (int j = 0 ; j <= sum ; j++) f[i][j] = -oo;
    f[0][0] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0;  j <= sum ; j++)
        {
            f[i][j] = max( f[i-1][j] , f[i - 1][abs(j - x[i])] + x[i]);
            if (j + x[i] <= sum ) f[i][j] = max(f[i][j] , f[i - 1][j + x[i]] + x[i]);
        }
    }
    if (f[n][0] <= 0) printf("%lld",sum) ;
    else  printf("%lld",sum - f[n][0] + f[n][0] / 2);
}