#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+10;
int n , k , a[MAXN];
long long sum[MAXN] , maxf[MAXN] , maxr[MAXN] , ans = 1e18;

int main()
{
    freopen("GIFTS.inp" , "r",  stdin);
    freopen("GIFTS.out" , "w",  stdout);
    scanf("%d%d",&n,&k);
    for(int i  =1 ; i<=n ; i++)
        scanf("%d",&a[i]);
    for(int i = 1 ; i<=n ; i++)
        sum[i] = sum[i-1] + a[i];
    for(int i = 1 ; i<=n - k + 1 ; i++)
        maxf[i + k - 1] = max(maxf[i +k - 2] , sum[i + k - 1] - sum[i-1]);
    for(int i = n ; i >= k ; i--)
        maxr[i - k+1]= max(maxr[i - k + 2] , sum[i] - sum[i - k]);

    for(int i  =1 ; i<=n ; i++)
        ans = min(ans , max(maxf[i-1] , maxr[i + k]));

    printf("%lld",ans);
    return 0;
}
