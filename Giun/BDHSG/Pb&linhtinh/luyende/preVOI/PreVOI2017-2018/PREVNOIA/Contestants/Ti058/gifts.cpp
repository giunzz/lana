#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
int n, k;
int a[N];
long long s[N], maxL[N], maxR[N], res;
int main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie();
    scanf("%d%d", &n, &k);
    for ( int i=1; i<=n; i++ )  scanf("%d", &a[i]);
    for ( int i=1; i<=k; i++ )
        s[1]=s[1]+a[i];
    for ( int i=2; i<=n-k+1; i++ )
        s[i]=s[i-1]-a[i-1]+a[i+k-1];
    for ( int i=1; i<=n-k+1; i++ )
        maxL[i]=max(maxL[i-1], s[i]);
    for ( int i=n-k+1; i>=1; i-- )
        maxR[i]=max(maxR[i+1], s[i]);
    res=1e13;
    for ( int i=1; i<=n-k+1; i++ )
        if ( i<=k )
            res=min(res, maxR[i+k]);
        else
        if ( i>k && i<n-2*k+2 )
            res=min(res, max(maxR[i+k], maxL[i-k]));
        else
            res=min(res, maxL[i-k]);
    printf("%lld", res);
}
