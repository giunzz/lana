#include <bits/stdc++.h>
#define task "BUBBLETEA."
#define ff(i, a, b) for (int i = a; i <= (int) b; ++i)
#define fd(i, a, b) for (int i = a; i >= (int) b; --i)
#define inf 1e9
#define pb push_back
using namespace std;
typedef long long ll;

const int maxn = 60000;
struct toado
{
    int x;
    int y;
    int w;
} e[maxn];
int park[maxn], par[maxn], h[maxn], n, k, length[maxn];
int check[maxn];
vector < pair <int, int> > adj[maxn];

inline int readint()
{
    int sign = 1;
    char c;
    do
    {
        c = getchar();
        if (c == '-') sign = -sign;
    }
    while (c < '0' || c > '9');
    int res;
    for (res = 0; c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + (c - '0');
    return res * sign;
}

void enter()
{
    freopen(task"inp", "r", stdin);
    freopen(task"out", "w", stdout);
    ios_base::sync_with_stdio(false);
    n = readint(); k = readint();
    ff(i, 1, k) park[i] = readint();
    ff(i, 1, n - 1)
    {
        e[i].x = readint(); e[i].y = readint();
        e[i].w = readint();
        adj[e[i].x].pb({e[i].y, e[i].w});
        adj[e[i].y].pb({e[i].x, e[i].w});
    }
}

void dfs(int u)
{
    ff(i, 0, adj[u].size() - 1)
    {
        int v = adj[u][i].first;
        if (v != par[u])
        {
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v);
        }
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    while (h[u] > h[v]) u = par[u];
    while (u != v)
    {
        u = par[u];
        v = par[v];
    }
    return u;
}

void bfs(int x)
{
    queue <int> qu;
    check[x] = 1;
    qu.push(x);
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        ff(i, 0, adj[u].size() - 1)
        {
            int v = adj[u][i].first;
            if (check[v] == 0)
            {
                check[v] = 1;
                int d = adj[u][i].second;
                length[v] = length[u] + d;
                qu.push(v);
            }
        }
    }
}

void solve()
{
    enter();
    dfs(1);
    bfs(1);
    int max_kq = 0;
    ff(i, 1, k - 1)
        ff(j, i + 1, k)
        {
            int cha = lca(park[i], park[j]);
            int len = (length[park[i]] + length[park[j]] - 2 * length[cha]);
            max_kq = max(max_kq, len);
        }
    printf("%d", max_kq);
}

int main()
{
    solve();
}

