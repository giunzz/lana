#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 307;

int n, m, a[maxn][maxn], k, Max[maxn][maxn], ans = LLONG_MIN;
int Max2[maxn][maxn], Trace[maxn][maxn];

void Try(int x, int y, int u, int v, int xcam, int ycam)
{
    if(xcam == x && ycam == y) return;
    int ansphu = LLONG_MIN;
    if(xcam > x)
    {
        for(int j = ycam + 1; j <= v; j++)
        {
            ansphu = max(ansphu, Max[xcam - 1][j] + Max2[xcam][j]);
        }
    }
    if(ycam > y)
    {
        for(int i = xcam + 1; i <= u; i++)
        {
            ansphu = max(ansphu, Max[i][ycam - 1] + Max2[i][ycam]);
        }
    }
    ans = min(ans, ansphu);
}

void Solve(int x, int y, int u, int v)
{
    ans = LLONG_MAX;
    Max[x][y] = a[x][y];
    Trace[x][y] = -1;
    for(int i = x; i <= u; i++)
    {
        for(int j = y; j <= v; j++)
        {
            if(i == x && j == y) continue;
            Max[i][j] = LLONG_MIN;
            if(i > x && Max[i][j] < Max[i - 1][j] + a[i][j]) Max[i][j] = Max[i - 1][j] + a[i][j], Trace[i][j] = 0;
            if(j > y && Max[i][j] < Max[i][j - 1] + a[i][j]) Max[i][j] = Max[i][j - 1] + a[i][j], Trace[i][j] = 1;
        }
    }
    Max2[u][v] = a[u][v];
    for(int i = u; i >= x; i--)
    {
        for(int j = v; j >= y; j--)
        {
            if(i == u && j == v) continue;
            Max2[i][j] = LLONG_MIN;
            if(i < u && Max2[i][j] < Max2[i + 1][j] + a[i][j]) Max2[i][j] = Max2[i + 1][j] + a[i][j];
            if(j < v && Max2[i][j] < Max2[i][j + 1] + a[i][j]) Max2[i][j] = Max2[i][j + 1] + a[i][j];
        }
    }
    int curx = u, cury = v;
    while(Trace[curx][cury] != -1)
    {
        if(Trace[curx][cury] == 0)
        {
            curx--;
            Try(x, y, u, v, curx, cury);
        }
        else
        {
            cury--;
            Try(x, y, u, v, curx, cury);
        }
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        Solve(x, y, u, v);
    }
}
