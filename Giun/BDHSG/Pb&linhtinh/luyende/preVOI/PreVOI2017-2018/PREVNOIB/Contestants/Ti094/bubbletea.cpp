#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define task "bubbletea"
#define N 1000001
#define MOD 1000000007
int n, k, b[N], trc[N], trc2[N], fr[N], fr2[N], l[N], e[20][N]  , sl[N], typ[N];
ll f[1025][11][11],d[N],  d2[N], res = 1e18, su = 0;
vector < pair < int , ll > > a[N];

void dfs(int u, int p)
{
    for(int i=0; i<a[u].size(); i++)
        {
            int v = a[u][i].F;
            ll w = a[u][i].S;
            if (v != p)
            {
                l[v] = l[u] + 1;
                d[v] = d[u] + w;
                e[0][v] = u;
                dfs(v,u);
            }
        }
}

int get(int x, int i)
{
    return (x >> i) & 1;
}

int pre(int x, int i)
{
    return ~(1 << i) & x;
}

int lca(int x, int y)
{
    for(int i=19; i>=0; i--)
        if (l[e[i][x]] >= l[y]) x = e[i][x];
    for(int i=19; i>=0; i--)
        if (l[e[i][y]] >= l[x]) y = e[i][y];
    for(int i=19; i>=0; i--)
        if (e[i][x] != e[i][y]) x = e[i][x], y = e[i][y];
    while (x != y)
    {
        x = e[0][x];
        y = e[0][y];
    }
    return x;
}

int check(int x, int y, int u, int v)
{
    memset(fr,0,sizeof(fr));
    memset(trc, 0, sizeof(trc));
    fr[x]  = 1;
    queue < int >  q;
    q.push(x);
    int ok =0;
    while (!q.empty())
        {
            int x1 = q.front();
            q.pop();
            for(int i=0; i<a[x1].size(); i++)
            {
                int y1 = a[x1][i].F;
                if (!fr[y1])
                    {
                        trc[y1] = x1;
                        fr[y1] = 1;
                        if (y1 == y)
                        {
                            ok = 1;
                            break;
                        }
                        else q.push(y1);
                    }

            }
            if (ok == 1 ) break;
        }
    while (!q.empty()) q.pop();
    q.push(u);
    ok = 0;
    memset(fr2,0,sizeof(fr2));
    fr2[u]  =1;
    memset(trc2, 0, sizeof(trc2));
    while (!q.empty())
        {
            int x1 = q.front();
            q.pop();
            for(int i=0; i<a[x1].size(); i++)
            {
                int y1 = a[x1][i].F;
                if (!fr2[y1])
                    {
                        trc2[y1] = x1;
                        fr2[y1] = 1;
                        if (y1 == v)
                        {
                            ok = 1;
                            break;
                        }
                        else q.push(y1);
                    }

            }
            if (ok == 1 ) break;
        }
    int dd = y;
    while (dd != x)
    {
        fr[dd] = 2;
        dd = trc[dd];
    }
    dd = v;
    while (dd != u)
    {
        if (fr[dd] == 2 && fr[trc2[dd]] == 2) return 0;
        dd = trc2[dd];
    }
    return 1;


}

ll kc(int u, int v)
{
    int x = lca(u,v);
    //int xx = e[0][x];
    return (d[u] - d[x] + d[v] - d[x]);
}
void xuli(int x)
{
    for(int i=1; i<k; i++)
        for(int j=i+1; j<=k; j++)
            if (get(x,i-1) ==  1 && get(x,j-1) == 1)
                {
                    int prex = pre(x,i-1);
                    prex = pre(prex, j-1);
                    if (prex != 0)
                    for(int u=1; u<k; u++)
                        {
                            int ok = 0;
                            for(int v=u+1; v<=k; v++)
                                if (get(prex,u-1) == 1 && get(prex,v-1) == 1)
                                    {
                                        int x1 = b[i];
                                        int y1 = b[j];
                                        int x2 = b[u];
                                        int y2 = b[v];
                                        if (!check(x1,y1,x2,y2))
                                            {
                                                ok = 1;
                                                break;
                                            }
                                        else
                                            {
                                                f[x][i][j] = max(f[x][i][j], max(kc(x1,y1), f[prex][u][v]));
                                            }
                                    }
                            if (ok == 1) f[x][i][j] = 0;
                        }
                    else f[x][i][j] = kc(b[i], b[j]);
                }
}
void sub1()
{
    l[1] = 1;
    dfs(1,1);
    for(int i=1; i<=19; i++)
        for(int j=1; j<=n; j++)
            e[i][j] = e[i-1][e[i-1][j]];
    int M = (1 << k) - 1;
    for(int i=1; i<=M; i++)
    {
        int sl = __builtin_popcount(i);
        if (sl > 1 && sl % 2 == 0) xuli(i);
    }
    for(int i=1; i<k; i++)
        for(int j=i+1; j<=k; j++)
            if (f[M][i][j] > 0) res = min(res, f[M][i][j]);
    if (res < 1e18) cout << res;
    else cout << -1;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=k; i++) cin >> b[i];
    for(int i=1; i<n; i++)
        {
            int u , v, w;
            cin >> u >> v >> w;
            a[u].pb(mp(v,w));
            a[v].pb(mp(u,w));
        }

    if (k <= 10) sub1();

    return 0;
}
