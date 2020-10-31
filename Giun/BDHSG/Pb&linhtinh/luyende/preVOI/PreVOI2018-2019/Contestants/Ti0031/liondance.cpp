#include <bits/stdc++.h>

using namespace std;
const long N=1001;
long a[N],b[N],n,d,ans;
long f[N][N];
vector<long>c;
void nhap()
{
    cin>>n>>d;
    for(long i=1;i<=n;++i)
        cin>>a[n-i+1];
    for(long j=1;j<=n;++j)
        cin>>b[n-j+1];
}
void sub1()
{
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=n;++j)
        {
            if(a[i]!=b[j])continue;
            f[i][j]=1;
            for(long u=1;u<i;++u)
            {
                for(long v=1;v<j;++v)
                {
                    if(a[u]==b[v])
                        f[i][j]=max(f[i][j],f[u][v]+1);
                }
            }
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans<<"\n";
    long u=n+1,v=n+1,ss=0;
    while(ans>0)
    {
        for(long i=u-1;i>=1;--i)
        {
            for(long j=v-1;j>=1;--j)
            {
                if(f[i][j]==ans&&ss<a[i])
                {
                    ss=a[i];
                    u=i;
                    v=j;
                }
            }
        }
        cout<<ss<<" ";
        ans--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    nhap();
    sub1();
    return 0;
}
