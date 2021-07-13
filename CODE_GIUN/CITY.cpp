#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define pl pair<ll,ll>
const ll maxn = 1e6 + 7 ;
using namespace std;
ll n , m , u , v , w , trace[maxn] = {0};
vector< pair <ll,ll>> G[maxn];
bool c[maxn] = {0};
vector<pl> res;
void prim ()
{
    ll ans = 0;
    priority_queue< pl, vector<pl> , greater<pl>> q;
    q.push({0,1} );
    ll u , tmp ; 
    while (q.size())
    {
        u = q.top().second;
        tmp = q.top().first;
        q.pop();
        if (c[u]) continue;
        c[u] = 1;
        res.push_back({u , trace[u]});
        ans += tmp;
        for (pl v : G[u])
        { 
            q.push(v) ;
            trace[v.second] = u;
        }
    }
    cout << res.size()-1 << " " << ans << endl;
    for (int i = 1 ; i < res.size() ; i++) cout << res[i].second << " " << res[i].first << endl;
}

int main()
{
    giuncute;
    freopen("city.inp","r",stdin);
    freopen("city.out","w",stdout);
    cin >> n >> m ; 
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }
    prim();    
}
