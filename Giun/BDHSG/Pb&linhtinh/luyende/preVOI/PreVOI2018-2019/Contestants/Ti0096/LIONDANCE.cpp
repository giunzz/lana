#include <bits/stdc++.h>

using namespace std;

int zReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res*10 + c - '0';
    return res;
}

void zWriteInt(const int &x)
{
    if (x > 9) zWriteInt(x/10);
    putchar(x%10 + '0');
}

const int maxn = 4005;
int n, L[maxn], R[maxn], dt;
void zEnter()
{
    n = zReadInt(); dt = zReadInt();
    for (int i = 1; i <= n; ++i) L[i] = zReadInt();
    for (int i = 1; i <= n; ++i) R[i] = zReadInt();
}

int F[maxn][maxn];
pair<int, int> p[maxn][maxn];
void zSolve1()
{
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) if (L[i] == R[j])
    {
        F[i][j] = 1; p[i][j] = {0, 0};
        for (int u = 0; u < i; ++u) if (abs(L[i] - L[u]) <= dt)
            for (int v = 0; v < j; ++v) if (L[u] == R[v])
        {
            if (F[i][j] < F[u][v] + 1) F[i][j] = F[u][v] + 1, p[i][j] = {u, v};
            else if (F[i][j] == F[u][v] + 1 && L[p[i][j].first] < L[u]) p[i][j] = {u, v};
        }
        if (F[x][y] < F[i][j]) x = i, y = j;
        else if (F[x][y] == F[i][j] && L[x] <= L[i]) x = i, y = j;
    }
    zWriteInt(F[x][y]); putchar('\n');
    while (F[x][y])
    {
        zWriteInt(L[x]); putchar(' ');
        int u = p[x][y].first, v = p[x][y].second;
        x = u; y = v;
    }
}

int c[maxn], mem[maxn], c1[maxn], mem1[maxn];
void zSolve2()
{
    for (int j = 1; j <= n; ++j) c[j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int Fmax = 1, prv = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (L[i] == R[j])
            {
                c1[j] = c[j]; mem1[j] = mem[j];
                if (c1[j] < Fmax) c1[j] = Fmax, mem1[j] = prv;
                else if (c1[j] == Fmax && R[mem1[j]] < R[prv]) mem1[j] = prv;
            }
            if (abs(L[i] - R[j]) <= dt)
            {
                if (Fmax < c[j] + 1) Fmax = c[j] + 1, prv = (c[j] != 0) ? j : 0;
                else if (Fmax == c[j] + 1 && R[prv] < R[j]) prv = (c[j] != 0) ? j : 0;
            }
        }
        for (int j = 1; j <= n; ++j) if (L[i] == R[j]) c[j] = c1[j], mem[j] = mem1[j];
    }
    int u = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (c[u] < c[i]) u = i;
        else if (c[u] == c[i] && R[u] <= R[i]) u = i;
    }
    zWriteInt(c[u]); putchar('\n');
    while (u)
    {
        zWriteInt(R[u]); putchar(' ');
        u = mem[u];
    }
}

void zSolve()
{
    reverse(L + 1, L + n + 1);
    reverse(R + 1, R + n + 1);
    if (n <= 20) zSolve1();
    else zSolve2();
}

#define task "LIONDANCE"
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    zEnter();
    zSolve();
}
