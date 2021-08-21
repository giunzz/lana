#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , q , s , f , t , p ;
ll  up[maxn][25] , level[maxn] = {0};
vector<ll> child[maxn];

void dfs(ll u , ll father)
{
    up[u][0] =  father;
    for (int v : child[u])
    {
        if (v == father) continue;
        level[v] = level[u] + 1;
        up[v][0] = u;
        for (int j = 1 ; j < 19 ; j++) up[v][j] = up[up[v][j-1]][j-1];
        dfs(v , u);
    }
}

ll lca (ll u , ll v)
{
    if (level[u] < level[v]) swap(u,v);
    ll k = level[u] - level[v];
    for (int i = 18 ; i >= 0 ; i--)
    {
        if (k & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = 18 ; i >= 0 ; i--)
    {
        if (up[u][i] != up[v][i]) 
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
ll sol (ll a , ll b , ll c)
{
    ll lca1 = lca(a,b) , lca2 = lca(a,c), lca3 = lca(b,c);
    if (level[lca1] < level[lca2]) lca1 = lca2;
    ll ans = level[a] - level[lca1] + 1;
    if (level[lca3] > level[lca1]) ans += level[lca3] - level[lca1];
    return ans;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> q;
    for (int i = 2 ; i <= n ; i++) cin >> p , child[p].push_back(i);
    dfs(1 , -1);
    while (q--)
    {
        cin >> s >> f >> t;
        cout << max({sol(s,f,t) , sol(f,s,t), sol(t,s,f)}) << endl;
    }
}