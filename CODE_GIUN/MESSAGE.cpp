#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)

int N,M,u,v , visited[1000] , cnt = 0 , ans = INT_MAX ;
vector<int>G[1000];

void DFS (int u)
{
    visited[u]  = 1;
    for (int v : G[u]) 
    {
        if (!visited[v]) DFS(v);
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> N >> M;
    for (int i = 1 ; i <= M ; i++) cin >> u >> v , G[u].push_back(v);
    for (int i = 1 ; i <= N ; i++)
        if (!visited[i] ) DFS(i);
    cout << ans;
}
