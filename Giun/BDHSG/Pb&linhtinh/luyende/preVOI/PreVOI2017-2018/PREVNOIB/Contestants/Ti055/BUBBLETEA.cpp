#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef pair<long long, long long> ii;
const int maxN = 50050;
long long N, K, maxx, res, tes, h[maxN], par[maxN], Num[maxN], Tail[maxN], cnt;
ii P[maxN][40];
vector<ii> edges[maxN];
vector<int> happy;
bool kt[maxN];
ii p[maxN];

void DFS(int u, int p)
{
    Num[u] = ++cnt;
    for (int i = 0; i < edges[u].size(); i++)
    {
        long long w = edges[u][i].f;
        int v = edges[u][i].s;
        if (Num[v] == 0)
        {
            par[v] = u;
            h[v] = h[u] + 1;
            P[v][0] = ii(u, w);
            DFS(v, u);
        }
    }
    Tail[u] = cnt;
}

ii LCA(int u, int v)
{
    int cur = 0;
    if (h[u] < h[v])    swap(u, v);
    for (int i = 20; i >= 0; i--)
        if (h[P[u][i].f] >= h[v])
        {
            cur = cur + P[u][i].s;
            u = P[u][i].f;
        }
    if (u == v) return ii(u, cur);
    for (int i = 20 ; i >= 0; i--)
        if (P[u][i].f != P[v][i].f)
        {
            cur = cur + P[u][i].s + P[v][i].s;
            u = P[u][i].f;
            v = P[v][i].f;
        }
    cur = cur + P[u][0].s + P[v][0].s;
    return ii(P[u][0].f, cur);
}

void check()
{
    long long tes = 0;
    for (int i = 1; i <= K/2; i++)
    {
        int u = p[i].f;
        int v = p[i].s;
        ii q = LCA(u, v);
        int pr = q.f;
        for (int j = 1; j <= K/2; j++)
        {
            if (j == i) continue;
            int nu = p[j].f;
            int nv = p[j].s;
            if (nu != pr)
            {
                if (Num[pr] <= Num[nu] && Tail[nu] <= Tail[pr])
                {
                    if (Num[nu] <= Num[u] && Tail[u] <= Tail[nu]) return;
                    if (Num[nu] <= Num[v] && Tail[v] <= Tail[nu]) return;
                }
            }
            if (nv != pr)
            {
                if (Num[pr] <= Num[nv] && Tail[nv] <= Tail[pr])
                {
                    if (Num[nv] <= Num[u] && Tail[u] <= Tail[nv]) return;
                    if (Num[nv] <= Num[v] && Tail[v] <= Tail[nv]) return;
                }
            }
        }
        tes = max(tes, q.s);
    }
    res = min(res, tes);
}

void snp(int i, int k)
{
    if (i == (K/2 + 1))
    {
        check();
        return;
    }
    for (int j = 0; j < happy.size(); j++)
    {
        long long u = happy[j];
        if (kt[u] == true)  continue;
        kt[u] = true;
        if (k == 1)
        {
            p[i].f = u;
            snp(i, 2);
            kt[u] = false;
        }
        else
        {
            p[i].s = u;
            snp(i + 1, 1);
            kt[u] = false;
        }
    }
}

int main()
{
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= K; i++)
    {
        int x;
        cin >> x;
        happy.push_back(x);
    }
    for (int i = 1; i < N; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        maxx = max(maxx, c);
        edges[u].push_back(ii(c, v));
        edges[v].push_back(ii(c, u));
    }
    if (K == N)
    {
        cout << maxx;
        exit(0);
    }
    if (K <= 10)
    {
        par[1] = -1;
        h[1] = 1;
        P[1][0] = ii(1, 0);
        DFS(1, -1);
        for (int k = 1; k <= 20; k++)
            for (int i = 1; i <= N; i++)
            {
                P[i][k].f = P[P[i][k - 1].f][k - 1].f;
                P[i][k].s = P[i][k - 1].s + P[P[i][k - 1].f][k - 1].s;
            }
        res = 1e17;
        snp(1, 1);
        if (res == 1e17)    cout << -1;
        else    cout << res;
        exit(0);
    }
    cout << -1;
    return 0;
}
