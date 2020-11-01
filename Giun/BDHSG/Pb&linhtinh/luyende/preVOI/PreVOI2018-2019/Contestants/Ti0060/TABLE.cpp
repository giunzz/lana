#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, k, lmin = 1e3, lmax, dmin = 1e3, dmax, giam[305];
ll a[305][305], f[305][305], sum;
vector < ll > vec;

struct Data
{
    int u, v, p, q;
    void Init()
    {
        cin >> u >> v;
        cin >> p >> q;
    }
} pi[305];

int main()
{
    if (fopen ("TABLE.inp", "r"))
    {
        freopen ("TABLE.inp", "r", stdin);
        freopen ("TABLE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= k; ++i)
        pi[i].Init();
    for (int i = 0; i <= 301; ++i)
        giam[i] = i - 1;
    int id = 1;
    while (id <= k)
    {
        int u = pi[id].u, v = pi[id].v;
        int p = pi[id].p, q = pi[id].q;
        int metis = giam[u];
        for (int i = v; i <= q; ++i)
            f[metis][i] = 0;
        metis = giam[v];
        for (int i = u; i <= p; ++i)
            f[i][metis] = 0;
        sum = 1e18;
        for (int dong = u; dong <= p; ++dong)
            for (int cot = v; cot <= q; ++cot)
            {
                if ((dong == u && cot == v) || (dong == p && cot == q))
                    continue;
                ll val = a[dong][cot];
                a[dong][cot] = 0;
                for (int i = u; i <= p; ++i)
                    for (int j = v; j <= q; ++j)
                        f[i][j] = max(f[giam[i]][j], f[i][giam[j]]) + a[i][j];
                sum = min(sum, f[p][q]);
                a[dong][cot] = val;
            }
        vec.push_back(sum);
        ++id;
    }
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << '\n';
}
