#include <bits/stdc++.h>

using namespace std;

int a[305][305], t[305][305];
long long f[305][305];

long long solve(int u, int v, int p, int q)
{
    if (u == p || v == q) return a[u][v];
    memset(f, 0, sizeof(f));
    f[u][v] = a[u][v];
    for (int i = v+1; i <= q; ++i)
    {
        f[u][i] = f[u][i-1] + a[u][i];
        t[u][i] = 1;
    }
    for (int i = u+1; i <= p; ++i)
    {
        f[i][v] = f[i-1][v] + a[i][v];
        t[i][v] = 0;
        for (int j = v+1; j <= q; ++j)
            if (f[i-1][j] > f[i][j-1])
            {
                f[i][j] = f[i-1][j] + a[i][j];
                t[i][j] = 0;
            }
            else
            {
                f[i][j] = f[i][j-1] + a[i][j];
                t[i][j] = 1;
            }
    }
    int x1 = p, y1 = q-1, x2 = p-1, y2 = q, d = p-u + q-v, t1, t2;
    while (--d && (x1 != x2 || y1 != y2))
    {
        t1 = t[x1][y1];
        t2 = t[x2][y2];
        x1 -= 1 - t1;
        y1 -= t1;
        x2 -= 1 - t2;
        y2 -= t2;
    }
    if (!d) return min(f[p-1][q], f[p][q-1]) + a[p][q];
    long long ans = min(f[p-1][q], f[p][q-1]) + a[p][q];
    memset(f, 0, sizeof(f));
    f[u][v] = a[u][v];
    for (int i = v+1; i <= q; ++i)
        if (f[u][i-1] && (u != x1 || i != y1))
            f[u][i] = f[u][i-1] + a[u][i];
    for (int i = u+1; i <= p; ++i)
    {
        if (f[i-1][v] && (i != x1 || v != y1)) f[i][v] = f[i-1][v] + a[i][v];
        for (int j = v+1; j <= q; ++j)
            if (i != x1 || j != y1)
                f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j];
    }
    return min(ans, f[p][q]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin >> a[i][j];
        }
    int u, v, p, q;
    while (k--)
    {
        cin >> u >> v >> p >> q;
        cout << solve(u, v, p, q) << '\n';
    }
    return 0;
}
