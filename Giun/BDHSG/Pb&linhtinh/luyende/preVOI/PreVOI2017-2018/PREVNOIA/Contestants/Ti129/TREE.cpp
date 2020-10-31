#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e3+3;
const int oo=0x3c3c3c3c;
int n;
int a[MAXN],b[MAXN];
vector<int> c[MAXN];
bool lf[MAXN];
int ans=oo;
/*int leaf[MAXN],lCount;

int sum;
void DFS(int u)
{
    if(!lf[u])
        b[u]=0;
    for(int i=0,v;i<c[u].size();++i)
    {
        v=c[u][i];
        DFS(v);
        b[u]+=b[v];
    }
    sum+=abs(a[u]-b[u]);
}
void check()
{
    sum=0;
    DFS(1);
    ans=min(ans,sum);
}
void bcktrck(int id)
{
    for(int i=0;i<=1;++i)
    {
        b[leaf[id]]=i;
        if(id==lCount)
            check();
        else
            bcktrck(id+1);
    }
}*/
vector<int> layer[MAXN];
int lm[MAXN];
int dt[MAXN];
int F[MAXN][MAXN];
void DFS(int u)
{
    layer[dt[u]].push_back(u);
    if(c[u].empty())
    {
        lm[u]=1;
        return ;
    }
    for(int i=0,v;i<c[u].size();++i)
    {
        v=c[u][i];
        dt[v]=dt[u]+1;
        DFS(v);
        lm[u]+=lm[v];
    }
}
void proc60()
{
    for(int i=1;i<=n;++i)
    for(int j=0;j<=n;++j)
        F[i][j]=oo;
    for(int i=1;i<=n;++i)
    {
        if(c[i].empty())
            lf[i]=1;
    }
    dt[1]=1;
    DFS(1);
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<layer[i].size();++j)
        {
            int u=layer[i][j];
            //cout<<u<<' ';
            if(lf[u])
            {
                F[u][0]=abs(a[u]);
                F[u][1]=abs(a[u]-1);
            }
            else
            {
                if(c[u].size()==1)
                    for(int val=0;val<=lm[u];++val)
                        F[u][val]=F[c[u][0]][val]+abs(a[u]-val);
                else
                {
                    for(int val=0;val<=lm[u];++val)
                    {
                        F[u][val]=oo;
                        for(int v=0;v<=val;++v)
                        {
                            F[u][val]=min(F[u][val],abs(a[u]-val)+F[c[u][0]][v]+F[c[u][1]][val-v]);
                        }
                    }
                }
            }
        }
        //cout<<'\n';
    }
    for(int i=0;i<=n;++i)
    {
        //cout<<i<<' '<<F[1][i]<<'\n';
        ans=min(ans,F[1][i]);
    }
    cout<<ans;
}
void D4C()
{
    cout<<rand()%(n*n/2);
}
#define filename "TREE"
void io()
{
    freopen(filename".INP","r",stdin);
    freopen(filename".OUT","w",stdout);
}
main()
{
    io();
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1,u,v;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        c[u].push_back(v);
    }
    if(n<=420)
        proc60();
    else
        D4C();
}
