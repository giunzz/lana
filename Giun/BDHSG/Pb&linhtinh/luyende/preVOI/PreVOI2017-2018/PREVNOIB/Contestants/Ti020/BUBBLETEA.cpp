#include <iostream>
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define filename "BUBBLETEA."
using namespace std;
typedef pair<int,int> ii;
const int maxN=50003;
vector<ii> G[maxN];
int n,k;
int T[maxN];
vector<int> TS;
void io()
{
    freopen(filename"INP","r",stdin);
    freopen(filename"OUT","w",stdout);
}
int dij(int s,int t)
{
    int d[maxN];
    FOR(i,1,n) d[i]=1e9;
    d[s]=0;
    priority_queue<ii,vector<ii>,greater_equal<ii>> Q;
    Q.push(ii(0,s));
    while(!Q.empty())
    {
        int w=Q.top().first;
        int u=Q.top().second;
        Q.pop();
        if(w!=d[u]) continue;
        if(u==t) return d[t];
       // for(ii o :G[u])
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].second;
            int neww=G[u][i].first;
        if(d[v]>d[u]+neww)
        {
                d[v]=d[u]+neww;
                Q.push(ii(d[v],v));
        }
        }
    }
    return d[s];
}
main()
{
    int my[11][11];
    io();
    scanf("%d%d",&n,&k);
    FOR(i,1,k)
    {
        int x;
        scanf("%d",&x);
        TS.push_back(x);
    }
    FOR(i,1,n-1)
    {
        int u,v,c;
        cin>>u>>v>>c;
        G[u].push_back(ii(c,v));
        G[v].push_back(ii(c,u));
    }
    int res=0;
    FOR(i,0,TS.size()-2)
    FOR(j,i+1,TS.size()-1)
        my[i][j]=dij(TS[i],TS[j]),res=max(res,my[i][j]);

    cout<<res;

}
