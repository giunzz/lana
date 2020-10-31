#include <bits/stdc++.h>
using namespace std;
int f[4001][4001],a[4001],b[4001],i,j,kq,ma,vt,n,ii,jj,i2,j2,m;
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=n;i>=1;i--) scanf("%d",&a[i]);
    for(i=n;i>=1;i--) scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]!=b[j]) continue;
            ma=0;
            for(i2=1;i2<i;i2++)
                for(j2=1;j2<j;j2++)
                    if(a[i2]==b[j2] && abs(a[i]-a[i2])<=m)
                        ma=max(ma,f[i2][j2]);
            f[i][j]=ma+1;
            kq=max(kq,f[i][j]);
        }
    printf("%d\n",kq);
    if(kq==0) return 0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(f[i][j]==kq && vt<=a[i])
            {
                vt=a[i];
                ii=i; jj=j;
            }
    i=ii; j=jj;
    while(1)
    {
        kq--; printf("%d ",a[i]); vt=0;
        if(kq==0) break;
        for(i2=1;i2<i;i2++)
            for(j2=1;j2<j;j2++)
                if(f[i2][j2]==kq && vt<=a[i2])
                {
                    vt=a[i2];
                    ii=i2; jj=j2;
                }
        i=ii; j=jj;
    }
}
