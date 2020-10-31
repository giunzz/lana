#include <bits/stdc++.h>
#define ll long long
#define N 305
#define se second
#define ft first

using namespace std;

ll n,m,k,a[N][N],u,v,p,q,f[N][N],res,tam;
pair<int,int> w[N*N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
    while (k--)
    {
        cin>>u>>v>>p>>q;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++) f[i][j]=-1e17;
        res=1e17;
        f[u][v]=a[u][v];
         for (int i=u+1;i<=p;i++) f[i][v]=f[i-1][v]+a[i][v];
        for (int i=v+1;i<=q;i++) f[u][i]=f[u][i-1]+a[u][i];
        for (int x=u+1;x<=p;x++)
            for (int y=v+1;y<=q;y++)
                f[x][y]=max(f[x][y-1],f[x-1][y])+a[x][y];
        ll d=0;
        ll x=p;ll y=q;
        while (x!=u || y!=v)
        {
            if (f[x][y-1]>f[x-1][y])
            {
                f[x][y]=f[x][y-1];
                y-=1;
            }
            else {
                f[x][y]=f[x-1][y];
                x-=1;
            }
            w[++d].ft=x;
            w[d].se=y;
        }
	d--;
        for (int o=1;o<=d;o++)
            {
               ll x=w[o].ft;ll y=w[o].se;
                for(int i=u;i<=p;i++)
                    for (int j=v;j<=q;j++) f[i][j]=0;
                f[u][v]=a[u][v];
                for (int i=u+1;i<=p;i++) f[i][v]=f[i-1][v]+a[i][v];
                for (int i=v+1;i<=q;i++) f[u][i]=f[u][i-1]+a[u][i];
                tam=a[x][y];
                a[x][y]=-1e17;
                for (int i=u+1;i<=p;i++)
                    for (int j=v+1;j<=q;j++)
                        f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
                res=min(res,f[p][q]);
                a[x][y]=tam;
            }
        cout<<res<<"\n";
    }
    return 0;
}
