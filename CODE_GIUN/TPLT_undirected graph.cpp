#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)

int N,M,u,v , visited[(int) 1e5+7] , ans = 0 ;
vector<int>G[(int) 1e5+7];

void DFS (int u)
{
    visited[u]  = 1;
    for (int v : G[u]) 
        if (!visited[v]) DFS(v);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> N >> M;
    for (int i = 1 ; i <= M ; i++) cin >> u >> v , G[u].push_back(v);
    for (int i = 1 ; i <= N ; i++)
        if (!visited[i] ) ans++ , DFS(i);
    cout << ans;
}
