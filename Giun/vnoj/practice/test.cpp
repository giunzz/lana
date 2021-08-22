#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e3 + 7;
using namespace std;

ll t , n , m , x ,q , u , v;
ll size[maxn] , up[maxn][25] = {0};
vector<ll> child[maxn];

void dfs (ll u , ll father)
{
    up[u][0] = father ;
    for (int j = 1 ; j < 19 ; j++)
        up[u][j] = up[up[u][j-1]][j-1];
    for (ll v : child[u])
    {
        if (v == father) continue;
        size[v] = size[u]  + 1 ;
        dfs(v,u);
    }
}

ll lca (ll u , ll v)
{
    if (size[v] > size[u]) swap(u,v);
    ll k = size[u] - size[v];
    for (ll j = 18 ; j >= 0 ; j-- )
    {
        if (k & (1 << j)) u = up[u][j];
    }
    if (u == v) return u;
    for(int j = 18; j >= 0; j--) 
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
    freopen("f.inp","r",stdin);
    freopen("f.out","w",stdout);
    cin >> t;
    // cerr << t;
    for (int k = 1 ; k <= t ; k ++)
    {
        cout << "Case " << k << ":" << endl;
        cin >> n;
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= 18 ; j++) up[i][j] = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            size[i] = 0 ;
            cin >> m ;
            while (m--)
            {
                cin >> x ;
                child[i].push_back(x);
            }
        }
        dfs(1 , (ll) -1);
        cin >> q;
        while (q--)
        {
            cin >> u >> v;
            cout << lca(u,v) << endl;
        }
    }
}