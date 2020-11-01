#include<bits/stdc++.h>
long long ii,jj,n,i,j,h,k,t,d,m,a[303][303],x,y,u,v,f[100][100][100];
using namespace std;
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>m>>n>>k;
    for(i=1;i<=m;i++) for(j=1;j<=n;j++) cin>>a[i][j];
    for(h=1;h<=k;h++)
    {
        cin>>x>>y>>u>>v;
        d=1e15;
        for(i=x;i<=u;i++) for(j=y;j<=v;j++)
            if ((i!=x||j!=y)&&(i!=u||j!=v))
        {
            t=a[i][j];
             a[i][j]=-1e15;
            for(ii=x;ii<=u;ii++) for(jj=y;jj<=v;jj++) f[h][ii][jj]=max(f[h][ii-1][jj],f[h][ii][jj-1])+a[ii][jj];
            d=min(d,f[h][u][v]);
            a[i][j]=t;
        }
        cout<<d<<endl;
    }
}
