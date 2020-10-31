#include<bits/stdc++.h>

using namespace std;
const long N=303;
long n,m,k;
long a[N][N];
long long f[N][N];
long u,v,p,q;
void nhap()
{
    cin>>n>>m>>k;
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=m;++j)
        {
            cin>>a[i][j];
        }
    }
}
void kkk(long x,long y)
{
    for(long i=u;i<=p;++i)
    {
        for(long j=v;j<=q;++j)
        {
            f[i][j]=-1e18;
        }
    }
    f[u][v]=a[u][v];
    for(long i=u;i<=p;++i)
    {
        for(long j=v;j<=q;++j)
        {
            if(i==x&&j==y)continue;
            if(i>u)
                f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]);
            if(j>v)
                f[i][j]=max(f[i][j],f[i][j-1]+a[i][j]);
        }
    }
}
void lam()
{
    long long ans;
    while(k--)
    {
        cin>>u>>v>>p>>q;
        ans=1e18;
        for(long i=1;i<=n;++i)
        {
            for(long j=1;j<=m;++j)
            {
                if(i==u&&j==v)continue;
                if(i==p&&j==q)continue;
                kkk(i,j);
                ans=min(ans,f[p][q]);
            }
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    nhap();
    lam();
    return 0;
}
