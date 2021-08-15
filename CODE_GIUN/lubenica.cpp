#include <bits/stdc++.h>
#define ll int
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , k , u , v , w ;
ll size[maxn] = {0} , up[maxn][25] ={0};
ll dp_min[maxn][25] = {0} , dp_max[maxn][25] = {0};
vector<pl> g[maxn];

void dfs(ll u , ll father)
{
    up[u][0] = father;
    for (pl i : g[u])
    {
        v = i.first , w = i.second;
        if (v == father) continue;
        size[v] = size[u] + 1;
        up[v][0] = u;
        dp_min[v][0] = dp_max[v][0] = w;
        for (int j = 1 ; j < 20 ; j++)
        {
            up[v][j] = up[up[v][j-1]][j-1];
            dp_min[v][j] = min(dp_min[v][j-1] , dp_min[up[v][j-1]][j-1]);
            dp_max[v][j] = max(dp_max[v][j-1] , dp_max[up[v][j-1]][j-1]);
        }
        dfs(v , u);
    }
}

void lca (ll u , ll v)
{
    ll ma = INT_MIN , mi = INT_MAX;
    if (size[u] < size[v]) swap(u,v);
    ll k = size[u] - size[v];
    for (int i = 19 ; i >= 0 ; i--)
    {
        if (k & (1 << i)) 
        {
            mi = min( mi , dp_min[u][i]);
			ma = max( ma , dp_max[u][i]);
            u = up[u][i];
        }
    }  
    if (u != v)
    {
        for (int i = 19 ; i >= 0 ; i--)
        {
            if (up[u][i] != up[v][i] )
            {
                mi = min({mi , dp_min[u][i] , dp_min[v][i]});
                ma = max({ma , dp_max[u][i] , dp_max[v][i]});
                u = up[u][i];
                v = up[v][i];
            }
        } 
        mi = min({mi , dp_min[u][0] , dp_min[v][0]});
        ma = max({ma , dp_max[u][0] , dp_max[v][0]});       
    }
    cout << mi << " " << ma << endl;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ;  j <= 20 ; j++) dp_min[i][j] = INT_MAX , dp_max[i][j] = 0;
    for (int i = 1 ; i < n ; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1 , -1);
    cin >> k;
    for (int i = 1  ; i <= k ; i++)
    {
        cin >> u >> v;
        lca(u,v);
    }
}