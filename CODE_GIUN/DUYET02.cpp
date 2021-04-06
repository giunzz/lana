#include<bits/stdc++.h>
const long long maxn=100007;
using namespace std;
long long n,m,u,v,visited[maxn]={0};
vector<long long> G[maxn];
void BFS(long long node){
    queue<long long> q;
    cout << node << " ";
    visited[node]=1;
    q.push(node);
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        for(int v : G[u]){
            if(!visited[v]) cout << v << " ", q.push(v), visited[v]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout.tie(0);
    freopen("DUYET02.INP","r",stdin);
    freopen("DUYET02.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> u >> v; 
        G[u].push_back(v);
        G[v].push_back(u);
    }
    BFS(1);
    return 0;
}