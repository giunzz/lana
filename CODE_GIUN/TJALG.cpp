#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
int N,M,u,v , visited[(int)1e5+7]={0} , cnt = 0 , low[(int)1e5+7]={0} , ans = 0;
vector<int>G[(int) 1e5+7];
stack<int> a;
void DFS (int u)
{
    visited[u] = low[u] = ++cnt ;
    a.push(u);
    for (int v : G[u]) 
    {
        if (visited[v]) low[u] = min(low[u],visited[v]);
        else 
        {
            DFS(v);
            low[u] = min(low[u],low[v]);
        }
    }
    if (visited[u] == low[u])
    {
        ans++;
        do {
            v = a.top();
            a.pop();
            visited[v] = low[v] = INT_MAX;
            } while (u != v);
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
