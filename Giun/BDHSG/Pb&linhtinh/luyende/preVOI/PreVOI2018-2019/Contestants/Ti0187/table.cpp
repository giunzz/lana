#include <bits/stdc++.h>
using namespace std;
const int N=305;
int n,m,q,a[N][N],f[N][N],d[N][N];
int f1[N][N];
int x,y,u,v,x1,y1,res,u1,v1;
bool check(int i, int j)
{
    return ( i>=x && i<=u && j>=y && j<=v && (i!=x1 || j!=y1) );
}
void sub1()
{
    while (q--)
    {
        cin >> x >> y >> u >> v;
        int kq=1e9;
        for (int U=x; U<=u; U++) for (int V=y; V<=v; V++)
        {
            if( (U==x && V==y) || (U==u && V==v) )continue;
            for (int i=x-1; i<=u+1; i++)
                for (int j=y-1; j<=v+1; j++)
                    f[i][j]=0;
            x1=U; y1=V;
            f[x][y]=a[x][y];
            for (int i=x; i<=u; i++)
                for (int j=y; j<=v; j++)
                {
                    if (i==x && j==y) continue;
                    if (check(i-1,j) && f[i][j]<f[i-1][j]+a[i][j])
                        f[i][j]=f[i-1][j]+a[i][j];
                    if (check(i,j-1) && f[i][j]<f[i][j-1]+a[i][j])
                        f[i][j]=f[i][j-1]+a[i][j];
                }
            kq=min(kq,f[u][v]);
        }
        cout << kq << '\n';
    }
    exit(0);
}
void sub2()
{
    while (q--)
    {
        cin >> x >> y >> u >> v;
        for (int i=x-1; i<=u+1; i++)
            for (int j=y-1; j<=v+1; j++)
                f1[i][j]=f[i][j]=d[i][j]=0;
        f[x][y]=a[x][y];
        d[x][y]=1;
        for (int i=x; i<=u; i++)
            for (int j=y; j<=v; j++)
            {
                if (i==x && j==y) continue;
                f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
                if (f[i-1][j]==f[i][j-1]) d[i][j]=2;
                else d[i][j]=1;
            }
        for (int i=u; i>=x; i--)
            for (int j=v; j>=y; j--)
                f1[i][j]=max(f1[i+1][j],f1[i][j+1])+a[i][j];
        res=x1=y1=0;
        for (int i=x; i<=u; i++)
            for (int j=y; j<=v; j++)
            {
                if ( (i==x && j==y) || (i==u && j==v) )
                {
                    f[i][j]=0;
                    continue;
                }
                if (d[i][j]==1 && f[i][j]+f1[i][j]-a[i][j]==f[u][v])
                {
                    if (a[i][j]>res)
                    {
                        res=a[i][j];
                        x1=i; y1=j;
                    }
                }
                f[i][j]=0;
            }
        f[x][y]=a[x][y];
        for (int i=x; i<=u; i++)
            for (int j=y; j<=v; j++)
            {
                if (i==x && j==y) continue;
                if (check(i-1,j) && f[i][j]<f[i-1][j]+a[i][j])
                    f[i][j]=f[i-1][j]+a[i][j];
                if (check(i,j-1) && f[i][j]<f[i][j-1]+a[i][j])
                    f[i][j]=f[i][j-1]+a[i][j];
            }
        cout << f[u][v] << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) cin >> a[i][j];
    if (n<=30 && m<=30 && q<=30) sub1();
    sub2();

}
