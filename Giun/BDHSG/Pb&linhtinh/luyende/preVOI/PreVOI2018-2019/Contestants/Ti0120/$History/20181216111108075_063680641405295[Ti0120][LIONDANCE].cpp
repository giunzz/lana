#include <bits/stdc++.h>

const int maxn = 4005;

using namespace std;

int n, k, a[maxn], b[maxn], f[maxn][maxn], pre[maxn][maxn], x[maxn], c[maxn];

void Solve()
{
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int j = 1; j <= n; ++j) scanf("%d", &b[j]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            f[i][j] = max(f[i][j], max(f[i - 1][j], f[i][j - 1]));
            if(a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
        }

    printf("%d\n", f[n][n]);

    int u = n, v = n, slx = 0;
    while(u > 0 && v > 0)
    {
        if(a[u] == b[v]) x[++slx] = a[u], --u, --v;
        if(f[u][v] == f[u - 1][v]) u--;
        if(f[u][v] == f[u][v - 1]) v--;
    }

    for(int i = slx; i >= 1; --i) printf("%d ", x[i]);
}

#define TASK "LIONDANCE"
int main()
{
    #ifdef TASK
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK

    Solve();
}
