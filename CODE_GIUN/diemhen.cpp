#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 + 7;
const ll maxn = 1e5 + 7;
using namespace std;

ll n , m , k , u , v , w , a , b ;
ll fa[maxn] , fb[maxn];
vector<pl> g[maxn];

void dijkstra( ll f[] , ll node)
{
    priority_queue<pl, vector<pl> , greater<pl>> q;
    for (int i = 1 ; i <= n ; i++) f[i] = oo;
    f[node] = 0;
    q.push({0 , node});
    while (!q.empty())
    {
        ll dis = q.top().fi;
        u = q.top().se;
        q.pop();
        if (dis != f[u]) continue;
        for (pl v : g[u])
        {
            if (f[v.first] > dis + v.second ) 
            {
                f[v.first] = dis + v.second;
                q.push(make_pair(f[v.first] , v.first));
            }
        }
    }
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> k ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    
    dijkstra(fa, 1);
    dijkstra(fb, n);

    for (int i = 1 ; i <= k ; i++)
    {
        cin >> a >> b;
        ll ans = oo;
        for (int j = 1 ; j <= n ; j++)
        {
            if (fa[j] == oo || fb[j] == oo) continue;
            ans = min(ans , fa[j] * a + fb[j] * b);
        }
        cout << ans << endl;
    }
}