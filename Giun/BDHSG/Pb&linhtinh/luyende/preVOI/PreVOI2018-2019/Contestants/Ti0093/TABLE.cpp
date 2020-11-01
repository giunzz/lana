#define taskname "TABLE"
#include <bits/stdc++.h>

using namespace std;

const int maxn = 318;
const int inf = 1e6;

using Arr = int[maxn][maxn];

int n, m, k, lim, idel, jdel;
Arr a, f, dp;

int Max(int a, int b, int c)
{
    return max(a, max(b, c));
}

void Clear()
{
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = 0;
            dp[i][j] = 0;
        }
    }
}

bool Check(int i, int j, int x, int y, int u, int v)
{
    bool ok = false, oki = false;
    if (i >= 1 && j >= 1 && i <= m && j <= n) ok = true;
    if (a[i][j] != a[x][y] && a[i][j] != a[u][v]) return true;
    if (ok == true && oki == true) return true;
    else return false;
}

int Query(int x, int y, int u, int v)
{
    lim = 0;
    Clear();
    for (int i = x; i <= u; ++i) {
        for (int j = y; j <= v; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            int tmp =  Max(a[i][j], a[i][j-1], a[i-1][j]);
            if (lim < tmp) {
                lim = tmp;
                if (tmp == a[i][j] && Check(i, j, x, y, u, v) == true) idel = i, jdel = j;
                else if (tmp == a[i][j-1] && Check(i, j-1, x, y, u, v) == true) idel = i, jdel = j-1;
                else if (Check(i-1, j, x, y, u, v) == true) idel = i-1, jdel = j;
            }
        }
    }
    int val = a[idel][jdel];
    a[idel][jdel] = -inf;
    for (int i = x; i <= u; ++i) {
        for (int j = y; j <= v; ++j) f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
    }
    a[idel][jdel] = val;
    return f[u][v];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= m; ++i) {
        a[i][0] = -inf;
        a[i][n+1] = -inf;
    }
    for (int i = 1; i <= n; ++i) {
        a[0][i] = -inf;
        a[m+1][i] = -inf;
    }
    for (int i = 1; i <= k; ++i) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << Query(x, y, u, v) << '\n';
    }
}
