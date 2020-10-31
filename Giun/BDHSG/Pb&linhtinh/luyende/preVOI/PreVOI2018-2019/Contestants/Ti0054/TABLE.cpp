#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=302;
int n,m,k,a[maxn][maxn];
int lt[maxn][maxn],b[maxn*maxn],trc1[maxn*maxn],trc2[maxn*maxn];
bool dd[maxn*maxn];
long long d1[maxn*maxn],cnt1[maxn*maxn],d2[maxn*maxn],cnt2[maxn*maxn],d[maxn*maxn];
typedef pair<int,int> ii;
vector<ii> ve1[maxn*maxn],ve2[maxn*maxn];
typedef pair<long long,int> li;
priority_queue<li,vector<li>,greater<li>> q;
void dijkstra(int u,long long d[],long long cnt[],int trc[],vector<ii> ve[])
{
    for(int i=1;i<=n*m;++i) d[i]=LLONG_MIN;
    cnt[u]=1;
    q.push({d[u]=b[u],u});
    while(!q.empty())
    {
        u=q.top().S;
        long long cu=q.top().F;
        q.pop();
        if(cu!=d[u]) continue;
        for(int i=0;i<ve[u].size();++i)
        {
            int v=ve[u][i].S;
            long long cv=ve[u][i].F;
            if(d[v]<cu+cv) {trc[v]=u; cnt[v]=cnt[u]; q.push({d[v]=cu+cv,v});}
            else if(d[v]==cu+cv) cnt[v]+=cnt[u];
        }
    }
}
void dijkstra2(int u)
{
    for(int i=1;i<=n*m;++i) d[i]=LLONG_MIN;
    q.push({d[u]=b[u],u});
    while(!q.empty())
    {
        u=q.top().S;
        long long cu=q.top().F;
        q.pop();
        if(cu!=d[u]) continue;
        for(int i=0;i<ve1[u].size();++i)
        {
            int v=ve1[u][i].S;
            if(dd[v]) continue;
            long long cv=ve1[u][i].F;
            if(d[v]<cu+cv) q.push({d[v]=cu+cv,v});
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,tt=0;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            lt[i][j]=++tt;
            b[tt]=a[i][j];
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(i<n) ve1[lt[i][j]].push_back({a[i+1][j],lt[i+1][j]});
            if(j<m) ve1[lt[i][j]].push_back({a[i][j+1],lt[i][j+1]});
        }
    for(int i=n;i>=1;--i)
        for(int j=m;j>=1;--j)
        {
            if(i>1) ve2[lt[i][j]].push_back({a[i-1][j],lt[i-1][j]});
            if(j>1) ve2[lt[i][j]].push_back({a[i][j-1],lt[i][j-1]});
        }
    while(k--)
    {
        int u,v,x,y; cin>>u>>v>>x>>y;
        dijkstra(lt[u][v],d1,cnt1,trc1,ve1);
        dijkstra(lt[x][y],d2,cnt2,trc2,ve2);
        long long mn=LLONG_MAX;
        int uu=trc1[lt[x][y]],vv=lt[x][y];
        for(vv=uu,uu=trc1[uu];uu;vv=uu,uu=trc1[uu])
            if(cnt1[uu]*cnt2[vv]==cnt1[lt[x][y]])
            {
                dd[vv]=1;
                dijkstra2(lt[u][v]);
                mn=min(mn,d[lt[x][y]]);
                dd[vv]=0;
            }
        if(mn!=LLONG_MAX) cout<<mn<<'\n';
        else cout<<d1[lt[x][y]]<<'\n';
    }
}
