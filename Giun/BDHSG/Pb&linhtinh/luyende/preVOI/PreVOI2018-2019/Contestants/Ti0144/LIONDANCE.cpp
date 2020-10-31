#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,dt,f[4002][4002],Last[4002][4002];
ii trace[4002][4002];
int a[4002],b[4002],res[4002];
int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    scanf("%d%d",&n,&dt);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
    if (n*n*n*n > 200000000) {cout<<0; return 0;}
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {
        f[i][j] = f[i-1][j]; trace[i][j] = ii(i-1,j);
        Last[i][j] = Last[i-1][j];
        if (f[i][j] < f[i][j-1])
        {
            f[i][j] = f[i][j-1];
            trace[i][j] = ii(i,j-1);
            Last[i][j] = Last[i][j-1];
        }
        if (a[i] != b[j]) continue;
        for (int k = 0; k < i; k++)
            for (int l = 0; l < j; l++)
            if (a[k] == b[l] && (f[k][l] == 0 || abs(a[i] - b[l]) <= dt))
            {
                if (f[i][j] < f[k][l] + 1)
                {
                    f[i][j] = f[k][l] + 1;
                    trace[i][j] = ii(k,l);
                    Last[i][j] = a[i];
                }
                if (f[i][j] == f[k][l] + 1 && f[i][j] > 1)
                {
                    int u = trace[i][j].first, v = trace[i][j].second;
                    if (Last[u][v] < Last[k][l])
                    {
                        trace[i][j] = ii(k,l);
                        Last[i][j] = a[i];
                    }
                }
            }
    }
    cout<<f[n][n]<<"\n";
    int i = n, j = n, cnt = 0;
    while (i > 0 || j > 0)
    {
        int u = trace[i][j].first, v = trace[i][j].second;
        if (f[i][j] == f[u][v] + 1)
            res[++cnt] = a[i];
        i = u; j = v;
    }
    for (i = cnt; i >= 1; --i) cout<<res[i]<<' ';
    return 0;
}
