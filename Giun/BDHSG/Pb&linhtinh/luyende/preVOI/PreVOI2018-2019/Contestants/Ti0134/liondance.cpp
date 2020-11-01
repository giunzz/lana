#include<bits/stdc++.h>
long long ii,jj,n,i,j,h,k,t,d,m,kq[4001],a[5005],b[5005],f[4001][4001],x,y,res=0;
using namespace std;
void xl()
{
    long long t=-1,ii,jj;
    for(i=x-1;i>=1;i--) if (a[i]>t&&(abs(a[x]-a[i])<=k))
            for(j=y-1;j>=1;j--) if (a[i]==b[j])
            if (f[x][y]==f[i][j]+1)
            {
                kq[res]=a[i],ii=i,jj=j;
                t=a[i];
            }
    res--;x=ii;y=jj;
}
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (a[i]==b[j])
    {
        f[i][j]=1;
        for(ii=1;ii<i;ii++) if (abs(a[i]-a[ii])<=k)
            for(jj=j-1;jj>=1;jj--) if (a[ii]==b[jj]) f[i][j]=max(f[i][j],f[ii][jj]+1);
        if (f[i][j]>res) res=f[i][j],x=i,y=j;
    }
    cout<<res<<endl;
    d=res;
    kq[res]=a[x];
    res--;
    while (res>0)
    {
        xl();
    }
    for(i=1;i<=d;i++) cout<<kq[i]<<' ';
}
