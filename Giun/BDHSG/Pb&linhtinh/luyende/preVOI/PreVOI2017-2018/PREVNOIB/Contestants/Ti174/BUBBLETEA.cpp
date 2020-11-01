#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define pb push_back
#define fi first
#define se second

typedef pair <int, ll> ii;

const int maxn = 50004;
const int mn = 10004;
const ll inf = 10000000000000009;

int n, k, a[maxn], cnt[maxn], t, x[maxn];
ll f[mn][mn], ans = inf;
bool dd[maxn];
vector <ii> deg[maxn];

void inp()
{
    cin >> n >> k;

    for (int i = 1; i <= k; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = inf;

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        f[u][v] = c;
        f[v][u] = c;
        deg[u].pb(ii(v, c));
        deg[v].pb(ii(u, c));
    }

    for (int i = 1; i <= n; ++i)
        deg[i].pb(ii(0, 0));
}

void DFS(int u)
{
    dd[u] = true;
    cnt[u] = t;

    for (int i = 0; int v = deg[u][i].fi; ++i)
        if (!dd[v]) DFS(v);
}

void Floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];
}

void proc()
{
    ll temp = f[a[x[1]]][a[x[2]]];

    for (int i = 3; i <= k; i += 2)
        temp = max(temp, f[a[x[i]]][a[x[i+1]]]);

    ans = min(ans, temp);
}

void backtrack(int i)
{
    for (int j = 1; j <= k; ++j)
        if (dd[j])
    {
        x[i] = j;
        dd[j] = false;
        if (i == k) proc();
        else backtrack(i + 1);
        dd[j] = true;
    }
}

void sub1()
{
    fill (dd + 1, dd + n + 1, true);

    Floyd();

    backtrack(1);

    cout << ans;
}

void work_out()
{
    for (int i = 1; i <= n; ++i)
        if (!dd[i]) { ++t; DFS(i);}

    t = cnt[a[1]];
    for (int i = 2; i <= k; ++i)
        if (cnt[a[k]] != t) { cout << "-1"; return;}

    sub1();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("BUBBLETEA.inp", "r", stdin);
    freopen("BUBBLETEA.out", "w", stdout);

    inp();
    work_out();

    return 0;
}
