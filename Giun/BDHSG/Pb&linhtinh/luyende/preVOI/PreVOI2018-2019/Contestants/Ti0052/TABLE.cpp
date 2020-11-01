#include <bits/stdc++.h>

using namespace std;

int const oo=INT_MAX;
int ans;
int n,m,k,u,v,p,q,e,f;
bool visited[1000][1000];
int a[1000][1000];
bool dd[1000][1000];
int dx[]={1,0};
int dy[]={0,1};
int res;

void thao(int u,int v,int p ,int q)
{
    int maxx=a[u][v+1];
    int x=u,y=v+1;
    for(int i=u;i<=p;i++)
    for(int j=v;j<=q;j++)
        if( maxx<a[i][j] )
        {
            if( i==u && j==v  ) continue;
            if( i==p && j==q  ) continue;
            maxx=a[i][j];
            x=i,y=j;
        }
    dd[x][y]=1;
    e=x;f=y;
    return;
}

void DFS(int u,int v,int p ,int q)
{
    visited[u][v]=1;
    for(int i=0;i<2;i++)
    {
        int x=u+dx[i];
        int y=v+dy[i];
        if( visited[x][y] ) continue;
        if( 1 > x || x > p || 1> y || y > q )   continue;
        if( dd[x][y]==1 ) continue;
        res+=a[x][y];
        if( x!=p || y!=q )  DFS(x,y,p,q);
        if( x==p && y==q )  ans=max(ans,res);
        res-=a[x][y];
    }
    visited[u][v]=0;
}

int main()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cin >> a[i][j];
    while(k--)
    {
        cin >> u >> v >> p >> q;
        res+=a[u][v];
        thao(u,v,p,q);
        DFS(u,v,p,q);
        dd[e][f]=0;
        cout << ans << "\n";
        res=0;
        ans=0;
    }
    return 0;
}
