//Given a tree and weights of nodes. Weights are non-negative integers. Task is to find maximum size of a subtree of a given tree such that all nodes are even in weights.
// 600E (cF)
#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e6+7;
ll  m ,n , size[maxn] , color[maxn] , u , v , a[maxn] , visited[maxn] = {0} , dd[maxn] = {0};
vector < ll > G[maxn];

void DFS (int u)
{
    size[u] = 1;
    visited[u] = 1;
    for (int v : G[u])
        if (!visited[v]) p[v] = u , visited[v] = 1 , DFS(v);
    for (int v : G[u])
        if (v != p[u]) size[u] += size[v];
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    vector< pair <ll , ll> > tmp ;
    for (int i = 1  ; i <= n ; i++) cin >> a[i] , dd[a[i]]++;
    // for (int i = 1 ; i <= 1e5 ; i++)
    //     if (dd[i]) tmp.push_back({i,dd[i]});
    DFS(1);
    p[1] = 1;
    for (i = 1 ; i <= n ; i++)
    {
        for (int j = i ; j <= p[i] ; j++)
        {
            
        }
    }
    for (int i = 1 ; i < n ; i++) 
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}