#include <bits/stdc++.h>

using namespace std;

#define int                         long long
#define FOR(i, a, b)                for(int i = a; i <= b; ++i)
#define FORD(i, a, b)               for(int i = a; i >= b; --i)
#define REP(i, a, b)                for(int i = a; i  < b; ++i)

//--------------------------------------------------------------
inline int read()
{
    int sign = 1;
    char c;
    do
    {
        c = getchar();
        if (c == '-') sign = -sign;
    } while (c < '0' || c > '9');
    int res;
    for (res = 0; c >= '0' && c <= '9'; c = getchar()) res = res * 10 + (c - '0');
    return res * sign;
}
void write(int x)
{
    if (x < 0) { putchar('-'); write(abs(x)); }
    if (x > 9) write(x / 10);
    putchar(char(x % 10 + '0'));
}
//----------------------------------------------------------------
const int N = 5010;
int n;
int f[N][N];
int a[N], numChild[N];
vector < int > adj[N];
void Enter()
{
    n = read();
    FOR(i, 1, n) a[i] = read();
    REP(i, 1, n)
    {
        int u, v; u = read(), v = read();
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
}
void dfs(int u, int prv = 0)
{
    //bool ok = true;
    REP(i, 0, adj[u].size())
    {
        int v = adj[u][i];
        if (v == prv) continue;
        dfs(v, u);
        numChild[u] += numChild[v];
    }
    if (adj[u].size() == 0)
    {
        f[u][0] = abs(a[u] -0);
        f[u][1] = abs(a[u] -1);
        numChild[u] = 1;
    }
    if (adj[u].size() == 1)
    {
        int v = adj[u][0];
        FOR(i, 0, numChild[u])
            f[u][i] = min(f[u][i], f[v][i] + abs(a[u] -i));
    }
    if (adj[u].size() == 2)
    {
        int v1 = adj[u][0], v2 = adj[u][1];
        FOR(i, 0, numChild[u])
            FOR(j, 0, i) f[u][i] = min(f[u][i], f[v1][j] + f[v2][i-j] + abs(a[u] -i));
    }
}
void Solve()
{
    memset(f, 0x3f, sizeof f);
    dfs(1);
    //FOR(i, 1, n) cout << i << ' ' << numChild[i] << '\n';
    int ans = 1e18 +7;
    FOR(i, 0, n) ans = min(ans, f[1][i]);
    write(ans);
}
main()
{
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);

    Enter();
    Solve();

    return 0;
}
