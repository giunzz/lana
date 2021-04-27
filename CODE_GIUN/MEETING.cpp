#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pi pair<ll,ll>
const ll maxn = 2008;
ll m , n , u , v , k , t , x;
vector<pair<ll,pair<ll,ll>>> G[maxn];
/*  
    dp[i][j] la thoi gian ngan nhat tu A den i mat j dong
    q.push({dp[i][j], {i, j}});
    *********************


    dp[i][j] = 1e17;
    q.push({0, {A, 0}});
    dp[A][0] = 0;
    while(q.size()){
        u = q.top.second.first, costu = q.top.second.second, timeu = q.top.first;
        q.pop();
        if(timeu != dp[u][costu]) continue;
        for(auto i : g[u]){
            ll v = i.v, costv = costu + i.cost, timeuv = i.time;
            if(costv <= k && dp[v][costv] > dp[u][costu] + timeuv){
                dp[v][costv] = dp[u][costu] + timeuv;
                q.push({dp[v][costv], {v, costv}});
            }
        }
    }

*/
void DIJKSTRA (int startnode)
{
    priority_queue<pi, vector<pi> , greater<pi>> pq;
    for (int i = 1 ; i <= N ; i++) MINF[i] = oo ;
    MINF[startnode] = 0;
    pq.push(pi(startnode,0));
    while (!pq.empty())
    {
        u = pq.top().first ; // đỉnh u hiện tại đang thăm
        int dis_u = pq.top().second; // Dis_u là khoảng cách ngắn nhất từ 1 đến u lúc hiện tại
        pq.pop();
        if(MINF[u] != dis_u) continue;
        for (pi v : G[u])
        {
            if (MINF[v.first] > dis_u + v.second  ) 
            {
                MINF[v.first] = dis_u + v.second;
                pq.push(make_pair(v.first,MINF[v.first]));
                trace[v.first] = u;
            }
        }
    }
}

int main()
{
	giuncute;
	freopen("giun.inp","r",stdin);
	freopen("giun.out","w",stdout);
    cin >> k >> m >> n ;
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> u >> v >> t >> x;
        G[u].push_back(make_pair(v,make_pair(t,x)));
        G[v].push_back(make_pair(u,make_pair(t,x)));
    }
}