#include <bits/stdc++.h>
#define maxn 5000
#define oo 100000000

using namespace std;

int n, kq, A[maxn], P[maxn], x[maxn], KQ[maxn], B[maxn], delta;

void xuli()
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
        if (x[i] == 1)
        {
            if (abs(A[i] - P[dem]) <= delta || dem == 0) P[++dem] = A[i];
            else return;
        }
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        if (B[i] == P[j]) j++;
    }
    if (j != dem + 1) return;
    if (dem < kq) return;
    if (dem > kq)
    {
        kq = dem;
        for (int i = 1; i <= dem; i++)
            KQ[i] = P[i];
        return;
    }
    for (int i = 1; i <= dem; i++)
    {
        if (KQ[i] > P[i]) return;
        if (P[i] > KQ[i])
        {
            for (int k = 1; k <= dem; k++)
                KQ[k] = P[k];
            return;
        }
    }
}
void tryLION(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n) xuli();
        else tryLION(i + 1);
    }
}
void process()
{
    kq = -oo;
    tryLION(1);
    printf("%d\n", kq);
    for (int i = 1; i <= kq; i++) printf("%d ", KQ[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);

    scanf("%d%d", &n, &delta);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    process();
}
