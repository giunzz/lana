#include <bits/stdc++.h>
#define task "TABLE"
#define nmax 333
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
int n,m,k,a[333][333],f[nmax][nmax],u,v,p,q,res[nmax];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int e = 1; e <= k; e++)
    {
        res[e] = 1e9;
        cin >> u >> v >> p >> q;
        for (int i = u; i <= p; i++)
            for (int j = v; j <= q; j++)
            {
                if ((i == u && j == v) || (i == p && j == q)) continue;
                reset(f);
                for (int r = u; r <= p; r++)
                    for (int c = v; c <= q; c++)
                    {
                        if (r == i && c == j) {
                            f[r][c] = -1e9;
                            continue;
                        }
                        f[r][c] = max(f[r][c-1],f[r-1][c]) + a[r][c];
                    }
                res[e] = min(res[e],f[p][q]);
            }
        cout << res[e] <<'\n';
    }

}
