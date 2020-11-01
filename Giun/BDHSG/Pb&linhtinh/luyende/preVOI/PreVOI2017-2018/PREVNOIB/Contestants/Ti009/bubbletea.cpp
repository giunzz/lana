#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+3,logn=17,oo=1e18+3;
int n,k,u,v,c,high[N],par[N][30],lng[N],center[N],res=oo,pick[N][4],cnt[N];
vector<pair<int,int> > adj[N];
int dfs(int u)
{
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i].first;
        if(v!=par[u][0])
        {
            high[v]=high[u]+1;
            lng[v]=lng[u]+adj[u][i].second;
            par[v][0]=u;
            dfs(v);
        }
    }
}
int prepare()
{
    //memset(par,0,sizeof par);
    high[1]=0;
    dfs(1);
    for(int j=1;j<=logn;j++)
        for(int i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1];
            //cout<<par[i][j]<<'\n';
    high[0]=-1;
}
int lca(int u,int v)
{
    if(high[u]<high[v]) return lca(v,u);
    for(int i=logn;i>=0;i--)
        if(high[par[u][i]]>=high[v])
           u=par[u][i];
    //cout<<u<<' '<<v<<'\n';
    if(u==v) return v;
    for(int i=logn;i>=0;i--)
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    return par[u][0];
}
int update()
{
    int lng_max=0;
    for(int i=1;i<=k/2;i++)
    {
        int u=pick[i][1];
        int v=pick[i][2];
        int ccc=lca(u,v);
        lng_max=max(lng_max,lng[u]+lng[v]-lng[ccc]);
    }
    res=min(res,lng_max);
}
int backtrack(int i)
{
    if(i>k) {update(); return 0;}
    for(int j=1;j<=(k/2);j++)
    if(cnt[j]<2)
    {
        cnt[j]++;
        pick[j][cnt[j]]=i;
        backtrack(i+1);
        cnt[j]--;
    }
}
int process()
{
    backtrack(1);
    cout<<res;
}
main()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    cin>>n>>k;
    //cout<<n<<'\n';
    for(int i=1;i<=k;i++)
        cin>>center[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
    prepare();
    process();
    //cout<<lca(6,4);
}
