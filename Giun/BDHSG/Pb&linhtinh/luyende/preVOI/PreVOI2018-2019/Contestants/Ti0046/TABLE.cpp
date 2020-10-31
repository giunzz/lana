#include <bits/stdc++.h>
#define FILE "TABLE"
#define long long long
#define pii pair < int, int >
#define pip pair < int, pii >
#define x first
#define y second
#define val first
#define xQ second.first
#define yQ second.second

using namespace std;
const int maxn=3e2+5;

int m, n, k, a[maxn][maxn], d[maxn][maxn], t[maxn][maxn];
vector < pii > tmp;

int Dijkstra(pii s, pii f, const pii b = {0,0})
{
    for (int i = s.x; i <= f.x; ++i) for (int j = s.y; j <= f.y; ++j) d[i][j] = -1e9;
    queue < pip > Q; t[s.x][s.y] = 0; d[s.x][s.y] = a[s.x][s.y]; Q.push({d[s.x][s.y], s});
    while (!Q.empty())
    {
        int u = Q.front().xQ, v = Q.front().yQ, w = Q.front().val; Q.pop();
        if (w != d[u][v] || u > f.x || v > f.y || (u == b.x && v == b.y)) continue;
        if (u == f.x && v == f.y) break;

        if (u < m && d[u+1][v] < w+a[u+1][v]) t[u+1][v] = 1, d[u+1][v] = w + a[u+1][v], Q.push({d[u+1][v], {u+1, v}});
        if (v < n && d[u][v+1] < w+a[u][v+1]) t[u][v+1] = 2, d[u][v+1] = w + a[u][v+1], Q.push({d[u][v+1], {u, v+1}});
    } return d[f.x][f.y];
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];

    while (k--)
    {
        pii s, f; cin >> s.x >> s.y >> f.x >> f.y;
        int res = Dijkstra(s, f); //res = min(res-a[s.x][s.y], res-a[f.x][f.y]);

        pii b = f; if (t[b.x][b.y] == 1) b.x--; else b.y--;
        while (b != s){ tmp.push_back(b); if (t[b.x][b.y] == 1) b.x--; else b.y--; }

        while (tmp.size()) res = min(res, Dijkstra(s, f, tmp.back())), tmp.pop_back();

        cout << res << "\n";
    }
    return 0;
}
