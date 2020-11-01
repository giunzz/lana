#include <bits/stdc++.h>
#define ft first
#define sd second
#define maxn 5003
#define mod
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg "TREE"
using namespace std;
long n,gt[maxn],sl[maxn];
long long f[maxn][maxn];
vector < long > a[maxn];
void nhap()
{
    cin >>n;
    for(long i=1;i<=n;++i)
    {
        cin >> gt[i];
    }
    for(long i=1;i<n;++i)
    {
        long u,v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
}
void dfs(long u,long pa)
{
    if(a[u].size()==1 && u!=1)
    {
        sl[u]=1;
        return ;
    }
    for(auto v:a[u])
    {
        if(v==pa) continue;
        dfs(v,u);
        sl[u]+=sl[v];
    }
}
void bfs(long u,long pa)
{
    if(a[u].size()==1 && u!=1)
    {
        f[u][0]=abs(gt[u]);
        f[u][1]=abs(gt[u]-1);
    }
    for(auto v:a[u])
    {
        if(v==pa)continue;
        bfs(v,u);
    }
    if((a[u].size()==2&&u!=1) || (u==1 && a[u].size()==1))
    {
        for(auto v:a[u])
        {
            if(v==pa) continue;
            for(long j=0;j<=sl[v];++j)
            {
                f[u][j]=min(f[u][j],f[v][j]+abs(gt[u]-j));
            }
        }
    }
    if((a[u].size()==3 && u!=1) || (u==1 && a[u].size()==2))
    {
        long v1=0,v2=0;
        for(auto v:a[u])
        {
            if(v==pa) continue;
            if(v1==0) v1=v;
            else v2=v;
        }
        for(long j=0;j<=sl[v1];++j)
        {
            for(long k=0;k<=sl[v2];++k)
            {
                f[u][j+k]=min(f[u][j+k],f[v1][j]+f[v2][k]+abs(gt[u]-j-k));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Bjerg".inp","r",stdin);
    freopen(Bjerg".out","w",stdout);
    nhap();
    dfs(1,0);
    for(long i=1;i<=n;++i)
    {
        for(long j=0;j<=sl[1];++j)
        {
            f[i][j]=100000000009;
        }
    }
    bfs(1,0);
    long long ans=100000000009;
    for(long i=0;i<=sl[1];++i)
    {
        ans=min(ans,f[1][i]);
    }
    cout << ans;
    return 0;
}
