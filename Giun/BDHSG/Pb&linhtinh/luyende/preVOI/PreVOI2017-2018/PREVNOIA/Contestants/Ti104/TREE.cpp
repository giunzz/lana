#include <bits/stdc++.h>
#define task "TREE."
#define ff(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define inf 1e9
#define pb push_back
using namespace std;
typedef long long ll;

const int maxn = 6000;
int a[maxn], sum[maxn], n, degree[maxn], par[maxn], step;
vector < int > V[maxn];
struct edges
{
    int x;
    int y;
} f[maxn];

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
    n = readint();
    ff(i, 1, n) a[i] = readint();
    ff(i, 1, n - 1)
    {
        f[i].x = readint();
        f[i].y = readint();
        V[f[i].x].pb(f[i].y);
        degree[f[i].x]++;
    }
}

void dfs(int u)
{
    if (degree[u] == 0)
    {
        if (a[u] > 1)
        {
            step += a[u] - 1;
            a[u] = 1;
        }
        return;
    }
    for (int i = 0; i < V[u].size(); ++i)
    {
        int v = V[u][i];
        if (v != par[u])
        {
            par[v] = u;
            dfs(v);
            sum[u] += a[v] + sum[v];
        }
    }
    step += abs(a[u] - sum[u]);
    a[u] = sum[u];
}

void solve()
{
    enter();
    dfs(1);
    printf("%d", step);
}

int main()
{
    solve();
}

