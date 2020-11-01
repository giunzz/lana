#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define N 305
#define ll long long
#define maxc 1ll*10000000000007


using namespace std;

int n, m, a[N][N];
ll d[2][N][N], f[2][N][N], row[N][N], col[N][N], dis[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void calc(int u, int v, int id, int lDir, int rDir)
{
    f[id][u][v] = 1;
    d[id][u][v] = a[u][v];
    if (id == 0)
    {
        FOR(i, u, n)
            FOR(j, v, m)
                FOR(dir, lDir, rDir)
                {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (d[id][x][y] < d[id][i][j] + a[x][y])
                    {
                        d[id][x][y] = d[id][i][j] + a[x][y];
                        f[id][x][y] = f[id][i][j];
                    }
                    else if (d[id][x][y] == d[id][i][j] + a[x][y])
                        f[id][x][y] += f[id][i][j];
                }
    }
    else
    {
        FORD(i, u, 1)
            FORD(j, v, 1)
                FOR(dir, lDir, rDir)
                {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (d[id][x][y] < d[id][i][j] + a[x][y])
                    {
                        d[id][x][y] = d[id][i][j] + a[x][y];
                        f[id][x][y] = f[id][i][j];
                    }
                    else if (d[id][x][y] == d[id][i][j] + a[x][y])
                        f[id][x][y] += f[id][i][j];
                }
    }
}
ll Trau(int u, int v, int p, int q, int bX, int bY)
{
    memset(dis, -60, sizeof dis);
    dis[u][v] = a[u][v];
    FOR(i, u, p)
        FOR(j, v, q)
            FOR(dir, 0, 1)
            {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (x == bX && y == bY) continue;
                dis[x][y] = max(dis[x][y], dis[i][j] + a[x][y]);
            }
    return dis[p][q];
}
int random(int M)
{
    int x = rand();
    int y = rand();
    return (x*y) % M + 1;
}
//#define SINH
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef SINH
    srand(time(NULL));
    freopen("TABLE.INP", "w", stdout);
    n = m = 6;
    int numQ = 3;
    cout <<n<<' '<<m<<' '<<numQ<<'\n';
    FOR(i, 1, n)
    {
        FOR(j, 1, m) cout <<random(20) - 10<<' ';
        cout <<'\n';
    }
    FOR(i, 1, numQ)
    {
        int u = random(n);
        int v = random(m);
        int p = random(n);
        int q = random(m);
        if (u > p) swap(u, p);
        if (v > q) swap(v, q);
        cout <<u<<' '<<v<<' '<<p<<' '<<q<<'\n';
    }
    #else


    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    int numQ;
    cin >> n >> m >> numQ;
    FOR(i, 1, n)
        FOR(j, 1, m) cin >> a[i][j];
    while(numQ--)
    {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        memset(d, -60, sizeof d);
        memset(f, 0, sizeof f);
        memset(row, -60, sizeof row);
        memset(col, -60, sizeof col);
        calc(u, v, 0, 0, 1);
        calc(p, q, 1, 2, 3);

        FOR(i, u, p)
            FOR(j, v, q)
            {
                ll dis = d[0][i][j] + d[1][i][j] - a[i][j];
                row[i][j] = max(row[i][j-1], dis);
                col[i][j] = max(col[i-1][j], dis);
            }

        ll res = maxc;

        FOR(i, u, p)
            FOR(j, v, q)
            {
                if (i == u && j == v) continue;
                if (i == p && j == q) continue;

                if (d[0][i][j] + d[1][i][j] - a[i][j] < d[0][p][q])
                {
                    res = min(res, d[0][p][q]);
                    continue;
                }
                if (f[0][i][j]*f[1][i][j] != f[0][p][q])
                {
                    res = min(res, d[0][p][q]);
                    continue;
                }
                ll cur = -maxc;
                if (i > u && j < q) cur = max(cur, col[i-1][j+1]);
                if (i < p && j > v) cur = max(cur, row[i+1][j-1]);
                if (cur != -maxc) res = min(res, cur);
            }
        cout <<res<<'\n';
    }

    #endif
}
