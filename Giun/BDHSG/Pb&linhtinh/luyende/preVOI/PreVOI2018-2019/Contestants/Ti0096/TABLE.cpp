#include <bits/stdc++.h>

using namespace std;

int zReadInt()
{
    char c;
    for (c = getchar(); c != '-' && (c < '0' || c > '9'); c = getchar());
    int res, sgn;
    if (c == '-') res = 0, sgn = -1;
    else res = c - '0', sgn = 1;
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res*10 + c - '0';
    return res*sgn;
}

void zWriteInt(const int64_t &x)
{
    if (x < 0)
    {
        putchar('-'); zWriteInt(-x);
        return;
    }
    if (x > 9) zWriteInt(x/10);
    putchar(x%10 + '0');
}

const int maxn = 305;
int m, n, k, a[maxn][maxn];
void zEnter()
{
    m = zReadInt(); n = zReadInt(); k = zReadInt();
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) a[i][j] = zReadInt();
}

int64_t dp[maxn][maxn][2];
void zSolve()
{
    for (; k; --k)
    {
        int u = zReadInt(), v = zReadInt(), p = zReadInt(), q = zReadInt();
        dp[u - 1][v - 1][0] = dp[u - 1][v - 1][1] = 0;
        for (int i = u; i <= p; ++i) dp[i][v - 1][0] = dp[i][v - 1][1] = 0;
        for (int i = v; i <= q; ++i) dp[u - 1][i][0] = dp[i][v - 1][1] = 0;
        for (int i = u; i <= p; ++i) dp[i][v][0] = dp[i - 1][v][0] + a[i][v], dp[i][v][1] = 0;
        for (int i = v; i <= q; ++i) dp[u][i][0] = dp[u][i - 1][0] + a[u][i], dp[u][i][1] = 0;
        for (int i = u + 1; i <= p; ++i)
            for (int j = v + 1; j <= q; ++j)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + a[i][j];
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + a[i][j];
            if (dp[i - 1][j][1] || dp[i][j - 1][1])
                dp[i][j][1] = min(dp[i][j][1], max(dp[i - 1][j][1], dp[i][j - 1][1]) + a[i][j]);
        }
        zWriteInt(dp[p][q][1]); putchar('\n');
    }
}

#define task "TABLE"
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    zEnter();
    zSolve();
}
