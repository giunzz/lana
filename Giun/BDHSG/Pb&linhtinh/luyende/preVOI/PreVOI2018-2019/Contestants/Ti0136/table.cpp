#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const long maxn=305;
long n,m,i,j,k,sl,u,v,x,y,h,z,t;
long long d[maxn][maxn],kl,a[maxn][maxn];
pair <long,long> trc[maxn][maxn];
typedef pair<long long,pair<long ,long> > pli;
priority_queue <pli,vector<pli>,greater<pli> > q;
bool cx[maxn][maxn];

void relax(long u,long v,long h,long k,long w)
{
    bool ok=-d[u][v]-w < -d[h][k];
    if(ok)
    {
        d[h][k]=d[u][v]+w;
        trc[h][k].first=u;
        trc[h][k].second=v;
        q.push(make_pair((-d[h][k]),make_pair(h,k)));
    }
}
void dij()
{
    while(!q.empty())
    {
        long u=q.top().second.first;
        long v=q.top().second.second;
        q.pop();
        if(cx[u][v]==1) continue;
        cx[u][v]=1;
        if(u+1<=m && cx[u+1][v]==0)
            relax(u,v,u+1,v,a[u+1][v]);
        if(v+1<=n&&cx[u][v+1]==0)
            relax(u,v,u,v+1,a[u][v+1]);
    }
}
void relax2(long u,long v,long h,long k,long w)
{
    bool ok=-d[u][v]-w < -d[h][k];
    if(ok)
    {
        d[h][k]=d[u][v]+w;
        q.push(make_pair((-d[h][k]),make_pair(h,k)));
    }
}
void dij2()
{
    while(!q.empty())
    {
        //cout << 1;
        long u=q.top().second.first;
        long v=q.top().second.second;
        //cout << u << " " << v << '\n';
        q.pop();
        if(cx[u][v]==1) continue;
        //cx[u][v]=1;
        if(u+1<=m && cx[u+1][v]==0)
            relax2(u,v,u+1,v,a[u+1][v]);
        if(v+1<=n&&cx[u][v+1]==0)
            relax2(u,v,u,v+1,a[u][v+1]);
    }
}
void dfs(long u,long v)
{
    cx[u][v]=1;
    if(u+1<=m && cx[u+1][v]==0)
    {
        d[u+1][v]=max(d[u+1][v],d[u][v]+a[u+1][v]);
        dfs(u+1,v);
    }
    if(v+1<=n && cx[u][v+1]==0)
    {
        d[u][v+1]=max(d[u][v+1],d[u][v]+a[u][v+1]);
        dfs(u,v+1);
    }
}
void Try(long i,long j)
{
    if(i!=u || j!=v)
    {
        for(long k=1;k<=m;k++)
            for(long h=1;h<=n;h++) cx[k][h]=0,d[k][h]=0;
        cx[i][j]=1;
        d[u][v]=a[u][v];
        q.push(mp(-d[u][v],mp(u,v)));
        dij2();
        kl=min(kl,d[z][t]);
        Try(trc[i][j].first,trc[i][j].second);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin >> m >> n >> k;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        cin >> a[i][j];
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=m;j++)
            for(h=1;h<=n;h++) cx[j][h]=0,d[j][h]=0;
        cin >> u >> v >> z >> t;
        d[u][v]=a[u][v];
        q.push(mp(-d[u][v],mp(u,v)));
        dij();
        kl=1e15;
        for(j=1;j<=m;j++)
            for(h=1;h<=n;h++) cx[j][h]=0;
        Try(trc[z][t].first,trc[z][t].second);
        cout << kl << '\n';
    }
}
