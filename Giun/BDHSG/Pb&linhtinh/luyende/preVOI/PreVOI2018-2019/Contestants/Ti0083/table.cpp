#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[307][307], f[307][307];

int calc(int x, int y, int u, int v){
    for (int i=x-1; i<=u; ++i)
        for (int j=y-1; j<=v; ++j) f[i][j]=0;
    f[x][y]=a[x][y];

    for (int i=x; i<=u; ++i)
        for (int j=y; j<=v; ++j)
        {
            f[i][j]=max(f[i-1][j] + a[i][j], f[i][j]);
            f[i][j]=max(f[i][j-1] + a[i][j], f[i][j]);
        }
    return f[u][v];
}

int main(){
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) scanf("%d", &a[i][j]);

    while (k--)
    {
        int u, v, p, q; scanf("%d%d%d%d", &u, &v, &p, &q);
        int mn=1e9;
        for (int i=u; i<=p; ++i)
            for (int j=v; j<=q; ++j)
            {
                if (i == u && j == v) continue;
                if (i == p && j == q) continue;
                int tg=a[i][j]; a[i][j]=-1e9;
                mn=min(mn, calc(u,v,p,q)); a[i][j]=tg;
            }
        cout << mn << "\n";
    }
    return 0;
}
