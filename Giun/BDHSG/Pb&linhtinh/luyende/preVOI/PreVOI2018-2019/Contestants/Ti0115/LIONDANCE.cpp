#include<bits/stdc++.h>
using namespace std;
int n,delta,a[4005],b[4005],pre[4005],f[4005][4005],x[4005];
#define LO "LIONDANCE"
int main ()
{
    freopen(LO".inp","r",stdin);
    freopen(LO".out","w",stdout);
    scanf("%d%d",&n,&delta);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) if(a[i]==b[j]) {
        f[i][j]=1;
        pre[i]=0;
        for(int k=1;k<i;k++)
        for(int h=1;h<j;h++) if(a[k]==b[h]&&abs(a[i]-a[k])<=delta) {
            if(f[i][j]<=f[k][h]+1&&a[pre[i]]<a[k]) {
                f[i][j]=f[k][h]+1;
                pre[i]=k;
            }
        }
    }
    int m=0, ds=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) if(f[i][j]>ds) ds=f[i][j], m=i;
    printf("%d\n",ds);
    int sl=0;
    while(m>0) {
        x[++sl]=a[m];
        m=pre[m];
    }
    for(int i=sl;i>=1;i--) printf("%d ",x[i]);
}
