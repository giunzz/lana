#include <bits/stdc++.h>
using namespace std;

ifstream fi("TREE.INP");
ofstream fo("TREE.OUT");

int n,res=1e9,a[5005],leaf[5005],F[5005][5005];
bool Free[5005][5005];
vector<int> g1[5005],g[5005];

void PreDFS(int u,int p)
{
    bool check=false;
    for(int i=0;i<g1[u].size();i++)
        if(g1[u][i]!=p)
        {
            check=true;
            g[u].push_back(g1[u][i]);
            PreDFS(g1[u][i],u);
            leaf[u]+=leaf[g1[u][i]];
        }
    if(check==false)
        leaf[u]++;
}

int f(int u,int val)
{
    if(Free[u][val]==true)
        return F[u][val];
    Free[u][val]=true;
    F[u][val]=1e9;
    if(val>leaf[u])
        return F[u][val];
    if(g[u].size()==0)
    {
        if(val>=2)
            return F[u][val];
        return F[u][val]=abs(a[u]-val);
    }
    if(g[u].size()==1)
        F[u][val]=min(F[u][val],f(g[u][0],val)+abs(a[u]-val));
    if(g[u].size()==2)
        for(int i=0;i<=val;i++)
            F[u][val]=min(F[u][val],f(g[u][0],i)+f(g[u][1],val-i)+abs(a[u]-val));
    return F[u][val];
}

int main()
{
    fi>>n;
    for(int i=1;i<=n;i++)
        fi>>a[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        fi>>u>>v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    PreDFS(1,1);
    for(int i=0;i<=leaf[1];i++)
        res=min(res,f(1,i));
    fo<<res;
}
