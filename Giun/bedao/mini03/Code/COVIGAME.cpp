#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e5 + 7;

int a[maxn], low[maxn], high[maxn], F[maxn], G[maxn];
vector <int> V[maxn];

int main()
{
    freopen("COVIGAME.INP", "r", stdin);
    freopen("COVIGAME.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, mi = INT_MAX;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        V[a[i]].push_back(i);
        if (i > 1) F[i] = F[i - 1] + (abs(a[i] - a[i - 1]) > k);
    }

    for (int i = 2; i <= n; ++i)
        if (a[i] == a[i - 1]) low[i] = low[i - 1];
        else low[i] = i - 1;

    for (int i = n - 1; i > 0; --i)
        if (a[i] == a[i + 1]) high[i] = high[i + 1];
        else high[i] = i + 1;

    F[n + 1] = F[n] + 1;
    for (int f = 1; f <= n; ++f)
    {
        int i = a[f];
        if (G[i]) continue;
        for (int j = 1; j < (int)V[i].size(); ++j)
            G[i] += max(0, F[V[i][j] - 1] - F[V[i][j - 1] + 1]);
        if (V[i].size()) G[i] += F[V[i][0] - 1] + max(0, F[n] - F[V[i].back() + 1]);
    }

    for (int i = 1; i <= n; ++i)
        G[a[i]] += (low[i] && high[i] && abs(a[low[i]] - a[high[i]]) > k && a[i] != a[i - 1]);

    for (int i = 1; i <= n; ++i) mi = min(mi, G[a[i]]);
    int p = maxn;
    for (int i = 1; i <= n; ++i)
        if (G[a[i]] == mi) p = min(p, a[i]);
    cout << p;
    return 0;
}
