// Sparse Table
#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e4 + 7;
using namespace std;

ll t , n , m , x ,q , u , v;
ll size[maxn] , up[maxn][20] = {0};
vector<ll> child[maxn];

void dfs (ll u)
{
    for (ll v : child[u])
    {
        size[v] = size[u]  + 1 ;
        up[v][0] = u ;
        for (int j = 1 ; j < 20 ; j++)
            up[v][j] = up[up[v][j-1]][j-1];
        dfs(v);
    }
}

ll lca (ll u , ll v)
{
    if (size[v] > size[u]) swap(u,v);
    ll k = size[u] - size[v];
    for (ll j = 19 ; j >= 0 ; j-- )
        if (k & (1 << j)) u = up[u][j] ;
    if (u == v) return u;
    for(int j = 19; j >= 0; j--) 
    {
		if(up[u][j] != up[v][j]) 
        {
			u = up[u][j];
			v = up[v][j];
		}
	}
	return up[u][0];
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> m ;
        while (m--)
        {
            cin >> x ;
            child[i].push_back(x);
        }
    }
    dfs(0);
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        cout << lca(u,v) << endl;
    }
}