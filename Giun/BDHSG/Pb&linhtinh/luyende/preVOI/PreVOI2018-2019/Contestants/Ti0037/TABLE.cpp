#include <bits/stdc++.h>
#define maxn 309
#define Nlog 10

using namespace std;

const long long oo = 1000000000000;

long long m, n, k, A[maxn][maxn], U[maxn], V[maxn], P[maxn], Q[maxn], F[maxn][maxn], kq, maxx1[maxn][maxn][Nlog], maxx2[maxn][maxn][Nlog], D[maxn][maxn], G[maxn][maxn];

void nhapdl()
{
    scanf("%lld%lld%lld", &m, &n, &k);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        scanf("%lld", &A[i][j]);
    for (int i = 1; i <= k; i++)
        scanf("%lld%lld%lld%lld", &U[i], &V[i], &P[i], &Q[i]);
}
void RMQ1(int u, int v, int p, int q)
{
    for (int i = u; i <= p; i++)
    {
        for (int j = v; j <= q; j++) maxx1[i][j][0] = D[i][j];
        for (int k = 1; (1<<k) <= q - v + 1; k++)
        for (int h = 1; h <= (q - v + 1) - (1<<k) + 1; h++)
            maxx1[i][h][k] = max(maxx1[i][h][k - 1], maxx1[i][h + (1<<(k - 1))][k - 1]);
    }
}
void RMQ2(int u, int v, int p, int q)
{
    for (int i = v; i <= q; i++)
    {
        for (int j = u; j <= p; j++) maxx2[i][j][0] = D[j][i];
        for (int k = 1; (1<<k) <= p - u + 1; k++)
        for (int h = 1; h <= (p - u + 1) - (1<<k) + 1; h++)
            maxx2[i][h][k] = max(maxx2[i][h][k - 1], maxx2[i][h + (1<<(k - 1))][k - 1]);
    }
}
long long getmax1(int i, int u, int v)
{
    if (u > v) return -oo;
    int k = log2(v - u + 1);
    return max(maxx1[i][u][k], maxx1[i][v - (1<<k) + 1][k]);
}
long long getmax2(int i, int u, int v)
{
    if (u > v) return -oo;
    int k = log2(v - u + 1);
    return max(maxx2[i][u][k], maxx2[i][v - (1<<k) + 1][k]);
}
void xuli1()
{
    for (int query = 1; query <= k; query++)
    {
        kq = oo;
        for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            F[i][j] = 0;
        for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if ((U[query] != i || V[query] != j) && (P[query] != i || Q[query] != j))
            {
                for (int u = U[query]; u <= P[query]; u++)
                for (int v = V[query]; v <= Q[query]; v++)
                    if (u != i || v != j)
                    {
                        F[u][v] = -oo;
                        if (u != i || v - 1 != j)
                            F[u][v] = max(F[u][v], F[u][v - 1] + A[u][v]);
                        if (u - 1 != i || v != j)
                            F[u][v] = max(F[u][v], F[u - 1][v] + A[u][v]);
                    }
                kq = min(kq, F[P[query]][Q[query]]);
            }
            printf("%lld\n", kq);
    }
}
void xuli2()
{
    long long res, cmp1, cmp2, cmp3, cmp4;
    for (int u, v, p, q, query = 1; query <= k; query++)
    {
        kq = oo;
        for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            F[i][j] = 0;
            G[i][j] = 0;
            for (int h = 1; h <= Nlog; h++)
            {
                maxx1[i][j][h] = 0;
                maxx2[j][i][h] = 0;
            }
        }
        u = U[query]; v = V[query]; p = P[query]; q = Q[query];
        for (int i = u; i <= p; i++)
        for (int j = v; j <= q; j++)
        {
            F[i][j] = -oo;
            F[i][j] = max(F[i][j], max(F[i - 1][j], F[i][j - 1]) + A[i][j]);
        }
        for (int i = p ; i >= u; i--)
        for (int j = q ; j >= u; j--)
        {
            G[i][j] = -oo;
            G[i][j] = max(G[i][j], max(G[i + 1][j], G[i][j + 1]) + A[i][j]);
        }
        for (int i = u; i <= p; i++)
        for (int j = v; j <= q; j++)
            D[i][j] = F[i][j] + G[i][j] - A[i][j];
        RMQ1(u, v, p, q);
        RMQ2(u, v, p, q);
        for (int i = u; i <= p; i++)
        for (int j = v; j <= q; j++)
            if ((i != u || j != v) && (i != p || j != q))
            {
                if (i + 1 <= p) cmp1 = getmax1(i + 1, v, j - 1);
                else cmp1 = -oo;
                if (j + 1 <= q) cmp2 = getmax2(j + 1, u, i - 1);
                else cmp2 = -oo;
                cmp3 = max(F[i + 1][j - 1] + G[i + 1][j], F[i - 1][j + 1] + G[i][j + 1]);
                cmp4 = max(F[i + 1][j - 1] + A[i + 1][j], F[i - 1][j + 1] + A[i][j + 1]) + G[i + 1][j + 1];
                res = max(cmp1, max(cmp2, max(cmp3, cmp4)));
                kq = min(kq, res);
            }
        printf("%lld\n", kq);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);

    nhapdl();
    if (m <= 30 && n <= 30) xuli1(); else xuli2();
}
