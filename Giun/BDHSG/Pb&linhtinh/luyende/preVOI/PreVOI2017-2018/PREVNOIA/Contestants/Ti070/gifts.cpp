#include <bits/stdc++.h>
#define maxn 1000002
using namespace std;
long n,k;
long long f[maxn],a[maxn],d[maxn];
void nhap()
{
    cin>>n>>k;
    for(long i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(long i=k;i<=n;++i)
    {
        f[i]=max(f[i-1],a[i]-a[i-k]);
    }
    for(long i=n-k;i>=1;--i)
    {
        d[i]=max(d[i+1],a[i+k]-a[i]);
    }
}
void lam()
{
    long long ans=1ll*maxn*maxn;
    long long pos;
    for(long i=k;i<=n;++i)
    {
        pos=a[i]-a[i-k];
        //cout<<pos<<endl;
        if(pos>=max(f[i-k],d[i]))
            ans=min(ans,pos);
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    nhap();
    lam();
    return 0;
}
