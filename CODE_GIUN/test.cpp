#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pl pair<ll,ll> 
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0)
ll n , m , s , t , dp[(int) 1e5+7];
vector<pair<ll,ll>> G[(int)1e5+7];

void dijkstra(int node)
{
    priority_queue< pl , vector<pl> , greater<pl>> p;
    for (int i = 1 ; i <= n ; i++) dp[i] = 1e17;
    p.push({0,node});
    dp[node] = 0 ;
    while (p.size())
    {
        ll u = p.top().second  , disu = p.top().first;
        p.pop();
        cerr << u << " " << disu << endl;
        if (dp[u] != disu) continue;
        for (pl v : G[u])
        {
            if (dp[v.first] > disu + v.second )
            {
                dp[v.first] = disu + v.second;
                p.push({dp[v.first] , v.first});
            }
        }
    }

}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++ )
    {
        ll u , v , w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    cin >> s >> t ;
    cerr << s << " " << t << endl;
    dijkstra(s);
    for (int i = 1 ; i <= n ; i++) cerr << dp[i] << " ";
    if (dp[t] != 1e17) cout << dp[t];
    else cout << -1;
}