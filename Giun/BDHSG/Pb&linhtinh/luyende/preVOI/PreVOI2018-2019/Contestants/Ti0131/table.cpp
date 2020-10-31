#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
long long n,m,k;
bool ok=0;
long long a[305][305];
long long dp[305][305];
long long e[305][305];
long long e1[305][305];
long long gt[305][305];
long long dp1[305][305];
long long u,v,p,q;
void dauvao()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
}
void tinh(long long u,long long c,long long x,long long y)
{
    for (long long i=u;i<=x;i++)
    for (long long j=v;j<=y;j++)
        {
            dp[i][j]=0;
           if (i==u && j==v)
           {
                dp[i][j]=a[i][j];
                e[i][j]=1;
                continue;
           }
           if (i==u)
           {
                dp[i][j]=dp[i][j-1]+a[i][j];
                e[i][j]=1;
                continue;
           }
           if (j==v)
           {
               dp[i][j]=dp[i-1][j]+a[i][j];
               e[i][j]=1;
               continue;
           }
           if (dp[i-1][j]<dp[i][j-1])
           {
               dp[i][j]=dp[i][j-1]+a[i][j];
               e[i][j]=e[i][j-1];
               continue;
           }
           if (dp[i-1][j]>dp[i][j-1])
           {
               dp[i][j]=dp[i-1][j]+a[i][j];
               e[i][j]=e[i-1][j];
               continue;
           }
           dp[i][j]=dp[i-1][j]+a[i][j];
           e[i][j]=e[i-1][j]+e[i][j-1];
        }
    for (long long i=x;i>=u;i--)
    for (long long j=y;j>=v;j--)
        {
            dp1[i][j]=0;
           if (i==x && j==y)
           {
                dp1[i][j]=a[i][j];
                e1[i][j]=1;
                continue;
           }
           if (i==x)
           {
                dp1[i][j]=dp1[i][j+1]+a[i][j];
                e1[i][j]=1;
                continue;
           }
           if (j==y)
           {
               dp1[i][j]=dp1[i+1][j]+a[i][j];
               e1[i][j]=1;
               continue;
           }
           if (dp1[i+1][j]<dp1[i][j+1])
           {
               dp1[i][j]=dp1[i][j+1]+a[i][j];
               e1[i][j]=e1[i][j+1];
               continue;
           }
           if (dp1[i+1][j]>dp1[i][j+1])
           {
               dp1[i][j]=dp1[i+1][j]+a[i][j];
               e1[i][j]=e1[i+1][j];
               continue;
           }
           dp1[i][j]=dp1[i+1][j]+a[i][j];
           e1[i][j]=e1[i+1][j]+e1[i][j+1];
        }
}
long long tinh1(long long u,long long v,long long x,long long y,long long l,long long r)
{
 for (long long i=u;i<=x;i++)
    for (long long j=v;j<=y;j++)
        {
            gt[i][j]=-1e9;
           if (i==l && j==r) continue;
           if (i==u && j==v)
           {
                gt[i][j]=a[i][j];
                continue;
           }
           if (i==u)
           {
                gt[i][j]=gt[i][j-1]+a[i][j];
                continue;
           }
           if (j==v)
           {
               gt[i][j]=gt[i-1][j]+a[i][j];
               continue;
           }
           if (gt[i-1][j]<gt[i][j-1])
           {
               gt[i][j]=gt[i][j-1]+a[i][j];
               continue;
           }
           if (gt[i-1][j]>gt[i][j-1])
           {
               gt[i][j]=gt[i-1][j]+a[i][j];
               continue;
           }
           gt[i][j]=gt[i-1][j]+a[i][j];
        }
        return gt[x][y];
}
void nhap()
{
    cin>>n>>m>>k;
    for (long long i=1;i<=n;i++)
    for (long long j=1;j<=m;j++)
    {
        cin>>a[i][j];
    }
    while (k--)
    {
        long long u,v,x,y;
        long long kq;
        cin>>u>>v>>x>>y;
        tinh(u,v,x,y);
        kq=dp[x][y];
        for (long long i=u;i<=x;i++)
        for (long long j=v;j<=y;j++)
        {
            if (i==u && j==v) continue;
            if (i==x && j==y) continue;
            if (dp[i][j]+dp1[i][j]-a[i][j]==dp[x][y])
            {
                if (e[i][j]*e1[i][j]==e[x][y])
                {
                    kq=min(kq,tinh1(u,v,x,y,i,j));
                }
            }
        }
        cout<<kq<<"\n";
    }
}
int main()
{
    dauvao();
    nhap();
    return 0;
}
//cacccccccccccccccccccccccccccccccc
