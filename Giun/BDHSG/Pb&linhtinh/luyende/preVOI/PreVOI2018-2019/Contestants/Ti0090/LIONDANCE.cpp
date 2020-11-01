#include<bits/stdc++.h>

const int maxn = 4e3 + 5;

using namespace std;

int n, delta;
int L[maxn], R[maxn];

int x[maxn], y[maxn], p[maxn], ds = 0;
int dp[maxn][maxn];

void Input()
{
    scanf("%d %d", &n, &delta);

    for(int i = 1; i <= n; i++) scanf("%d", &L[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &R[i]);
}

void xuli()
{
    int sl = 0;

    for(int i = 1; i <= n; i++) if(x[i] == 1) sl++;

    if(sl < ds) return;

    sl = 0;

    for(int i = 1; i <= n; i++) if(x[i] == 1) y[++sl] = L[i];

    y[0] = y[1];
    for(int i = 1; i <= sl; i++) if(abs((int64_t)y[i] - y[i - 1]) > (int64_t)delta) return;

    int cnt = 1;

    for(int i = 1; i <= n; i++)
    {
        if(R[i] == y[cnt]) cnt++;
        if(cnt == sl + 1) break;
    }

    if(cnt <= sl) return;

    if(sl > ds)
    {
        for(int i = 1; i <= sl; i++) p[i] = y[i];
        ds = sl;
    }
    else
    {
        if(sl == ds)
        {
            for(int i = 1; i <= sl; i++)
            {
                if(y[i] > p[i])
                {
                    for(int j = 1; j <= sl; j++) p[j] = y[j];
                    return;
                }
                if(y[i] < p[i]) return;
            }
        }
    }
}

void thu(int k)
{
    if(k > n)
    {
        xuli();
        return;
    }

    for(int i = 1; i >= 0; i--)
    {
        x[k] = i;
        thu(k + 1);
    }
}

void sub1()
{
    thu(1);

    printf("%d\n", ds);

    for(int i = 1; i <= ds; i++) printf("%d ", p[i]);
}

void sub2()
{
    for(int i = 1; i <= n; i++)
    {
        if(R[i] == L[1]) dp[1][i] = 1;
        else dp[1][i] = dp[1][i - 1];

        if(L[i] == R[1]) dp[i][1] = 1;
        else dp[i][1] = dp[i - 1][1];
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            if(L[i] == R[i])
            {
                for(int p = i - 1; p >= 1; p--)
                {
                    for(int q = j - 1; q >= 1; q--)
                    {
                        int gmax = 0;

                        if(L[p] == R[q] && abs((int64_t)L[p] - L[i]) <= (int64_t)delta)
                        {
                            if(dp[i][j] < dp[p][q] + 1)
                            {
                                dp[i][j] = dp[p][q] + 1;
                                gmax = L[p];
                            }
                            else
                            {
                                if(dp[i][j] == dp[p][q] + 1 && L[p] > gmax)
                                {
                                    dp[i][j] = dp[p][q] + 1;
                                    gmax = L[p];
                                }
                            }
                        }
                    }
                }
            }
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int u, v, sl = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dp[i][j] > ds) ds = dp[i][j], u = i, v = j;
        }
    }

    while(u > 0 && v > 0)
    {
        if(L[u] == R[v]) p[++sl] = L[u], u--, v--;
        else
        {
            if(dp[u - 1][v] > dp[u][v - 1]) u--;
            else v--;
        }
    }

    printf("%d\n", ds);
    for(int i = ds; i >= 1; i--) printf("%d ", p[i]);
}

void sub3()
{
    for(int i = 1; i <= n; i++)
    {
        if(R[i] == L[1]) dp[1][i] = 1;
        else dp[1][i] = dp[1][i - 1];

        if(L[i] == R[1]) dp[i][1] = 1;
        else dp[i][1] = dp[i - 1][1];
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            if(L[i] == R[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int u, v, sl = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dp[i][j] > ds) ds = dp[i][j], u = i, v = j;
        }
    }

    while(u > 0 && v > 0)
    {
        if(L[u] == R[v]) p[++sl] = L[u], u--, v--;
        else
        {
            if(dp[u - 1][v] > dp[u][v - 1]) u--;
            else v--;
        }
    }

    printf("%d\n", ds);
    for(int i = ds; i >= 1; i--) printf("%d ", p[i]);
}

void Solve()
{
    if(n <= 20) sub1();
    else
    {
        if(n <= 100) sub2();
        else sub3();
    }
}

#define TASK "LIONDANCE"
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
