#include <bits/stdc++.h>

using namespace std;

const int MAXN  =   50000 + 10;
int n, k;
int deg[MAXN], mx, mx2;
vector< int > adj[MAXN];

void Read()
{
    cin>> n >> k;
    int u, v, c;
    for(int i = 1;i < n; i++){
        cin>> u >> v >> c;
        deg[u]++; deg[v]++;
        if (c <= mx) mx2  = c;
        mx = max(mx, c);
        adj[u].push_back(v); adj[v].push_back(u);
    }
}
void Solve()
{
    bool OK = 1;
    int num = 0;
    for(int i = 1; i <= n; i++){
        if (deg[i] > 2) OK = 0;
        if (deg[i] == 1) num++;
    }
    OK&= (num == 2);
    if (OK) cout<< mx2 ;
        else cout<< -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("Bubbletea.inp","r",stdin);
    freopen("Bubbletea.out","w",stdout);
    Read();
    Solve();

}
