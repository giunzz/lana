#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;

int n, k, a[maxn];
long long head[maxn], tail[maxn], tong[maxn];

int main()
{
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        tong[i] = tong[i-1] + a[i];
        if( i >= k )  head[i] = max(head[i-1], tong[i] - tong[i-k]);
    }

    for(int i=n;i>=1;i--)
    {
        if( i+k <= n+1 ) tail[i] = max(tail[i+1], tong[i+k-1] - tong[i-1]);
    }

    long long cmin = 1e15;
    for(int i=1;i<=n;i++)
    {
        long long sum = tong[i+k-1] - tong[i-1];
        if( sum >= max( head[i-1], tail[i+k]) )
        {
            cmin = min(cmin, sum);
        }
    }
    printf("%lld", cmin);
}
