#include <bits/stdc++.h>
using namespace std;
long long f[302][302],l[302][302],g[302][302],kq,a[302][302],ma,l2[302][302];
int n,m,k,i,j,i2,j2;
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) scanf("%lld",&a[i][j]);
    int x1,y1,x2,y2;
    while(k--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        kq=1000000000000000000;
        for(i=x1;i<=x2;i++)
            for(j=y1;j<=y2;j++)
                if(i==x1 && j==y1) f[i][j]=a[i][j];
                else if(i==x1) f[i][j]=f[i][j-1]+a[i][j];
                else if(j==y1) f[i][j]=f[i-1][j]+a[i][j];
                else f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
        for(i=x2;i>=x1;i--)
            for(j=y2;j>=y1;j--)
                if(i==x2 && j==y2) g[i][j]=a[i][j];
                else if(i==x2) g[i][j]=g[i][j+1]+a[i][j];
                else if(j==y2) g[i][j]=g[i+1][j]+a[i][j];
                else g[i][j]=max(g[i+1][j],g[i][j+1])+a[i][j];
        for(i=x1;i<=x2;i++)
            for(j=y2;j>=y1;j--)
                if(j==y2) l[i][j]=f[i][j]+g[i][j]-a[i][j];
                else l[i][j]=max(l[i][j+1],f[i][j]+g[i][j]-a[i][j]);
        for(i=x1;i<=x2;i++)
            for(j=y1;j<=y2;j++)
                if(j==y1) l2[i][j]=f[i][j]+g[i][j]-a[i][j];
                else l2[i][j]=max(l2[i][j-1],f[i][j]+g[i][j]-a[i][j]);
        for(i=x1;i<=x2;i++)
            for(j=y1;j<=y2;j++)
                if((i==x1 && j==y1) || (i==x2 && j==y2)) continue;
                else
                {
                    ma=-1000000000000000000;
                    if(i>x1 && j<y2) ma=max(ma,l[i-1][j+1]);
                    if(i<x2 && j>y1) ma=max(ma,l2[i+1][j-1]);
                    kq=min(kq,ma);
                }
        printf("%lld\n",kq);
    }
}
