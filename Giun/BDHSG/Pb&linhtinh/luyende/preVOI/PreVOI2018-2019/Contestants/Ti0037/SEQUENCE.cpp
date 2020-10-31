#include <bits/stdc++.h>
#define maxn 3001
#define oo 1000000000

using namespace std;

int m, n, k, KQ[maxn], P[maxn], F[maxn][maxn], G[maxn][maxn], A[maxn], B[maxn];

void nhapdl()
{
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
}
void prepare()
{
    int res, cmp;
    A[0] = oo;
    for (int i = 1; i <= m; i++)
    {
        res = 0;
        for (int j = 1 ; j <= i; j++)
        {
            cmp = 0;
            for (int kk = res + 1; kk <= m; kk++)
                if (A[kk] < A[cmp] && m - kk >= i - j)
                    cmp = kk;
            F[i][j] = cmp;
            res = cmp;
        }
    }
    B[0] = oo;
    for (int i = 1; i <= n; i++)
    {
        res = 0;
        for (int j = 1 ; j <= i; j++)
        {
            cmp = 0;
            for (int kk = res + 1; kk <= n; kk++)
                if (B[kk] < B[cmp] && n - kk >= i - j)
                    cmp = kk;
            G[i][j] = cmp;
            res = cmp;
        }
    }
}
void xuli()
{
    prepare();
    for (int i = 1; i <= k; i++) KQ[i] = oo;
    for (int len = 0; len <= min(m, k); len++)
        if (k - len <= n)
        {
            int i = 1, j = 1, dem = 0;
            while (i <= len || j <= k - len)
            {
                if (A[F[len][i]] <= B[G[k - len][j]])
                {
                    P[++dem] = A[F[len][i]];
                    i++;
                }
                else
                {
                    P[++dem] = B[G[k - len][j]];
                    j++;
                }
            }
            for (int l = 1; l <= k; l++)
                if (P[l] > KQ[l]) break;
                else
                {
                    if (P[l] < KQ[l])
                    {
                        for (int h = 1; h <= k; h++)
                            KQ[h] = P[h];
                        break;
                    }
                }
        }
    for (int i = 1; i <= k; i++) printf("%d ", KQ[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);

    nhapdl();
    xuli();
}
