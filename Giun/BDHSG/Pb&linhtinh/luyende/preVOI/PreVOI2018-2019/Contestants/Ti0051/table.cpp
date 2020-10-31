#include <bits/stdc++.h>
#define PII pair<int,int>
#define F first
#define S second
#define LL long long
using namespace std;
int m,n,k,a[302][302];
LL f[302][302][5];
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++) cin>>a[i][j];
    for (int i=1;i<=k;i++)
    {
        int u,v,p,q;
        cin>>u>>v>>p>>q;
        memset(f,0,sizeof(f));
        LL res=1e16;

        for (int j=u;j<=p;j++)
        for (int k=v;k<=q;k++)
            f[j][k][1]=max(f[j-1][k][1],f[j][k-1][1])+a[j][k];

        for (int j=p;j>=u;j--)
        for (int k=q;k>=v;k--)
            f[j][k][0]=max(f[j+1][k][0],f[j][k+1][0])+a[j][k];

        for (int j=u;j<=p;j++)
        for (int k=q;k>=v;k--)
            f[j][k][2]=max(max(f[j-1][k][2],f[j][k+1][2]),f[j][k][0]+f[j][k][1]-a[j][k]);

        for (int j=p;j>=u;j--)
        for (int k=v;k<=q;k++)
            f[j][k][3]=max(max(f[j+1][k][3],f[j][k-1][3]),f[j][k][0]+f[j][k][1]-a[j][k]);

        for (int j=u;j<=p;j++)
        for (int k=v;k<=q;k++)
        if ((j!=u||k!=v)&&(j!=p||k!=q))
            res=min(res,max(f[j-1][k+1][2],f[j+1][k-1][3]));

        cout<<res<<"\n";
    }
    return 0;
}
