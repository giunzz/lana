#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define task "tree"
#define N 1000001
int n, b[N], c[N], con[N][3], res = 0, typ[N], sl[N], del[N], fr[N];
vector < int > a[N];

void dfs(int u, int p)
{
    for(int i=0; i<a[u].size(); i++)
        {
            int v = a[u][i];
            if (v != p)
                {
                    sl[u] ++;
                 //   bac[v] = bac[u] + 1;
                    con[u][sl[u]] = v;
                    dfs(v,u);
                }
        }
    if (sl[u] == 0) typ[p] = 1;
    if (sl[u] > 0)
    {
        int s = 0;
        for(int i=1; i<=sl[u]; i++)
            if (con[u][i] != 0) s += b[con[u][i]];
        del[u] = b[u] - s;
    }
}

void dfs2(int u)
{
    if (typ[u] == 1 && u != 1)
    {
        res += abs(del[u]);
        c[u] = sl[u];

    }
    else
    {
        for(int i=1; i<=sl[u]; i++)
            {
                dfs2(con[u][i]);
                del[u] -= c[con[u][i]] - b[con[u][i]];
            }
        res += abs(del[u]);
        c[u] = b[u] - del[u];
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> b[i], c[i] = b[i];
    for(int i=1; i<n; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
//    bac[1] = 1;
    dfs(1,1);
    dfs2(1);
    cout << res;
    return 0;
}
