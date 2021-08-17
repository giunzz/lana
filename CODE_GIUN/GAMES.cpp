#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e9 + 7;
const ll maxn = 2e3 +7;
using namespace std;
ll n , m , s , t , a , b , u , v , w;
ll fa[maxn] , fb[maxn] , fc[maxn];
vector<pl> g[maxn];

void dij (ll node , ll f[maxn])
{
    priority_queue < pl , vector<pl> , greater<pl> > pq;
    for (int i = 1 ; i <= n ; i++) f[i] = oo;
    f[node] = 0 ;
    pq.push({0,node});
    while (!pq.empty())
    {
        u = pq.top().second;
        ll dis_u = pq.top().first;
        pq.pop();
        if (f[u] != dis_u) continue;
        for (pl v : g[u])
        {
            if (f[v.first] > dis_u + v.second)
            {
                f[v.first] = dis_u + v.second;
                pq.push({f[v.first] , v.first});
            }
        }
    }
    if (f[s] == oo) f[s] = -oo;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    cin >> s >> t >> a >> b ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    g[a].push_back({b , 0});
    dij(a , fa);
    dij(b , fb);
    if (fa[s] == -oo && fb[s] == -oo) cout << -1;
    else 
    {
        if (fa[s] >= fb[s])
        {
            dij(b , fc);
            if (fc[t] == oo) cout << -1;
            else cout << fa[s] + fc[t];
        }
        else 
        {
            dij(a, fc) ;
            if (fc[t] == oo) cout << -1;
            else cout << fb[s] + fc[t];
        }
    }
}