#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll int 
#define pi pair<int,int>
const int MAXN = 1e5+7;
const ll oo = 1e9 + 7;
int n,m,u,v,w,a,b,k;
int  d[MAXN] ={0} , visited[MAXN] = {0};
vector<pi>G[MAXN] ;

void dijkstra(ll node) 
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[node] = 0;
    pq.push({0, node});
    while (pq.size())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (pi i : G[u]) 
        {
            int v = i.second;
            int uv = i.first;
            if (d[v] > du + uv) d[v] = du + uv , pq.push({d[v], v});
        }
    }
}

int main() 
{
    giuncute;
    freopen("WARRANTY.inp","r",stdin);
    freopen("WARRANTY.out","w",stdout);
    cin >> n >> m >> a >> b >> k;
    for (int i = 1 ; i <= n ; i++) visited[i] = 0;
    visited[a] = 1, visited[b] = 1;
    while (m--) 
    {
        cin >> u >> v >> w;
        visited[u] = 0;
        visited[v] = 0;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    dijkstra(a);
    for (int j = 1 ; j <= n ; j++) 
        if (d[j] <= k) visited[j] = 1;

    dijkstra(b);
    for (int j = 1 ; j <= n ; j++) 
        if (d[j] <= k)  visited[j] = 1;
    int ok = 0 ;
    for (int i = 1 ; i <= n ; i++)
        if (visited[i] == 0) ok = 1 , cout << i << " ";
    if (ok == 0) cout << -1;
}