/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 307
#define Task "TABLE"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int m, n, k, a[maxn][maxn], color[maxn][maxn];
long long d[maxn][maxn];
pii tr[maxn][maxn], luu;
vector <pii> vect[maxn][maxn];
priority_queue <pair <pii, long long>> pr;

void in()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
}

void Dijkstra(pii s)
{
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            d[i][j] = -maxC;
            tr[i][j] = mp(0,0);
        }
    d[s.F][s.S] = 1ll*a[s.F][s.S];
    while (pr.size()) pr.pop();
    pr.push(mp(s,d[s.F][s.S]));
    while (pr.size())
    {
        pii u = pr.top().F;
        long long l = pr.top().S;
        pr.pop();
        if (d[u.F][u.S] != l) continue;
        for (int i = 0; i < vect[u.F][u.S].size(); ++i)
        {
            pii v = vect[u.F][u.S][i];
            if (color[v.F][v.S]) continue;
            if (d[v.F][v.S] < d[u.F][u.S] + 1ll*a[v.F][v.S])
            {
                d[v.F][v.S] = d[u.F][u.S] + 1ll*a[v.F][v.S];
                tr[v.F][v.S] = u;
                pr.push(mp(v, d[v.F][v.S]));
            }
        }
    }
}

void trace(pii s, pii t)
{
    pii cur = tr[t.F][t.S];
    int maxx = -maxC;
    while (cur != s)
    {
        if (maxx < a[cur.F][cur.S])
        {
            maxx = a[cur.F][cur.S];
            luu = cur;
        }
        cur = tr[cur.F][cur.S];
    }
}

void solve()
{
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (j+1 <= n) vect[i][j].pb(mp(i,j+1));
            if (i+1 <= m) vect[i][j].pb(mp(i+1,j));
        }
    int u, v, p, q;
    while (k--)
    {
        cin >> u >> v >> p >> q;
        Dijkstra(mp(u,v));
        trace(mp(u,v), mp(p,q));
        color[luu.F][luu.S] = 1;
        Dijkstra(mp(u,v));
        cout << d[p][q] << "\n";
        color[luu.F][luu.S] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
