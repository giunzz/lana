#include <bits/stdc++.h>
#define maxn 500
#define oo 1000000009
using namespace std;

int a[maxn][maxn],m,n,k,u,v,p,q,x,y,f[maxn][maxn];
bool kt[maxn][maxn];
void xuly()
{
    int tg=-oo;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) {kt[i][j]=true;f[i][j]=0;}
    for (int i=u;i<=p;i++)
        for (int j=v;j<=q;j++)
        {
            f[i][j]=a[i][j];
        }
    for (int i=u;i<=p;i++)
        for (int j=v;j<=q;j++)
        {
            if (tg<a[i][j])
            if (i+j>u+v&&i+j<p+q)
                {
                    x=i;y=j;
                }
        }
    kt[x][y]=false;
    for (int i=u;i<=p;i++)
        for (int j=v;j<=q;j++)
        {
            if (kt[i-1][j]) f[i][j]=max(f[i][j],a[i][j]+f[i-1][j]);
            if (kt[i][j-1]) f[i][j]=max(f[i][j],a[i][j]+f[i][j-1]);
        }
    cout<<f[p][q]<<endl;
    //cout<<x<<' '<<y<<endl;
}
void nhap()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    for (int i=1;i<=k;i++)
    {
        cin>>u>>v>>p>>q;
        xuly();
    }
}
int main()
{
    nhap();
    return 0;
}
