#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
const int oo = 1000000000;

long long n, m, k, a[maxn][maxn], d[maxn][maxn], dong[] = {0, 1}, cot[] = {1, 0}, res;
int dx[maxn][maxn], Times;

int BFS(int u, int v, int p, int q, int dcdv, int ccdv)
{
    queue < pair < int, int > > qu;
    qu.push({u, v});
    dx[u][v] = Times;
    while(qu.size())
    {
        int i = qu.front().first, j = qu.front().second;
        //cout <<  i << ' ' << j << '\n';
        qu.pop();
        if(i == p && j == q) return d[i][j];
        int Max = -oo, cs1, cs2, cs; bool ok = false;
        for(int k = 0; k < 2; k++)
        {
            int dm = i + dong[k], cm = j + cot[k];
            if(dm == dcdv && cm == ccdv) continue;
            if(dm > 0 && dm <= m && cm > 0 && cm <= n)
            {
                if(dx[dm][cm] != Times)
                {
                    dx[dm][cm] = Times;
                    d[dm][cm] = d[i][j] + a[dm][cm];
                    qu.push({dm, cm});
                }
            }
        }
    }
}

/*int F(int u, int v, int p, int q, int dcdv, int ccdv)
{
    if(u == p && v == q) return a[p][q];
    if(u == dcdv && v == ccdv) return 0;
    return max(F(u + 1, v, p, q, dcdv, ccdv), F(u, v + 1, p, q, dcdv, ccdv)) + a[u][v];
}*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("TABLE.inp","r",stdin); freopen("TABLE.out","w",stdout);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    for(int id = 1; id <= k; id++)
    {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        res = oo;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
        {
            if((i == u && j == v) || (i == p && j == q)) continue;
            Times++; d[u][v] = a[u][v];
            res = min(res, 0LL + BFS(u, v, p, q, i, j));
        }
        /*for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if((i == u && j == v) || (i == p && j == q)) continue;
                res = min(res, 0LL + F(u, v, p, q, i, j));
            }*/

        cout << res << '\n';
    }
    //Times = 1; d[1][1] = a[1][1];
    //cout << BFS(1, 1, 3, 4, 3,3);
}
