//Given a tree and weights of nodes. Weights are non-negative integers. Task is to find maximum size of a subtree of a given tree such that all nodes are even in weights.
#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e6+7;
ll p[maxn] ={0}  , m ,n , ChainHead[maxn] ={0} , ChainIn[maxn] ={0} , u , v , Chain = 0 ;
ll posIn[maxn] = {0} , Index = 0 , num_child[maxn] = {0};
ll visited[maxn] = {0},cnt = 0 ;
vector < ll > G[maxn];

void DFS (int u)
{
    num_child[u] = 1;
    visited[u] = 1;
    for (int v : G[u])
        if (!visited[v]) p[v] = u , DFS(v);
    for (int v : G[u]) 
        if ( v != p[u] ) num_child[u] += num_child[v];
}
void Heavy_Light_Decomposition(int u)
{
    if (ChainHead[Chain] == 0) ChainHead[Chain] = u ;
    ChainIn[u] = Chain;
    posIn[u] = ++Index;
    int vertex = -1;
    for (int v : G[u])
    {
        if (v != p[u]) 
            if (vertex == -1 || num_child[v] > num_child[vertex]) vertex = v ; 
    }
    if (vertex > -1) Heavy_Light_Decomposition(vertex);
    for (int v : G[u])
        if (v != p[u] && v != vertex) Chain++ , Heavy_Light_Decomposition(v);

}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ; 
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    p[1] = 1;
    DFS(1);
    Heavy_Light_Decomposition(1);
    cout << Chain + 1 << endl;
    for(int i = 0; i <= Chain; i++) cerr << ChainHead[i] << ' ';
    for (int i = 1 ; i <= n ; i++) cout << i << " " <<  posIn[i] << endl;
}