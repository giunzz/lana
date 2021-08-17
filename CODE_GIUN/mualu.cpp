#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , m , x , u , v , c , p[maxn] ={0} , sz[maxn] = {0};
vector<ll> g[maxn];
ll ans = 0 ;

ll get(ll u)
{
    if (u == p[u]) return u;
    return p[u] = get(p[u]);
}
void ghep (ll u , ll v)
{
    u = get(u) , v = get(v);
    if (u == v) return ;
    if (sz[u] < sz[v]) swap(u,v);
    sz[u] += sz[v];
    p[v] = u;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> x;
    for (int i = 1 ; i <=  n ; i++) p[i] = i;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> c;
        if (c < x ) continue;
        ghep(u , v);
    }
    for (int i = 1 ; i <= n ; i++)
        if (p[i] == i) ans++;
    cout << ans;
}
