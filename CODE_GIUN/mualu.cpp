#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , m , x , u , v , c , visited[maxn] ={0};
vector<ll> g[maxn];
ll ans = 0 ;
void dfs(ll u)
{
    visited[u] = 1;
    for (ll v : g[u])
        if (!visited[v]) dfs(v);
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> x;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> c;
        if (c >= x) g[u].push_back(v) , g[v].push_back(u); // , cerr << u << " " << v << endl;
    }
    for (int i = 1 ; i <= n ; i++)
        if (!visited[i]) ans++ , dfs(i);
    cout << ans;
}
