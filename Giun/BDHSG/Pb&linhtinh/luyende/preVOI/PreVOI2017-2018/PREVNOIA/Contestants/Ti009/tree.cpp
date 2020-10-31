#include <bits/stdc++.h>
using namespace std;
const int N=5015,oo=1e9+3;
int res=oo,x,y,n,a[N],f[N][N],num_leaf[N];
vector<int> adj[N],child[N];
int dfs(int u,int Pre)
{
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(v!=Pre)
        {
            dfs(v,u);
            child[u].push_back(v);
            if(!num_leaf[v]) num_leaf[u]++;
                else num_leaf[u]+=num_leaf[v];
        }
    }
}
int cal(int u,int s)
{
    if(!num_leaf[u]) if(s<=1) return abs(s-a[u]); else return oo;
    if(s>num_leaf[u]) return oo;
    if(f[u][s]!=-1) return f[u][s];
    f[u][s]=oo;
    if(child[u].size()==2)
    {
        int v1=child[u][0];
        int v2=child[u][1];
        for(int i=0;i<=s;i++)
            f[u][s]=min(f[u][s],cal(v1,i)+cal(v2,s-i)+abs(a[u]-s));
    } else f[u][s]=cal(child[u][0],s)+abs(s-a[u]);
    return f[u][s];
}
main()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(f,-1,sizeof f);
    dfs(1,0);
    for(int i=0;i<=num_leaf[1];i++)
        res=min(res,cal(1,i));
    cout<<res;
}
