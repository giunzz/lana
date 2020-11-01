#include <bits/stdc++.h>

using namespace std;
long long b[5],c1[5],a[10005][10005],d[10005][10005],n,m,k;
bool kt[10005][10005];
void bfs(int x,int di,int uu,int vv)
{
    queue <int> h;
    queue <int> c;
    h.push(x);
    c.push(di);
    d[x][di]=a[x][di];
    kt[x][di]=false;
    while (!h.empty() && !c.empty())
    {
        int u=h.front(),v=c.front();
        h.pop();
        c.pop();
        for (int i=1;i<=2;i++)
        if (kt[u+b[i]][v+c1[i]] &&v+c1[i]>0 && u+b[i]>0 &&v+c1[i]<=n && u+b[i]<=m)
        {
            d[u+b[i]][v+c1[i]]=max(d[u+b[i]][v+c1[i]],d[u][v]+a[u+b[i]][v+c1[i]]);
            kt[u+b[i]][v+c1[i]]=false;
            if (u+b[i]!=uu && (v+c1[i])!=vv)
            {h.push(u+b[i]);
            c.push(v+c1[i]);}
        }
      else d[u+b[i]][v+c1[i]]=max(d[u+b[i]][v+c1[i]],d[u][v]+a[u+b[i]][v+c1[i]]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("table.inp","r",stdin);
     freopen("table.out","w",stdout);
    b[1]=0,b[2]=1;
     c1[1]=1,c1[2]=0;
     cin>>m>>n>>k;
     for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
     while (k--)
     {  int u,v,p,q;
         for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) kt[i][j]=true;
      for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) d[i][j]=0;
         cin>>u>>v>>p>>q;
         bfs(u,v,p,q);
        // int m1=d[p-1][q]+a[d][p];
         cout<<min(d[p-1][q]+a[p][q],d[p][q-1]+a[p][q])<<endl;
     }
}
