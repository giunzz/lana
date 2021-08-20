#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e3 + 7;
using namespace std;
ll n , m , cost[maxn][maxn] ={{0}} ,ans = 0 , level[maxn];
vector<ll> g[maxn];

bool bfs(ll s , ll t)
{
    memset(level , 0 , sizeof level);
    level[s] = 1 ;
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

ll dfs(ll u , ll mi)
{
    ll val ;
    if (u == 1000) return mi;
    for (ll v : g[u])
    {
        if (level[v] == level[u] + 1)
        {
            val = dfs(v , min(cost[u][v] , mi));
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
    cin >> n >> m ;
    ll u , v , t = 1000 , s = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        g[s].push_back(i) , g[i].push_back(s);
        cost[s][i] = 1;
    }
    ll y = 0;
    while (cin >> u >> v)
    {
        v = v + n;
        y = max(y,v);
        g[u].push_back(v) , g[v].push_back(u);
        cost[u][v] = 1;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        g[t].push_back(i+n) , g[i+n].push_back(t);
        cost[i+n][t] = 1;
    }
    while (bfs(s,t) == true) ans += dfs(s,1e18);
    cout << ans << endl;
    for (int i = n+1 ; i <= n+m ; i ++)
    {
        for (int j = 1 ; j <= n ; j++)
            if (cost[i][j] > 0) cout << j << " " <<  i - n << endl;
    }
}