#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n , visited[maxn]  , t , m , f[maxn] = {0} , trace[maxn] = {0};
vector <ll> g[maxn];

ll bfs (ll node)
{
    ll ans = 0 ;
    queue<ll> q;
    for (int i = 1 ; i <= n ; i++) visited[i] = 0 , f[i] = 0;
    f[n] = 1e18;
    visited[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (int v : g[u] )
        {
            if (!visited[v]) 
            {
                q.push(v) , ans++;
                visited[v] = 1 ;
                f[v] = f[u] + 1;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cerr << f[i] << " ";
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t ;
    while (t--)
    {   cin >> n >> m ; 
        ll u , v;
        for (int i = 1 ; i <= n ; i++) g[i].clear();
        for (int i = 1 ; i <= m ; i++)
        {
            cin >> u >> v ;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << bfs(1) << endl;
    }
}