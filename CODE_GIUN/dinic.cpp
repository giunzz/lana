#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 1e3 + 7;
using namespace std;

ll n , m , s , t , ans = 0 ;
ll level[maxn] , cost[maxn][maxn];
vector<ll> g[maxn];

bool bfs(ll s , ll t)
{
    memset(level, 0, sizeof level);
    level[s] = 1;
    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (u == t) return 1;
        for (ll v : g[u])
        {
            if (level[v] == 0 && cost[u][v] != 0)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

ll dfs (ll u , ll mi)
{
    ll val;
    if (u == t) return mi;
    for (int v : g[u])
    {
        if (level[v] == level[u] + 1) 
        {
            val = dfs(v , min(mi , cost[u][v]));
            if (val != 0)
            {
                cost[u][v] -= val;
                cost[v][u] += val;
                return val;
            }
        }
    }
    return 0;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> s >> t ;
    for (int i = 1 ; i <= m ; i++)
    {
        ll u , v , w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u][v] += w;
    }
    while (bfs(s , t) == true) ans += dfs(s , 1e18) ;
    cout << ans;
}