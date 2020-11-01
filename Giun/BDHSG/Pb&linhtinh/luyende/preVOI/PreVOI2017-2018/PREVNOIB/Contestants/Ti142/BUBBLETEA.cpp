#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define PB push_back
#define maxc 1000000007
#define N 50005
#define LN 20
using namespace std;

int n, k, play[N], res = maxc, h[N], dist[N], p[N][LN], dd[N], tt, xx[N], dem[N];
vector<pii> a[N];
void setup()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &play[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}
void DFS(int u, int pa)
{
    for (auto z : a[u])
    {
        int v = z.F;
        int w = z.S;
        if (v == pa) continue;
        dist[v] = dist[u] + w;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LN; i++)
            p[v][i] = p[p[v][i-1]][i-1];
        DFS(v, u);
    }
}
int LCA(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);
    int delta = h[v] - h[u];
    for (int i = LN-1; i >= 0; i--)
        if ((delta >> i) & 1) v = p[v][i];
    if (u == v) return u;
    for (int i = LN-1; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

bool ok()
{
    for (int i = 1; i <= k/2; i++) dem[i] = 0;
    for (int i = 1; i <= k; i++) dem[xx[i]]++;
    for (int i = 1; i <= k/2; i++)
        if (dem[i] != 2) return 0;
    return 1;
}

bool go(int u, int v)
{
    while (u != v)
    {
        if (dd[u] == tt) return 0;
        dd[u] = tt;
        u = p[u][0];

    }
    return 1;
}
void tinh()
{
    vector<pii> all;
    for (int i = 1; i <= k; i++)
        for (int j = i+1; j <= k; j++)
            if (xx[i] == xx[j]) all.PB(mp(play[i], play[j]));
    int ans = 0;
    for (auto z : all)
    {
        int u = z.F;
        int v = z.S;
        int lca = LCA(u, v);
        if (!go(u, lca) || !go(v, lca)) return;
        ans = max(ans, dist[u] + dist[v] - 2*dist[lca]);
    }
    res = min(res, ans);
}
void duyet(int pos)
{
    if (pos > k && ok())
    {
        tt++;
        tinh();
        return;
    }
    if (pos > k) return;
    for (int i = 1; i <= k/2; i++)
    {
        xx[pos] = i;
        duyet(pos+1);
    }
}
void sub1()
{
    duyet(1);
    if (res == maxc) cout <<-1;
    else cout <<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    setup();
    DFS(1, -1);
    sub1();
}
