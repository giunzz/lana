#include<bits/stdc++.h>
using namespace std;
ifstream fi("TREE.INP");
ofstream fo("TREE.OUT");
int ans=1e9+7;
vector<int>v[5001];
int cnt=0,a[5001],b[5001],n,c[5001],res[5001];
void dfs(int u, int pa,int gt)
{
    if(v[u].size()==1&&u!=1)
    {
        if((b[u]&gt)==0)
        {
            c[u]=0;
            res[u]=a[u];
        }
        else
        {
            c[u]=1;
            res[u]=abs(a[u]-1);
        }
    }
    else
    {
        c[u]=0;
        res[u]=0;
        for(int i=0;i<v[u].size();++i)
        {
            int vv=v[u][i];
            if(vv==pa)continue;
            dfs(vv,u,gt);
            c[u]+=c[vv];
            res[u]+=res[vv];
        }
        res[u]+=abs(a[u]-c[u]);
    }
}
int main()
{
    fi>>n;
    for(int i=1;i<=n;++i)fi>>a[i];
    if(n==1)
    {
        fo<<min(a[1],abs(a[1]-1));
        exit(0);
    }
    for(int i=1;i<n;++i)
    {
        int x, y;
        fi>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=2;i<=n;++i)
    {
        if(v[i].size()>1)continue;
        b[i]=(1<<cnt);
        cnt++;
    }
    for(int i=0;i<(1<<cnt);++i)
    {
        dfs(1,1,i);
        ans=min(ans,res[1]);
    }
    fo<<ans;
}
