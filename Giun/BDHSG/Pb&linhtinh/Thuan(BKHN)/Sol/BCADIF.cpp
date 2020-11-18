#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

vector <int> adj[105];
vector <int> con_adj[105];

int n,m,k;
int cnt[105][105];
int cur[105];
int pos[105];
int id[105];

bool cmp(int i, int j)
{
    return adj[i].size() < adj[j].size();
}

bool solve(int i, int mx)
{
    if (i > m) return true;
    int u = id[i];
    bool res = 0;
    for (int v : adj[u]) if (!cnt[u][v] && cur[v] < mx)
    {
        cur[v]++;
        for (int w : con_adj[u])
        {
            cnt[w][v]++;
        }
        if (solve(i + 1, mx)) return true;
        cur[v]--;
        for (int w : con_adj[u])
        {
            cnt[w][v]--;
        }
    }
    return false;
}

void reset()
{
    memset(cnt, 0, sizeof(cnt));
    memset(cur, 0, sizeof(cur));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int sz;
        cin >> sz;
        while (sz--)
        {
            int j;
            cin >> j;
            adj[j].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        id[i] = i;
    }
    sort(id + 1, id + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        pos[id[i]] = i;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int u,v;
        cin >> u >> v;
        if (pos[u] < pos[v]) con_adj[u].push_back(v);
        else con_adj[v].push_back(u);
    }
    int lo = -1;
    int hi = m + 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) >> 1;
        reset();
        if (solve(1, mid)) hi = mid;
        else lo = mid;
    }
    if (hi > m) cout << -1;
    else cout << hi;
    return 0;
}
