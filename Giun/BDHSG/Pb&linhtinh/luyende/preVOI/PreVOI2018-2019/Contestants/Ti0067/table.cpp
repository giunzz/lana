#include <bits/stdc++.h>
#define ft first
#define sd second

using namespace std;
typedef pair <int, int> II;
typedef pair <int, II> III;

const int maxN = 1005;
const int dr[2] = { 0, 1};
const int dc[2] = { 1, 0};
const int64_t INF = 2e18;
int M, N, Query, Gold[maxN][maxN];
int A[maxN][maxN], visit[maxN][maxN];
int64_t dist[maxN][maxN];

void Dijsktra(int x, int y, int p, int q)
{
    set <III> S;
    visit[x][y] = 1, dist[x][y] = Gold[x][y];
    S.insert(III(dist[x][y], II(x, y)));
    while(!S.empty())
    {
        III T = *S.begin(); S.erase(T);
        int u = T.sd.ft, v = T.sd.sd;
        //if(u == p && v == q) return;
        for(int k = 0; k < 2; ++k)
        {
            int uu = u + dr[k], vv = v + dc[k];
            if(uu > 0 && uu <= M && vv > 0 && vv <= N)
            {
                if(visit[uu][vv] == 0)
                {
                    visit[uu][vv] = 1;
                    dist[uu][vv] = dist[u][v] + Gold[uu][vv];
                    S.insert(III(dist[uu][vv], II(uu, vv)));
                }
                else if(visit[uu][vv] == 1 && dist[uu][vv] < dist[u][v] + Gold[uu][vv])
                {
                    S.erase(III(dist[uu][vv], II(uu, vv)));
                    dist[uu][vv] = dist[u][v] + Gold[uu][vv];
                    S.insert(III(dist[uu][vv], II(uu, vv)));
                }
            }
        }
    }
}

void sub1()
{
    while(Query--)
    {
        int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v);
        //cerr << x << ' ' << y << ' ' << u << ' ' << v << '\n';
        int64_t ans = 2e18;
        for(int i = x; i <= u; ++i)
        for(int j = y; j <= v; ++j)
        {
            memset(visit, 0, sizeof visit);
            if((i == x && j == y) || (i == u && j == v)) continue;
            visit[i][j] = 2;
            Dijsktra(x, y, u, v);
            ans = min(ans, dist[u][v]);
            //cerr << dist[u][v] << ' ' << i << ' ' << j << '\n';
        }
        //cerr << '\n';
        printf("%I64d\n", ans);
    }
}

#define DU "table"
int main()
{
    freopen(DU".inp", "r", stdin);
    /*cout << 30 << ' ' << 30 << ' ' << 1 << '\n';
    for(int i = 1; i <= 30; ++i)
    {
        for(int j = 1; j <= 30; ++j) cout << 1 << ' ';
        cout << '\n';
    }*/
    freopen(DU".out", "w", stdout);
    scanf("%d%d%d", &M, &N, &Query);
    for(int i = 1; i <= M; ++i)
        for(int j = 1; j <= N; ++j) scanf("%d", &Gold[i][j]);
    if(M <= 30) sub1();
    else sub1();
}
