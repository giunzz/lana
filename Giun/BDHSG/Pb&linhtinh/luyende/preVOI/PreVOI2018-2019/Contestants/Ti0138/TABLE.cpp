#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;

const int maxn = 301;
const ll oo = 1e18;

struct TVer
{
    int x, y;
};

struct TQ
{
    TVer id;
    ll dlab;

    operator < (const TQ &other) const
    {
        return dlab > other.dlab;
    }
};
priority_queue<TQ> Queue;

int m, n, k;
ll a[maxn][maxn], res[maxn];
ll d[maxn][maxn];
TVer u[maxn], v[maxn];
TVer block;
ll base;

void Input()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int i = 1; i <= k; i++)
        cin >> u[i].x >> u[i].y >> v[i].x >> v[i].y;
}

bool Relax(TVer u, TVer v, ll w)
{
    if ((ll) d[u.x][u.y] + w < d[v.x][v.y])
    {
        d[v.x][v.y] = (ll) d[u.x][u.y] + w;
        return true;
    }
    return false;
}

void Init()
{
    while (!Queue.empty())
        Queue.pop();
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        d[i][j] = oo;
}

void Dijkstra(int key, TVer s, TVer t)
{
    Init();
    d[s.x][s.y] = a[s.x][s.y];
    Queue.push({s, d[s.x][s.y]});

    while (!Queue.empty())
    {
        TQ qu = Queue.top();
        Queue.pop();
        TVer u = qu.id;
        if (d[u.x][u.y] != qu.dlab)
            continue;
        if (u.x == t.x && u.y == t.y)
            break;

        if (u.x + 1 <= m)
        {
            TVer v = {u.x + 1, u.y};
            if (v.x != block.x || v.y != block.y)
            {
                if (Relax(u, v, a[v.x][v.y]))
                    Queue.push({v, d[v.x][v.y]});
            }
        }
        if (u.y + 1 <= n)
        {
            TVer v = {u.x, u.y + 1};
            if (v.x != block.x || v.y != block.y)
            {
                if (Relax(u, v, a[v.x][v.y]))
                    Queue.push({v, d[v.x][v.y]});
            }
        }
    }

    ll trueval = base * (((ll) t.x - s.x) + ((ll) t.y - s.y) + 1) - d[t.x][t.y];
    res[key] = min(res[key], trueval);
}

void Solve()
{
    fill(res + 1, res + 1 + k, oo);

    base = -oo;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        base = max(base, a[i][j]);

    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        a[i][j] = base - a[i][j];

    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        block = {i, j};
        for (int d = 1; d <= k; d++)
        if ((block.x != u[d].x || block.y != u[d].y)  && (block.x != v[d].x || block.y != v[d].y))
            Dijkstra(d, u[d], v[d]);
    }
}

void Output()
{
    for (int i = 1; i <= k; i++)
        cout << res[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("TABLE.INP" , "r" , stdin);
    freopen("TABLE.OUT" , "w" , stdout);

    Input();
    Solve();
    Output();
}
