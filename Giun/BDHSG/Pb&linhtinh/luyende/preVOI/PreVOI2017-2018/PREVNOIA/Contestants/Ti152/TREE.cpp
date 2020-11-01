#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int n, a[5005], b[1005], f[5005][5005], tp[5005], d = 0;
vector<int> vr[5005];
void nhap()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        vr[u].pb(v);
    }
}
void dfs(int u)
{
    tp[++d] = u;
    if(!vr[u].size())
    {
        b[u] = 1;
        return;
    }
    for(int &v : vr[u]) dfs(v), b[u] += b[v];
}
main()
{
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);
    nhap();
    dfs(1);
    for(int i = 0; i <= b[1]; ++i) f[0][i] = 0;
    for(int i = n; i; --i)
    {
        int u = tp[i];
        if(!vr[u].size())
        {
            f[u][0] = a[u];
            f[u][1] = abs(a[u]-1);
        }
        else
        {
            int v1 = vr[u][0], v2 = 0;
            if(vr[u].size() > 1) v2 = vr[u][1];
            for(int j = 0; j <= b[u]; ++j) f[u][j] = 1e9;
            for(int j1 = 0; j1 <= b[v1]; ++j1)
                for(int j2 = 0; j2 <= b[v2]; ++j2) f[u][j1+j2] = min(f[u][j1+j2], f[v1][j1]+f[v2][j2]+abs(a[u]-j1-j2));
        }
    }
    int s = 1e9;
    for(int i = 0; i <= b[1]; ++i) s = min(s, f[1][i]);
    printf("%d", s);
}
