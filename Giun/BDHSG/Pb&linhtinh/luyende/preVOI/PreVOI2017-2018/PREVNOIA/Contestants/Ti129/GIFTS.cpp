#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+4;
int n,k;
#define filename "GIFTS"
void io()
{
    freopen(filename".INP","r",stdin);
    freopen(filename".OUT","w",stdout);
}
long long a[MAXN],s[MAXN],l[MAXN],r[MAXN];
long long ans=1e16+3;
main()
{
    io();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        s[i]=s[i-1]+a[i];
    for(int i=k;i<=n;++i)
        l[i]=max(l[i-1],s[i]-s[i-k]);
    for(int i=n-k+1;i>=1;--i)
        r[i]=max(r[i+1],s[i+k-1]-s[i-1]);
    for(int i=1;i<=n;++i)
        ans=min(ans,max(l[i-1],r[i+k]));
    cout<<ans;
}

