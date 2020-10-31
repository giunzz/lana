#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int m, n, k, u, v, p, q, x, y;
long long a[305][305], f[2][305][305], tc[2][305][305], g[2], kq;
void nhap()
{
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) scanf("%lld", &a[i][j]);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    nhap();
    while(k--)
    {
        scanf("%d%d%d%d", &u, &v, &p, &q);
        memset(f, -60, sizeof(f));
        f[0][u-1][v] = f[1][p+1][q] = 0;
        for(int i = u; i <= p; ++i)
            for(int j = v; j <= q; ++j)
            {
                if(f[0][i-1][j] > f[0][i][j-1]) tc[0][i][j] = 0;
                else tc[0][i][j] = 1;
                f[0][i][j] = max(f[0][i-1][j], f[0][i][j-1]) + a[i][j];
            }
        for(int i = p; i >= u; --i)
            for(int j = q; j >= v; --j)
            {
                tc[1][i][j] = f[1][i][j] = max(f[1][i+1][j], f[1][i][j+1]);
                f[1][i][j] += a[i][j];
            }
        x = p, y = q;
        kq = 1e18, g[0] = g[1] = -1e18;
        while(x-u+y-v > 1)
        {
            if(!tc[0][x][y])
            {
                g[1] = max(g[1], f[0][x][y-1]+f[1][x][y]);
                x--;
                g[0] = -1e18;
                for(int i = q; i > y; --i) g[0] = max(g[0], f[0][x-1][i]+f[1][x][i]);
            }
            else
            {
                g[0] = max(g[0], f[0][x-1][y]+f[1][x][y]);
                y--;
                g[1] = -1e18;
                for(int i = p; i > x; --i) g[1] = max(g[1], f[0][i][y-1]+f[1][i][y]);
            }
            kq = min(kq, max(g[0], g[1]));
        }
        printf("%lld\n", kq);
    }
}
