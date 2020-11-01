#include<bits/stdc++.h>

const int maxn = 305;
const int64_t INF = 2e18;

using namespace std;

int m, n, k;
int a[maxn][maxn], u[maxn], v[maxn], p[maxn], q[maxn];

int b[maxn][maxn];
int64_t dp[maxn][maxn];

void Input()
{
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    }


    for(int i = 1; i <= k; i++) scanf("%d %d %d %d", &u[i], &v[i], &p[i], &q[i]);
}

void sub1()
{
    int64_t gmin;

    for(int t = 1; t <= k; t++)
    {
        int X1 = u[t], X2 = p[t], Y1 = v[t], Y2 = q[t];
        gmin = INF;

        for(int i = X1; i <= X2; i++)
        {
            for(int j = Y1; j <= Y2; j++)
            {

                for(int x = X1; x <= X2; x++)
                {
                    for(int y = Y1; y <= Y2; y++) dp[x][y] = 0;
                }

                b[i][j] = -1, dp[X1][Y1] = a[X1][Y1];

                if((i != X1 && j != Y1) || (i != X2 && j != Y2))
                {
                    for(int x = X1 + 1; x <= X2; x++)
                    {
                        if(b[x][Y1] != -1) dp[x][Y1] = dp[x - 1][Y1] + a[x][Y1];
                        else break;
                    }

                    for(int y = Y1 + 1; y <= Y2; y++)
                    {
                        if(b[X1][y] != -1) dp[X1][y] = dp[X1][y - 1] + a[X1][y];
                        else break;
                    }

                    for(int x = X1 + 1; x <= X2; x++)
                    {
                        for(int y = Y1 + 1; y <= Y2; y++)
                        {
                            if(b[x - 1][y] != -1) dp[x][y] = max(dp[x][y], dp[x - 1][y] + a[x][y]);
                            if(b[x][y - 1] != -1) dp[x][y] = max(dp[x][y], dp[x][y - 1] + a[x][y]);
                        }
                    }

                    gmin = min(gmin, dp[X2][Y2]);
                }

                b[i][j] = 0;
            }
        }

        printf("%I64d\n", gmin);
    }
}

void Solve()
{
    if((m <= 30 && n <= 30) && k <= 30) sub1();
    else sub1();
}

#define TASK "TABLE"
int main()
{
    #ifdef TASK
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    #else
    freopen("1.inp", "r", stdin);
    #endif // TASK
    Input();
    Solve();
}
