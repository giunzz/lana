#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll,ll> 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll m,n,u,v,w;
ll visited[(int)1e5+7]={0} , trace[(int) 1e5+7]={0};
vector<pl> g[(int) 1e5+7];


void bfs ()
{
    queue <ll> q;
    visited[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        u = q.front();
        u.pop();
        for (int v : g[u])
        {
            if (visited[v] p)
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> u >> v >> w;
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
    }
    bfs(1);
}


