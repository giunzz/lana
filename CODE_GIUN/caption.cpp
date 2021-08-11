#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e6 + 7;
using namespace std;
ll n , m, s , t , u , v , w , x;
ll  ans = 0 , a[maxn] = {0};
ll  MINF [maxn] ={0};
vector<pl> g[maxn];
ll DIJKSTRA (int s , int t)
{
    priority_queue<pl, vector<pl> , greater<pl>> pq;
    for (int i = 1 ; i <= n ; i++) MINF[i] = MOD ;
    MINF[s] = 0;
    pq.push(pl(0,s));
    ll dis_u;
    while (!pq.empty())
    {
        u = pq.top().second ; 
        if (u == t ) return MINF[u];
        pq.pop();
        for (pl v : g[u])
        {
            dis_u = MINF[u] + v.second;
            if (a[v.first] > dis_u  && MINF[v.first] > dis_u ) 
            {
                MINF[v.first] = dis_u ;
                pq.push(make_pair(MINF[v.first] , v.first));
            }
        }
    }
    if ( MINF[t] == MOD) return -1;
    return MINF[t];
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> s >> t;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i] ;
        if (a[i] == 0) a[i] = MOD;
    }
    for (int i = 1; i <= m ;  i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    cout << DIJKSTRA(s , t);
}
