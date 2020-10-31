#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<functional>
#include<chrono>
//#include<windows.h>
//#include<direct.h>
#include<random>
#include<sstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "TABLE"
//#define BeztDonkey

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int M = 301, N = 301, Inf = 1e9;

int a[M][N], f[M][N], g[M][N], m, n, k, u, v, p, q;
bool visit[M][N];
struct TPoint
{
    int x, y;
};

void Sub1()
{
    for (int cnt = 1; cnt <= k;  ++cnt)
    {
        cin >> u >> v >> p >> q;
        int ans = Inf;
        for (int x = u; x <= p; ++x)
            for (int y = v; y <= q; ++y)
            {
                if (x == u && y == v || x == p && y == q) continue;
                for (int i = u; i <= p; ++i)
                    for (int j = v; j <= q; ++j)
                    {
                        if (i == u && j == v) { f[i][j] = a[i][j]; continue; }
                        if (i == x && j == y) { f[i][j] = -Inf; continue; }
                        if (i > u)
                            if (j == v) f[i][j] = f[i - 1][j] + a[i][j];
                            else f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
                        else f[i][j] = f[i][j - 1] + a[i][j];
                    }
                ans = min(ans, f[p][q]);
            }
        cout << ans << '\n';
        //for (int i = u; i <= p; ++i, cout << '\n')
        //    for (int j = v; j <= q; ++j) cout << f[i][j] << ' ';
    }
}

inline void DFS(int i, int j)
{
    if (visit[i][j]) return;
    visit[i][j] = 1;
    if (i > u && f[i][j] == f[i - 1][j] + a[i][j]) DFS(i - 1, j);
    if (j > v && f[i][j] == f[i][j - 1] + a[i][j]) DFS(i, j - 1);
}

inline TPoint BFS()
{
    queue<TPoint> qu;
    qu.push({u, v});
    while (!qu.empty())
    {
        auto &u = qu.front();
        if (visit[u.x][u.y] && u.x < p && u.y < q &&
            visit[u.x + 1][u.y] && f[u.x][u.y] + a[u.x + 1][u.y] == f[u.x + 1][u.y] &&
            visit[u.x][u.y + 1] && f[u.x][u.y] + a[u.x][u.y + 1] == f[u.x][u.y + 1]) return u;
        if (u.x < p) qu.push({u.x + 1, u.y});
        if (u.y < q) qu.push({u.x, u.y + 1});
        qu.pop();
    }
    return {0, 0};
}

void Sub2()
{
    for (int cnt = 1; cnt <= k;  ++cnt)
    {
        cin >> u >> v >> p >> q;
        int ans = Inf;
        for (int i = u; i <= p; ++i)
            for (int j = v; j <= q; ++j)
            {
                visit[u][v] = 0;
                if (i == u && j == v) { f[i][j] = a[i][j]; continue; }
                if (i > u)
                    if (j == v) f[i][j] = f[i - 1][j] + a[i][j];
                    else f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
                else f[i][j] = f[i][j - 1] + a[i][j];
            }
        DFS(p, q);
        visit[u][v] = visit[p][q] = 0;
//        for (int i = u; i <= p; ++i, cout << '\n')
//            for (int j = v; j <= q; ++j) cout << f[i][j] << ' ';
//        for (int i = u; i <= p; ++i)
//            for (int j = v; j <= q; ++j)
//                if (visit[i][j]) cout << i << ' ' << j << '\n';
        TPoint t = BFS();
        if (t.x)
        {
            for (int i = u; i <= p; ++i)
                for (int j = v; j <= q; ++j) visit[i][j] = 0;
            visit[t.x][t.y] = 1;
        }
        for (int x = u; x <= p; ++x)
            for (int y = v; y <= q; ++y)
            {
                if (visit[x][y] == 0) continue;
                for (int i = u; i <= p; ++i)
                    for (int j = v; j <= q; ++j)
                    {
                        if (i == u && j == v) { f[i][j] = a[i][j]; continue; }
                        if (i == x && j == y) { f[i][j] = -Inf; continue; }
                        if (i > u)
                            if (j == v) f[i][j] = f[i - 1][j] + a[i][j];
                            else f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
                        else f[i][j] = f[i][j - 1] + a[i][j];
                    }
                ans = min(ans, f[p][q]);
            }
        cout << ans << '\n';
    }
}

int main()
{
    #ifdef BeztDonkey
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    Sub1();
    //Sub2();

    #ifdef BeztDonkey
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;

}

