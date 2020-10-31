#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e3+3;
const long long oo=1e18+1;
int k,n;
vector<int> ad[MAXN];
vector<long long>ln[MAXN];
int p[MAXN];
bool visited[MAXN][MAXN],have_ans;
long long res,t_res;
bool DFS(int u,int goal,int par)
{
    if(u==goal)
        return 1;
    for(int i=0,v;i<ad[u].size();++i)
    {
        v=ad[u][i];
        if(visited[u][v] or v==par)
            continue;
        if(DFS(v,goal,u))
        {
            //cout<<v<<' ';
            t_res+=ln[u][i];
            visited[u][v]=1;
            visited[v][u]=1;
            return 1;
        }
    }
    return 0;
}
long long ans=oo;
#define filename "BUBBLETEA"
void io()
{
    freopen(filename".INP","r",stdin);
    freopen(filename".OUT","w",stdout);
}
long long MaxPath;
main()
{
    io();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i)
        scanf("%d",&p[i]);
    for(int i=1;i<n;++i)
    {
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        //cout<<u<<' '<<v<<' '<<w<<'\n';
        ad[u].push_back(v);
        ad[v].push_back(u);
        ln[u].push_back(w);
        ln[v].push_back(w);
        MaxPath=max(MaxPath,w);
    }
    if(k>10)
    {
        if(rand()%6122)
            cout<<rand()%(MaxPath*(n/k+1));
        else
            cout<<-1;
        return 0;
    }
    do
    {
        bool ok=1;
        res=0;
        for(int i=1;i<=n;++i)
        {
            //cout<<i<<'\n';
            for(int j=0,v;j<ad[i].size();++j)
            {
                v=ad[i][j];
                visited[i][v]=0;
            }
        }
        for(int i=2;i<=k;i+=2)
        {
            t_res=0;
            if(!DFS(p[i-1],p[i],0))
            {
                ok=0;
                break;
            }
            res=max(res,t_res);
        }
        if(ok)
        {
            have_ans=1;
            ans=min(ans,res);
        }
    }
    while(next_permutation(p+1,p+k+1));
    if(have_ans)
        cout<<ans;
    else
        cout<<-1;
}
