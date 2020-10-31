#include <bits/stdc++.h>

using namespace std;
int m,n,k,a[300][300];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    cin >> m >> n >> k;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cin >> a[i][j];
    for(int i=1;i<=k;i++)
    {
        int u,v,p,q;
        cin >> u >> v >> p >> q;
        int ma=0,vt1,vt2,pr;
        for(int l=u;l<=p;l++)
            for(int j=v;j<=q;j++)
                if(a[l][j]>ma && a[l][j]!=a[u][v] && a[l][j]!=a[p][q])
                {
                    ma=a[l][j];
                    vt1=l;
                    vt2=j;
                }
        pr=a[vt1][vt2];
        a[vt1][vt2]=0;
        int b[300][300];
        for(int l=u;l<=p;l++) b[l][v-1]=0;
        for(int j=v;j<=q;j++) b[u-1][j]=0;
        for(int l=u;l<=p;l++)
            for(int j=v;j<=q;j++)
                b[l][j]=max(b[l-1][j]+a[l][j],b[l][j-1]+a[l][j]);
        cout << b[p][q]<<endl;
        a[vt1][vt2]=pr;
    }
    return 0;
}
