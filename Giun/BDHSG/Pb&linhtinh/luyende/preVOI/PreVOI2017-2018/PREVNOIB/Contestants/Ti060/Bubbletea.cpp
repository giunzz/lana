#include <bits/stdc++.h>

using namespace std;

const int maxn = 5*1e4+5;

typedef pair<long long, int> li;

int n, k;
int vc[maxn];
vector <li> g[maxn];
long long res = 0;

int main()
{
    freopen("Bubbletea.inp", "r", stdin);
    freopen("Bubbletea.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=k; i++)
        cin >> vc[i];
    for (int i=1; i<n; i++)
    {
        int u, v; long long w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
        res = max(w, res);
    }
    if (k == n) cout << res;
    else cout << -1;
}
