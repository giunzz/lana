#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 + 7;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , root , u , v , f[maxn];
vector<ll> g[maxn] , child[maxn];


void dfs (ll u , ll father)
{
    f[u] = 0;
    for (ll v : g[u])
    {
        if (v == father) continue;
        dfs(v , u);
        child[u].push_back(f[v]);
    }
    sort (child[u].rbegin() , child[u].rend());
    for (int v = 0 ; v < child[u].size() ; v ++)
    {
        f[u] = max (f[u] , child[u][v] + v + 1);
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> root;
    for (int i = 1 ; i < n ; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root , -1);
    cout << f[root];
}

