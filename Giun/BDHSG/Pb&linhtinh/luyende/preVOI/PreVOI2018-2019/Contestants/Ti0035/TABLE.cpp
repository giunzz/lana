#include<bits/stdc++.h>
#define maxn 303
#define pii pair<int, int>

using namespace std;

int m, n, k;
long long a[maxn][maxn];
int kt[31][31];
int h1[3]{0,1};
long long f[31][31];

void BFS(int u, int v, int p, int q, int i, int j)
{
    for(int l = u; l <= p; l++)
        for(int r = v; r <= q; r++)
        f[l][r] = -1e9;
    memset(kt, 0,sizeof(kt));
    queue<pii> lp;
    lp.push(make_pair(u, v));
    f[u][v] = a[u][v];
    while(!lp.empty())
    {
        pii X = lp.front();
        lp.pop();
//        cerr << X.first << " " << X.second <<"\n";
        for(int l = 0; l < 2; l++)
        {
            int x = X.first + h1[(l+1)%2];
            int y = X.second + h1[l%2];
            if(x == i && y == j)continue;
            if(x <= p && y <= q)
            {
            if(!kt[x][y]){
                lp.push(make_pair(x,y));
                kt[x][y] = 1;
            }
            f[x][y] = max(f[x][y], f[X.first][X.second] + a[x][y]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    cin >> m >> n >> k;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        cin >> a[i][j];

    while(k--)
    {
        long long res = 1e18;
        int u, v , p, q;
        cin >> u >> v >> p >> q;
        for(int i = u ; i <= p; i++)
            for(int j = v ; j <= q; j++)
        {
            if(i == u && j == v)continue;
            if(i == p && j == q)continue;
            BFS(u, v, p, q, i, j);
            res = min(res, f[p][q]);
        }
        cout << res << "\n";
    }
}
