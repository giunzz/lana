#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxMN = 303;
const lli infty = 1e9 + 1;
int m, n, k;
lli f[maxMN][maxMN];
bool x[maxMN][maxMN];
int a[maxMN][maxMN];
int u, v, p, q;
lli maxres = 0;
lli res;

void ReadInput()
{
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            x[i][j] = true;
            maxres += (long long)a[i][j];
        }
}

lli Optimize(int u, int v, int p, int q)
{
    for(int i = u; i <= p; i++)
        for(int j = v; j <= q; j++)
        {
            if(x[i][j])
            {
                if(i == u)
                {
                    if(j == v)
                        f[i][j] = (long long)a[i][j];
                    else f[i][j] = f[i][j-1] + (long long)a[i][j];
                }
                else if(j == v)
                    f[i][j] = f[i-1][j] + (long long)a[i][j];
                else
                    f[i][j] = max(f[i-1][j], f[i][j-1]) + (long long)a[i][j];
            }
            else f[i][j] = -infty;
        }
    return f[p][q];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    ReadInput();
    for(int t = 0; t < k; t++)
    {
        cin >> u >> v >> p >> q;
        res = maxres;
        //int posx, posy;
        for(int i = u; i <= p; i++)
            for(int j = v; j <= q; j++)
            {
                if((i == u && j == v) || (i == p && j == q)) continue;
                x[i][j] = false;
                lli calc = Optimize(u, v, p, q);
                res = min(res, calc);
                x[i][j] = true;
            }
        cout << res << '\n';
        //cout << posx << ' ' << posy << '\n';
    }
}
