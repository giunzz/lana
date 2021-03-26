#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 100007;
using namespace std;
ll n , m , u , v , visited[maxn] ={0};
vector<ll> G[maxn];
void dfs (ll u)
{
    visited[u] = 1;
    for (ll v : G[u]) 
    {
        if (!visited[v]) cout << v << " " ,dfs(v);
    }
}
void bfs (ll node)
{
    queue<ll> q;
    cout << node << " ";
    visited[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (int v : G[u] )
        {
            if (!visited[v]) cout << v << " ", q.push(v) , visited[v] = 1;
        }

    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >>n >> m ;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
 //   cout << 1 << " ";
 //   dfs(1);
    bfs(1);
}
// 6 9
// 1 2 
// 1 3 
// 2 3
// 2 4 
// 2 5
// 3 5 
// 4 5 
// 4 6
