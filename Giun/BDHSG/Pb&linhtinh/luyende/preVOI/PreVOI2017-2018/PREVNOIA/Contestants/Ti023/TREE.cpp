#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int nmax = 5000 + 10;
ll n,a[nmax],f[nmax][nmax],dd[nmax],l[nmax],x[nmax],id;
vector <int> adj[nmax];

void DFS(int u)
{
    x[++id] = u;
    dd[u] = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(dd[v] == 0)
        {
            DFS(v);
            l[u] = max(l[v] + 1,l[u]);
        }
    }
}

void con2(int u,int j,ll t)
{
    int v1 = adj[u][0];
    int v2 = adj[u][1];
    for(int k=max(0,j - (1 << (l[u]-1))); k<=min((1<<(l[u]-1)),j); k++)
    {
        f[u][j] = min(f[u][j],f[v1][k] + f[v2][j-k] + t);
    }
}

void con1(int u,int j,ll t)
{
    int v = adj[u][0];
    f[u][j] = f[v][j] + t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    DFS(1);
    for(int i=1; i<=n; i++)
        for(int j=0; j<=5000; j++)
            f[i][j] = 1e15 + 50;
    for(int i=n; i>=1; i--)
    {
        int u = x[i];
        for(int j=0; j<=(1 << l[u]); j++)
        {
            ll t = abs(a[u] - j);
            if(adj[u].size() == 0)
            {
                f[u][j] = t;
                continue;
            }
            else if(adj[u].size() == 2)con2(u,j,t);
            else if(adj[u].size() == 1)con1(u,j,t);
        }
    }
    ll minn = 1e15 + 50;
    for(int j=0; j<=(1 << l[1]); j++)
        minn = min(minn,f[1][j]);
    cout << minn;

    return 0;
}
