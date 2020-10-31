#include <bits/stdc++.h>
#define oo 2000000000

const int maxn = 305;

using namespace std;

int m, n, k;
int a[maxn][maxn], u[maxn], v[maxn], p[maxn], q[maxn], f[maxn][maxn];

void Reset_(int u, int v, int p, int q)
{
    for(int i = u; i <= p; ++i)
        for(int j = v; j <= q; ++j) f[i][j] = 0;
    return;
}

void Solve()
{
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);

    for(int i = 1; i <= k; ++i) scanf("%d %d %d %d", &u[i], &v[i], &p[i], &q[i]);

    for(int i = 1; i <= k; ++i)
    {
        memset(f, 0, sizeof(f));

        for(int i1 = u[i]; i1 <= p[i]; ++i1)
            for(int j1 = v[i]; j1 <= q[i]; ++j1)
                f[i1][j1] = max(f[i1 - 1][j1], f[i1][j1 - 1]) + a[i1][j1];

        int i2 = p[i], j2 = q[i],
            id = -oo, w1 = i2, w2 = j2;

        while(i2 != u[i] && j2 != v[i])
        {
            if(f[i2][j2] == f[i2 - 1][j2] + a[i2][j2])
            {
                i2 --;
                if(id < a[i2][j2] && !((i2 == p[i] && j2 == q[i]) || (i2 == u[i] && j2 == v[i]))) id = a[i2][j2], w1 = i2, w2 = j2;
            }
            if(f[i2][j2] == f[i2][j2 - 1] + a[i2][j2])
            {
                j2 --;
                if(id < a[i2][j2] && !((i2 == p[i] && j2 == q[i]) || (i2 == u[i] && j2 == v[i]))) id = a[i2][j2], w1 = i2, w2 = j2;
            }
        }

        Reset_(u[i], v[i], p[i], q[i]);
        f[w1][w2] = -1;
        for(int i1 = u[i]; i1 <= p[i]; ++i1)
            for(int j1 = v[i]; j1 <= q[i]; ++j1)
                if(f[i1][j1] != -1)
                {
                    if(f[i1 - 1][j1] != -1) f[i1][j1] = max(f[i1][j1], f[i1 - 1][j1]);
                    if(f[i1][j1 - 1] != -1) f[i1][j1] = max(f[i1][j1], f[i1][j1 - 1]);
                    f[i1][j1] += a[i1][j1];
                }

        printf("%d\n", f[p[i]][q[i]]);
    }
}

#define TASK "TABLE"
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
