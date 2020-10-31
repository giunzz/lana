#include <bits/stdc++.h>
using namespace std;

ifstream fi("BUBBLETEA.INP");
ofstream fo("BUBBLETEA.OUT");

typedef pair<int64_t,int64_t> ii;
int64_t n,k,res=1e18,a[50005],h[50005],W[50005],P[50005][20];
vector<int64_t> V[50005];
vector<ii> g[50005];

void DFS(int64_t u,int64_t high,int64_t w)
{
    h[u]=high;
    W[u]=w;
    for(int64_t i=0; i<g[u].size(); i++)
        if(h[g[u][i].first]==0)
        {
            P[g[u][i].first][0]=u;
            DFS(g[u][i].first,high+1,w+g[u][i].second);
        }
}

int64_t LCA(int64_t u,int64_t v)
{
    for(int64_t k=10; k>=0; k--)
        if(h[P[u][k]]>=h[v])
            u=P[u][k];
        else if(h[P[v][k]]>=h[u])
            v=P[v][k];
    for(int64_t k=10; k>=0; k--)
        if(P[u][k]!=P[v][k])
        {
            u=P[u][k];
            v=P[v][k];
        }
    while(u!=v)
    {
        u=P[u][0];
        v=P[v][0];
    }
    return u;
}

int64_t Dist(int64_t u,int64_t v)
{
    return W[u]+W[v]-2*W[LCA(u,v)];
}

void Check()
{
    int64_t maxn=0;
    for(int64_t i=1; i<=k/2; i++)
        maxn=max(maxn,Dist(V[i][0],V[i][1]));
    res=min(res,maxn);
}

void Try(int64_t i)
{
    for(int64_t j=1; j<=k/2; j++)
        if(V[j].size()<2)
        {
            V[j].push_back(a[i]);
            if(i==k)
                Check();
            else
                Try(i+1);
            V[j].pop_back();
        }
}

void Sub1()
{
    DFS(1,1,0);
    for(int k=1; k<=10; k++)
        for(int i=1; i<=n; i++)
            P[i][k]=P[P[i][k-1]][k-1];
    Try(1);
    fo<<res;
}

void Sub2()
{
    fo<<-1;
}

int main()
{
    fi>>n>>k;
    for(int64_t i=1; i<=k; i++)
        fi>>a[i];
    int64_t u,v,w;
    for(int64_t i=1; i<n; i++)
    {
        fi>>u>>v>>w;
        g[u].push_back(ii(v,w));
        g[v].push_back(ii(u,w));
    }
    if(k<=10)
        Sub1();
    else
        Sub2();
}
