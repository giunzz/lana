#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int m,n,k,x,y,u,v,a[305][305],f[305][305],ans,MAX,d;
pair<int,int>b[305];
bool kt[305][305];
void print()
{
     for (int i=x;i<=u;i++)
        {
            for (int j=y;j<=v;j++) cout<<f[i][j]<<" ";cout<<"\n";
        }
}
void go()
{
    for (int i=x;i<=u;i++)
        for (int j=y;j<=v;j++)
            if (i!=u || j!=v)
            {
                f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
                if (f[i][j]==MAX) {d++;b[d].fi=i;b[d].se=j;}
                if (f[i][j]>MAX) {MAX=f[i][j];d=1;b[d].fi=i;b[d].se=j;}
            }
}
void go2()
{
     for (int i=x;i<=u;i++)
        for (int j=y;j<=v;j++)
            if (kt[i][j]) f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];else f[i][j]=0;
}
void solve()
{
    MAX=0;
    memset(f,0,sizeof(f));
    go();ans=max(f[u-1][v],f[u][v-1])+a[u][v];
    for (int i=1;i<=d;i++)
    {
        kt[b[i].fi][b[i].se]=false;
        go2();
        ans=min(ans,f[u][v]);
        kt[b[i].fi][b[i].se]=true;
    }
    cout<<ans<<"\n";
}
void solve2()
{
    memset(f,0,sizeof(f));
    go2();
    ans=f[u][v];
    for (int i=x;i<=u;i++)
        for (int j=y;j<=v;j++)
            if ((i!=u || j!=v)&& (i!=x || j!=y))
    {
        kt[i][j]=false;
        go2();ans=min(ans,f[u][v]);
        kt[i][j]=true;
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin.tie(0);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    memset(kt,true,sizeof(kt));
    while (k--)
    {
        cin>>x>>y>>u>>v;
        if (m+n<=60) solve2();else solve();
    }
    return 0;
}
