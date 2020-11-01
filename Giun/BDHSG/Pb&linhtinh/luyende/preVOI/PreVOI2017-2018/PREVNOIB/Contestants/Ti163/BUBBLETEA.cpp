/*******************THACH THAO*******************/

#include <bits/stdc++.h>
#define maxn 50007
#define maxC 1000000007
#define Task "BUBBLETEA"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

int n, k, ans = maxC;
int p[maxn], b[maxn], f[maxn], dd[maxn], par[19][maxn], label[maxn];
vector <pii> a[maxn];


void setup()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        cin >> p[i];
    int u, v, w;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v >> w;
        a[u].pb(mp(v, w));
        a[v].pb(mp(u, w));
    }
}

void DFS(int u)
{
    dd[u] = 1;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i].F;
        int w = a[u][i].S;
        if (dd[v]) continue;
        f[v] = f[u] + w;
        par[0][v] = u;
        DFS(v);
    }
}

int MakeLabel(int u)
{
    if (u == 1) return 1;
    if (label[u] == 0) return MakeLabel(par[0][u]) + 1;
    return label[u];
}

int LCA(int x, int y)
{
    for (int k = 19; k >= 0; --k)
        if (label[par[k][x]] >= label[y]) x = par[k][x];
    for (int k = 19; k >= 0; --k)
        if (label[par[k][y]] >= label[x]) y = par[k][y];
    for (int k = 19; k >= 0; --k)
        if (par[k][x] != par[k][y]) x = par[k][x], y = par[k][y];
    while (x != y) x = par[0][x], y = par[0][y];
    return x;
}

void Calc()
{
    int res = -maxC;
    for (int i = 2; i <= k; i += 2)
        res = max(res, f[b[i]] + f[b[i-1]] - 2 * f[LCA(b[i], b[i-1])]);
    ans = min(ans, res);
}

void Back(int id)
{
    if (id > k)
    {
        Calc();
        return;
    }
    for (int i = 1; i <= k; ++i)
        if (!dd[i])
        {
            b[id] = p[i];
            dd[i] = 1;
            Back(id + 1);
            dd[i] = 0;
        }
}

void solve()
{
    DFS(1);
    memset(dd, 0, sizeof(dd));

    for (int i = 1; i <= n; ++i)
        label[i] = MakeLabel(i);
    for (int k = 1; k <= 19; ++k)
        for (int i = 1; i <= n; ++i)
            par[k][i] = par[k-1][par[k-1][i]];

    Back(1);

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    setup();
    solve();
    return 0;
}
