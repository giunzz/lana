#include<bits/stdc++.h>

const int maxn = 3e3 + 5;

using namespace std;

int m, n, k;
int a[maxn], b[maxn];

int N, sl, p[2 * maxn], q[2 * maxn], x[2 * maxn], y[2 * maxn], z[2 * maxn];

void Input()
{
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
}

void xuli()
{
    int dem = 0, sly = 0, slz = 0;

    for(int i = 1; i <= N; i++) if(x[i] == 1) dem++;

    if(dem != k) return;

    for(int i = 1; i <= m; i++) if(x[i] == 1) y[++sly] = a[i];

    for(int i = m + 1; i <= m + n; i++) if(x[i] == 1) z[++slz] = b[i - m];

    int tmp = 1;

    for(int i = 1; i <= sly; i++)
    {
        if(y[i] < z[tmp]) p[++sl] = y[i];
        else
        {
            while(z[tmp] <= y[i] && tmp <= slz) p[++sl] = z[tmp], tmp++;
            p[++sl] = y[i];
        }
    }

    for(int i = 1; i <= k; i++)
    {
        if(p[i] < q[i])
        {
            for(int j = 1; j <= k; j++) q[j] = p[j];
            return;
        }
        if(p[i] > q[i]) return;
    }
}

void thu(int k)
{
    if(k > N)
    {
        xuli();
        return;
    }

    for(int i = 0; i <= 1; i++)
    {
        x[k] = i;
        thu(k + 1);
    }
}

void Solve()
{
    N = m + n;

    for(int i = 1; i <= k; i++) q[i] = 2e9;

    thu(1);

    for(int i = 1; i <= k; i++) printf("%d ", q[i]);
}

#define TASK "SEQUENCE"
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
