#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pi pair<ll,pair<ll,ll>>
const ll maxn = 2008;
ll dp[maxn][maxn], trace[maxn];
ll m , n , u , v , k , t , x;
vector<pair<ll,pair<ll,ll>>> G[maxn];
void DIJKSTRA (int startnode)
{
    priority_queue< pi, vector<pair<ll,pair<ll,ll>>> , greater<pi>> pq;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= k ; j++) dp[i][j] = 1e17;
    }
        pq.push({0,{startnode,0}});
        dp[startnode][0] = 0 ;
        while (pq.size())
        {
            int u = pq.top().second.first , costu = pq.top().second.second , timeu = pq.top().first;
            pq.pop();
            if(timeu != dp[u][costu]) continue;
            for(auto i : G[u])
            {
                ll v = i.first, costv = costu + i.second.second, timeuv = i.second.first;
                if(costv < k && dp[v][costv] > dp[u][costu] + timeuv)
                {
                    dp[v][costv] = dp[u][costu] + timeuv;
                    pq.push({dp[v][costv], {v, costv}});
<<<<<<< HEAD
                    trace[costv] = costu;
=======
>>>>>>> 33543962cdea18d94ef15896eab6f4a4d35efb14
                }
            }
        }
}
ll o ,p ;
int main()
{
	giuncute;
	freopen("MEETING.inp","r",stdin);
	freopen("MEETING.out","w",stdout);
    cin >> k >> n >> m ;
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> u >> v >> t >> x;
        G[u].push_back(make_pair(v,make_pair(t,x)));
        G[v].push_back(make_pair(u,make_pair(t,x)));
    }
    cin >> o >> p;
    DIJKSTRA(o);
<<<<<<< HEAD
    // cerr << n << endl;
    // for (int  i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 1 ; j <= k ; j++) cerr<< dp[i][j] << " ";
    //     cerr << endl;
    // }
    // cerr << dp[4][7] ;
    // if (dp[o][p] != 1e17) cout << dp[p][7];
    // else cout << -1;
    long long res = 1e9;
    for(int i = 1; i <= k; ++i){
        res = min(dp[p][i], res);
        cerr << dp[p][i] << ' ' << i << '\n';
    }
    cout << res;
=======
    ll ans = 1e17 ;
    for (int i = 1 ; i <= k ; i++) ans = min(dp[p][i],ans);
    if (ans != 1e17) cout << ans;
    else cout << -1;
>>>>>>> 33543962cdea18d94ef15896eab6f4a4d35efb14
}