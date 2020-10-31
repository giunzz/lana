#include <bits/stdc++.h>

using namespace std;

#define task                        "bubbletea"
#define int                         long long
#define ft							first
#define nd							second
#define left                        _left
#define right                       _right
#define FOR(i, a, b)                for(int i = a; i <= b; ++i)
#define FORD(i, a, b)               for(int i = a; i >= b; --i)
#define REP(i, a, b)                for(int i = a; i < b; ++i)
#define REPD(i, a, b)               for(int i = (int)a-1; i >= b; --i)
#define ___unique(a)                sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end())-a.begin());
#define fast                        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CLR(a, x)                   memset(a, x, sizeof a);

typedef pair < int, int > ii;
typedef long double ldb;
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
void write(long long x)
{
    if (x < 0) { putchar('-'); write(abs(x)); }
    if (x > 9) write(x / 10);
    putchar(char(x % 10 + '0'));
}
//--------------------------------------------------------------
const int N = 5e4 +10;
const int inf = 1e18+7;
int n, k, MIN = inf;
int a[N];
struct Edge
{
    int u, v, c;
    Edge(){};
    Edge(int u, int v, int c) : u(u), v(v), c(c) {};
    int get(int x) { return x ^ u ^ v; }
} edge[N];
vector < int > adj[N];
void Enter()
{
    n = read(), k = read();
    FOR(i, 1, k) a[i] = read();
    MIN = inf;
    REP(i, 1, n)
    {
        int u, v, c;
        u = read(), v = read(), c = read();
        edge[i] = {u, v, c};
        MIN = min(MIN, c);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
}
namespace subtask1 {
    ii par[N];
    int high[N], cnt[N];
    int ans;
    void dfs(int u, int prv = 0)
    {
        REP(i, 0, adj[u].size())
        {
            int id = adj[u][i], v = edge[id].get(u);
            if (v == prv) continue;
            par[v] = {u, id};
            high[v] = high[u] + 1;
            dfs(v, u);
        }
    }
    int lca(int u, int v, int type)
    {
        bool ok = true;
        int ans = 0;
        if (high[u] < high[v]) swap(u, v);
        while (high[par[u].ft] >= high[v])
        {
            int id = par[u].nd;
            cnt[id] += type;
            ans += edge[id].c;
            if (cnt[id] > 1) ok = false;
            u = par[u].ft;
        }
        if (u == v)
        {
            if (!ok) return 0;
            return ans;
        }
        while (par[u].ft != par[v].ft)
        {
            int id1 = par[u].nd, id2 = par[v].nd;
            u = par[u].ft, v = par[v].ft;
            cnt[id1] += type;
            cnt[id2] += type;
            ans += edge[id1].c + edge[id2].c;
            if (cnt[id1] > 1 || cnt[id2] > 1) ok = false;
        }
        int id1 = par[u].nd, id2 = par[v].nd;
        u = par[u].ft, v = par[v].ft;
        cnt[id1] += type;
        cnt[id2] += type;
        ans += edge[id1].c + edge[id2].c;
        if (cnt[id1] > 1 || cnt[id2] > 1) ok = false;
        if (!ok) return 0;
        return ans;
    }
    int get(int x, int k) { return (x >> k) & 1; }
    int turn(int x, int i, int j)
    {
        x ^= (1 << i);
        x ^= (1 << j);
        return x;
    }
    void backtrack(int state, int res)
    {
        if (state == 0)
        {
            ans = min(ans, res);
            return;
        }
        REP(i, 0, k) if (get(state, i))
            REP(j, 0, k) if (j != i && get(state, j))
            {
                int ss = lca(a[i+1], a[j+1], 1);
                if (ss) backtrack(turn(state, i, j), max(res, ss));
                lca(a[i+1], a[j+1], -1);
            }
    }
    void run()
    {
        high[0] = -1;
        dfs(1);
        ans = inf;
        backtrack( (1 << k) - 1, 0);
        write(ans);
    }
}
namespace subtask2 {
    void run()
    {
        write(MIN);
    }
}
void Solve()
{
    if (k == n) subtask2 :: run();
    else
        subtask1 :: run();
}
main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    Enter();
    Solve();
    return 0;
}
/*
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/
/*
8 6
1 4 5 6 7 8
1 2 1
2 3 10
3 4 1
2 5 6
2 6 6
3 7 6
3 8 6
*/
