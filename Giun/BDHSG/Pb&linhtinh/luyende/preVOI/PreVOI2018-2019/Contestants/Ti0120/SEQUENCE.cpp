#include <bits/stdc++.h>
#define ft first
#define sc second

const int maxn = 3005;

using namespace std;

int m, n, k;
int a[maxn], b[maxn], f[maxn], g[maxn], prf[maxn], prg[maxn], da[maxn], db[maxn];
typedef pair<int, int> II;
typedef pair<II, int> III;
III x[maxn];

void Solve()
{
    scanf("%d %d %d", &m ,&n, &k);
    for(int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);

    f[1] = 1;
    for(int i = 2; i <= m; ++i)
        for(int j = 1; j < i; ++j)
            if(a[j] <= a[i])
            {
                if(f[i] < f[j] + 1) f[i] = f[j] + 1, prf[i] = j;
                else if(f[i] == f[j] + 1) if(prf[i] != 0 && a[prf[i]] > a[j]) prf[i] = j;
            }

    g[1] = 1;
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j < i; ++j)
            if(b[j] <= b[i])
            {
                if(g[i] < g[j] + 1) g[i] = g[j] + 1, prg[i] = j;
                else if(g[i] == g[j] + 1) if(prg[i] != 0 && b[prg[i]] > b[j]) prg[i] = j;
            }

    int maxf = 0, maxg = 0, idf = 0, idg = 0, slx = 0;
    for(int i = 1; i <= m; ++i) if(maxf < f[i]) maxf = f[i], idf = i; else if(maxf == f[i] && a[idf] > a[i]) idf = i;
    for(int i = 1; i <= n; ++i) if(maxg < g[i]) maxg = g[i], idg = i; else if(maxg == g[i] && b[idg] > b[i]) idg = i;

    while(idf > 0)
    {
        x[++slx] = III(II(a[idf], idf), 1); da[idf] = 1;
        idf = prf[idf];
    }
    while(idg > 0)
    {
        x[++slx] = III(II(b[idg], idg), 2); db[idg] = 1;
        idg = prg[idg];
    }

    sort(x + 1, x + slx + 1);
    if(slx < k)
    {
        int i = m, j = n;
        while(slx < k && (j > 0 || i > 0))
        {
            while(db[j] == 1) j --;
            while(da[i] == 1) i --;

            if(db[j] == 0 && j > 0)
            {
                if(da[i] == 0) if(b[j] <= a[i]) x[++slx] = III(II(b[j], j), 2), db[j] = 1, j --;
                              else x[++slx] = III(II(a[i], i), 1), da[i] = 1, i --;
                else x[++slx] = III(II(b[j], j), 2), db[j] = 1, --j;
            }
            else if(da[i] == 0) x[++slx] = III(II(a[i], i), 1), da[i] = 1, i --;
        }

        for(int i = 1; i <= slx; ++i)
            for(int j = i + 1; j <= slx; ++j)
                if(x[i].sc == x[j].sc) {if(x[i].ft.sc > x[j].ft.sc) swap(x[i], x[j]);}
                else if(x[i].ft.ft > x[j].ft.ft) swap(x[i], x[j]);
    }

    while(slx > k) slx --;

    for(int i = 1; i <= slx; ++i)
        printf("%d ", x[i].ft.ft);
}

#define TASK "SEQUENCE"
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
