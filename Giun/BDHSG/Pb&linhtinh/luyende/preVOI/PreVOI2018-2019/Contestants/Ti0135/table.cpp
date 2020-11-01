#include<bits/stdc++.h>

#define maxn 303
#define maxk 82
#define maxm 1000006

#define fi first
#define se second

#define oo 2e18

using namespace std;

int n, m, a[maxn][maxn], dd[maxk][maxk], k, u[maxn], v[maxn], q[maxn], p[maxn], maxa[maxn][maxn];
int64_t f[maxk][maxk], ds = oo, dp[maxn][maxn];

typedef pair<int, int> II;
typedef pair<int, II> III;
III x[maxk * maxk];
II nho[maxm];

bool ok(int i, int j, int g)
{
    if(i == u[g] && j == v[g]) return false;
    if(i == p[g] && j == q[g]) return false;
    return true;
}

void sub1()
{

    for(int g = 1; g <= k; ++g)
    {
        ds = oo;
        int sl = 0;
        for(int i = u[g]; i <= p[g]; ++i)
            for(int j = v[g]; j <= q[g]; ++j)
                if(ok(i, j, g)) x[++sl] = III(a[i][j], II(i, j));
        sort(x + 1, x + 1 + sl);
        for(int i = sl; i >= 1 ; --i)
        {
            for(int i2 = u[g] ; i2 <= p[g]; ++i2)
                for(int j2 = v[g]; j2 <= q[g]; ++j2) f[i2][j2] = 0;
            dd[x[i].se.fi][x[i].se.se] = 1;
            bool ok = true;
            for(int i1 = u[g]; i1 <= p[g]; ++i1)
            {
                for(int j1 = v[g]; j1 <= q[g]; ++j1)
                {
                    if(dd[i1][j1] == 0)
                        f[i1][j1] = max(f[i1 - 1][j1], f[i1][j1 - 1]) + a[i1][j1];
                    else
                        f[i1][j1] = 0;
                    if(f[i1][j1] >= ds)
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok == false)
                    break;
            }
            if(ok == true)
            {
                ds = min(ds, f[p[g]][q[g]]);
            }
            dd[x[i].se.fi][x[i].se.se] = 0;
            a[x[i].se.fi][x[i].se.se] = x[i].fi;
        }

        printf("%I64d\n", ds);
    }

}

void sub2()
{

    for(int g = 1; g <= k; ++g)
    {

        for(int i = u[g]; i <= p[g]; ++i)
            for(int j = v[g]; j <= q[g]; ++j) dp[i][j] = 0;
        for(int i = u[g]; i <= p[g]; ++i)
            for(int j = v[g]; j <= q[g]; ++j)
        {
            nho[a[i][j]] = II(i, j);
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            if(dp[i][j] == dp[i - 1][j] + a[i][j] && ok(i, j, g)){maxa[i][j] = max(maxa[i - 1][j], a[i][j]);}
            else if(ok(i, j, g)) maxa[i][j] = max(maxa[i][j - 1], a[i][j]);
            if(!ok(i, j, g)) maxa[i][j] = max(maxa[i][j - 1], maxa[i - 1][j]);
        }

         II u1 = nho[maxa[p[g]][q[g]]];
         int b = a[u1.fi][u1.se];
         a[u1.fi][u1.se] = 0;
        for(int i = u[g]; i <= p[g]; ++i)
            for(int j = v[g]; j <= q[g]; ++j) dp[i][j] = 0;
        for(int i = u[g]; i <= p[g]; ++i)
            for(int j = v[g]; j <= q[g]; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            if(dp[i][j] == dp[i - 1][j] + a[i][j] && ok(i, j, g)){maxa[i][j] = max(maxa[i - 1][j], a[i][j]);}
        }
        a[u1.fi][u1.se] = b;
        printf("%I64d\n", dp[p[g]][q[g]]);
    }

}

int main()
{
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);

    scanf("%d %d %d", &m, &n, &k);

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);

    for(int i = 1; i <= k; ++i)
        scanf("%d %d %d %d", &u[i], &v[i], &p[i], &q[i]);
    if(n <= 30)
        sub1();
    else
        sub2();
}
