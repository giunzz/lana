#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define fi first
#define se second
#define Tpair pair <ll, ll>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int mod  = 1e9 + 7;
const int oo   = 1e9 + 1;

ll n, T, h[maxn], dep[maxn], par[maxn], Lca[maxn][20], u, t, w, k, a[maxn], p[11];
bool avail[maxn];
vector <Tpair> v[maxn];

void Dfs (int x, int pre)
{
    par[x] = pre;
    for (Tpair j : v[x])
        if (j.se != pre)
        {
            h[j.se] = h[x] + 1;
            dep[j.se] = dep[x] + j.fi;
            Dfs (j.se, x);
        }
}

int LCA (int x, int y)
{
    if (h[x] < h[y]) swap (x, y);
    for (int i = 19; i >= 0; --i)
        if (h[Lca[x][i]] >= h[y]) x = Lca[x][i];
    for (int i = 19; i >= 0; --i)
        if (Lca[x][i] != Lca[y][i])
        {
            x = Lca[x][i]; y = Lca[y][i];
        }
    if (x != y) x = Lca[x][0];
    return x;
}

void Init()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> t >> w;
        v[u].push_back ({w, t});
        v[t].push_back ({w, u});
    }
    Dfs (1, 1);
    //for (int i = 1; i <= n; ++i) cout << i << " " << h[i] << " " << dep[i] << endl;

    par[1] = 1;
    for (int i = 1; i <= n; ++i) Lca[i][0] = par[i];
    for (int i = 1; i <= 19; ++i)
        for (int j = 1; j <= n; ++j) Lca[j][i] = Lca[Lca[j][i - 1]][i - 1];
}

ll Kc (int u, int t)
{
    int r = LCA (u, t);
    return dep[u] + dep[t] - 2 * dep[r];
}

void Solve()
{
    ll res = +oo;
    for (int i = 1; i <= k; ++i) p[i] = i;
    do
    {
        ll Max = 0;
        //for (int i = 1; i <= k; ++i) cout << p[i] << " "; cout << endl;
        for (int i = 1; i <= k / 2; ++i)
        {
            int u = a[i];
            int t = a[k / 2 - i + 1];
            Max = max (Max, Kc(u, t));
        }
        res = min (res, Max);
    }
    while (next_permutation(p + 1, p + k + 1));
    cout << res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("bubbletea.inp", "r", stdin);
    freopen ("bubbletea.out", "w", stdout);

    Init();
    if (k > 15) {cout << -1; return 0;}
    Solve();
}
// Date 2 Month 12 Year 2017

