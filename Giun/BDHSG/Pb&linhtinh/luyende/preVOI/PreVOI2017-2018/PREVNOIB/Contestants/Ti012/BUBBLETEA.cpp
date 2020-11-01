#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 50005
#define Task "BUBBLETEA"
using namespace std;
int n,k,b[maxn],pos[maxn],par[maxn][20],kc[500][500],h[maxn];
long long ans = 20ll*maxc;
vector <pair <int,int> > a[maxn];
bool dd[500][500],use[500];
int lca(int u,int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u]-h[v];
    for (int i = 17; i >= 0;i--)
        if ((delta >> i) & 1) u = par[u][i];
    if ( u == v) return u;
    for (int i = 17;i >= 0;i--)
        if ( par[u][i] != par[v][i])
    {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}
void trau(int cnt)
{
    if (cnt == k)
    {
        memset(dd,0,sizeof dd);
        long long temp = 0;
        for (int i = 1; i <= k; i += 2)
        {
            int qwe = lca(b[pos[i]],b[pos[i+1]]);
            int u = b[pos[i]];
            int v = b[pos[i+1]];
            while (u != qwe)
            {
                if (dd[u][par[u][0]]) return;
                dd[u][par[u][0]] = 1;
                temp += kc[u][par[u][0]];
            }
            u = v;
            while (u != qwe)
            {
                if (dd[u][par[u][0]]) return;
                dd[u][par[u][0]] = 1;
                temp += kc[u][par[u][0]];
            }
        }
        ans = min(ans,temp);
        return;
    }
    ++cnt;
    FOR(i,1,k)
    if (!use[i])
    {
        use[i] = 1;
        pos[cnt] = i;
        trau(cnt);
        use[i] = 0;
    }
}
void dfs(int u)
{
    for (auto v :a[u])
        if (par[u][0] != v.F)
        {
            par[v.F][0] = u;
            FOR(i,1,17) par[v.F][i] = par[par[v.F][i-1]][i-1];
            dfs(v.F);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> k;
    FOR(i,1,k) cin >> b[i];
    h[1] = 1;
    FOR(i,1,n-1)
    {
        int x,y,z;
        cin >> x >> y >> z;
        kc[x][y] = kc[y][x] = z;
        a[x].pb(mp(y,z));
        a[y].pb(mp(x,z));
    }
    dfs(1);
    trau(0);
    cout << ans;
    return 0;
}
