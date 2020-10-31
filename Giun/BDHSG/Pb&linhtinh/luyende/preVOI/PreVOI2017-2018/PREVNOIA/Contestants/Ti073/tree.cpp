#include <bits/stdc++.h>

using namespace std;

int ReadInt()
{
    char c;
    for(c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}

void WriteInt(int64_t x)
{
    if(x > 9)WriteInt(x / 10);
    putchar(x % 10 + '0');
}

#define maxn 5005
int n, a[maxn], deg[maxn];
vector<int> g[maxn];

void Enter()
{
    n = ReadInt();
    for(int i = 1; i <= n; ++i)
    {
        a[i] = ReadInt();
        g[i]. clear();
        deg[i] = 0;
    }
    for(int i = 1; i < n; ++i)
    {
        int u = ReadInt(), v = ReadInt();
        g[u]. push_back(v); ++deg[u];
        g[v]. push_back(u); ++deg[v];
    }
}

int cl[maxn], cur[maxn], pd[maxn], s[maxn], sn, tp[maxn], stp;

void DFS(int xp)
{
    sn = 0;
    s[++sn] = xp;
    cl[xp] = 1; pd[xp] = 0;
    while(sn)
    {
        int u = s[sn];
        if(cur[u] < deg[u])
        {
            int v = g[u][cur[u]++];
            if(cl[v] == 0)
            {
                s[++sn] = v;
                cl[v] = 1; pd[v] = u;
            }
        }
        else tp[--stp] = u, --sn;
    }
}

int _v[2];
int64_t F[maxn][maxn];
#define INF 1000000000000000001LL

void Solve()
{
    for(int i = 1; i <= n; ++i)cl[i] = cur[i] = pd[i] = 0;
    stp = n + 1;
    DFS(1);
    for(int x = n; x >= 1; --x)
    {
        int u = tp[x];
        int socon = 0;
        for(int k = 0; k < deg[u]; ++k)
        {
            int v = g[u][k];
            if(pd[v] == u)_v[socon++] = v;
        }
        for(int i = 0; i <= n; ++i)F[u][i] = INF;
        if(socon == 0)
        {
            F[u][0] = a[u];
            F[u][1] = abs(a[u] - 1);
        }
        if(socon == 1)
        {
            for(int i = 0; i <= n; ++i)if(F[_v[0]][i] != INF)F[u][i] = F[_v[0]][i] + abs(i - a[u]);
        }
        if(socon == 2)
        {
            for(int i = 0; i <= n; ++i)
                for(int j = 0; j <= i; ++j)if(F[_v[0]][j] != INF && F[_v[1]][i - j] != INF)
                    F[u][i] = min(F[u][i], F[_v[0]][j] + F[_v[1]][i - j] + abs(i - a[u]));
        }
    }
    int64_t ds = INF;
    for(int i = 0; i <= n; ++i)ds = min(ds, F[1][i]);
    WriteInt(ds);
}

#define TASK "tree"

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    Enter();
    Solve();
}
