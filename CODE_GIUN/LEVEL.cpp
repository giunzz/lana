#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n , visited[maxn] , size[maxn] = {0};
vector <ll> g[maxn];

void dfs (ll u , ll father )
{
    for (ll v : g[u])
    {
        if (v == father) continue;
        size[v] = size[u]  + 1 ;
        dfs(v , u);
    }
}

int main()
{
    giuncute;
    freopen("level.inp","r",stdin);
    freopen("level.out","w",stdout);
    cin >> n ; 
    ll u , v;
        for (int i = 1 ; i <= n ; i++) g[i].clear();

    for (int i = 1 ; i < n ; i++)
    {
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> u ;
    size[1] = 1;
    dfs(1 , -1);
    ll ans = 0 ;
    for (int i = 1 ; i <= n ; i++)
        if (size[i] == u) ans++;
    cout << ans;
}