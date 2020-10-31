#include <bits/stdc++.h>
using namespace std;
#define ft(i,x,y) for (int i = x; i <= y; ++i)
const int maxn = 5e3+2;
int n,a[maxn],p[maxn];
vector<int> d[maxn];
int cnt_leaf[maxn];
long long f[maxn][maxn],ans;
bool vis[maxn];
void Enter()
{
    scanf("%d",&n);
    ft(i,1,n) scanf("%d",&a[i]);
    ft(i,1,n-1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        d[u].push_back(v);
        d[v].push_back(u);
    }
}
void dfs(int u)
{
    vis[u] = 1;
    cnt_leaf[u] = 0;
    if (d[u].size() == 1 && u != 1)
    {
        f[u][0] = a[u];
        f[u][1] = abs(a[u] - 1);
        cnt_leaf[u] = 1;
        return;
    }
    for (int i = 0,v; i < d[u].size(); i++)
    {
        v = d[u][i];
        if (vis[v]) continue;
        p[v] = u;
        dfs(v);
        cnt_leaf[u] += cnt_leaf[v];
    }
    if (u == 1) return;
    int v = 0;
    if (d[u].size() == 2)
    {
        if (d[u][0] == p[u]) v = d[u][1];
            else v = d[u][0];
        for (int k = 0; k <= cnt_leaf[u]; k++)
            if (f[v][k] > -1)
            f[u][k] = f[v][k] + abs(a[u] - k);
    }
    else
    {
        int i,j;
        for (i = 0; i < d[u].size(); i++) if (d[u][i] == p[u]) break;
        if (i != 0)
        {
            j = d[u][0]; i = d[u][3 - i];
        }
        else
        {
            j = d[u][1]; i = d[u][2];
        }
        for (int k = 0; k <= cnt_leaf[u]; k++)
            for (int l = 0; l <= k; l++)
                f[u][k] = min(f[i][l] + f[j][k - l] + abs(a[u] - k),f[u][k]);
    }
}
void Solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++) f[i][j] = 1e9;
    dfs(1);
    ans = 1e9;
    if (d[1].size() == 0) {cout<<min(a[1],abs(a[1] - 1)); return;}
    if (d[1].size() == 1)
    {
        int u = d[1][0];
        for (int i = 0; i <= cnt_leaf[1]; i++)
            ans = min(ans,f[u][i] + abs(a[1] - i));
        cout<<ans;
        return;
    }
    int i = d[1][0], j = d[1][1];
    for (int k = 0; k <= cnt_leaf[1]; k++)
        for (int l = 0; l <= k; l++)
            ans = min(ans,f[i][l] + f[j][k-l] + abs(a[1] - k));
    cout<<ans;
    return;
}
int main()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    Enter();
    Solve();
}
