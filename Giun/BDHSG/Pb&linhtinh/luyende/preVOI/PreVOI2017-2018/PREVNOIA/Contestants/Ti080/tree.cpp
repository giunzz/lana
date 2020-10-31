#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int oo = 1e9;
int n;
int a[maxn];
vector<int> g[maxn];
int cl[maxn],h[maxn];
int m;
int vt[maxn];
int x[maxn];
int b[maxn];

int res=oo;
void dfs(int u)
{
    cl[u]=1;
    h[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!cl[v])
        {
            dfs(v);
            h[u]=max(h[u],h[v]+1);
        }

    }

}
void kt()
{
    int s=0;
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=1;i<=m;i++)
    {

        s+=abs(b[vt[i]]-x[i]);
        b[vt[i]]=x[i];
    }
    for(int k=2;k<=h[1];k++)
        for(int i=1;i<=n;i++)
            if(h[i]==k)
    {
        int t=0;
        for(int j=0;j<g[i].size();j++)

            t+=b[g[i][j]];
        s+=abs(b[i]-t);
        b[i]=t;

    }
    res=min(res,s);
}
void Try(int i)
{
    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        if(i==m) kt();
        else Try(i+1);
    }
}
int main()
{
    freopen("tree.inp","r",stdin);
   freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
   dfs(1);
   for(int i=1;i<=n;i++)
    if(h[i]==1)
   {
       m++;
       vt[m]=i;
   }
   Try(1);
   cout<<res;
}
