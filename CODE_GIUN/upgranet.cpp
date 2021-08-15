#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , m;
ll p[maxn] , size[maxn] , sz[maxn] = {0} , up[maxn][30] ={{0}} , dp_min[maxn][30];
vector<pl> g[maxn];

struct giun
{
    ll x , y , val;
}a[maxn];

bool cmp (giun &b , giun&c)
{
    return b.val > c.val;
}

ll dsu(ll u)
{
    if (u == p[u]) return u;
    return p[u] = dsu(p[u]);
}

bool ghep(ll u , ll v)
{
    u = dsu(u) , v = dsu(v);
    if (u == v) return 0;
    if (size[u] < size[v]) swap(u,v);
    size[u] += size[v];
    p[v] = u ;
    return 1;
}

void dfs(ll u , ll father)
{
    up[u][0] = father;
    for (pl i : g[u])
    {
        ll v = i.first , w = i.second;
        if (v == father) continue;
        up[v][0] = u;
        sz[v] = sz[u] + 1;
        dp_min[v][0] = w;
        for (int j = 1 ; j < 19 ; j++) 
        {
            up[v][j] = up[up[v][j-1]][j-1];
            dp_min[v][j] = min (dp_min[v][j-1] , dp_min[up[v][j-1]][j-1]);
        }
        dfs(v , u);
    }
}

ll lca (ll u , ll v)
{
    ll mi = INT_MAX;
    if (sz[u] < sz[v]) swap(u,v);
    ll k = sz[u] - sz[v];
    for (int i = 19 ; i >= 0 ; i--)
    {
        if (k & (1 << i))
        {
            mi = min(mi , dp_min[u][i]);
            u = up[u][i];
        }
    }
    if (u != v)
    {
        for (int i = 19 ; i >= 0 ; i--)
        {
            if (up[u][i] != up[v][i])
            {
                mi = min ({mi , dp_min[u][i] , dp_min[v][i]});
                u = up[u][i];
                v = up[v][i];
            }
        }
        mi = min ({mi , dp_min[u][0] , dp_min[v][0]});
    }
    return mi;
}


int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= 20 ; j++) dp_min[i][j] = oo;
    for (int i = 1 ; i <= m ; i++) cin >> a[i].x >> a[i].y >> a[i].val;
    sort( a + 1 , a + 1 + m , cmp);
    for (int i = 1 ; i <= m ; i++) p[i] = i , size[i] = 1;
    ll cnt = 0 ;
    vector<giun>tmp;
    for (int i = 1 ; i <= m ; i++)
    {
        if (cnt != n-1 && ghep(a[i].x , a[i].y))
        {
            cnt++;
            g[a[i].x].push_back({a[i].y , a[i].val});
            g[a[i].y].push_back({a[i].x , a[i].val});
        }
        else tmp.push_back({a[i].x , a[i].y, a[i].val});
    }
    dfs(1 , -1);
    ll ans = 0 ;
    for (int i = 0 ; i < (int) tmp.size() ; i++)
    {
        ll c = lca(tmp[i].x , tmp[i].y);
        ans = ans + (c - tmp[i].val);
    }
    cout << ans;
}