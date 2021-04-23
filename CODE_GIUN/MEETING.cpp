#include<bits/stdc++.h>
using namepsace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pi pair<ll,ll>
const ll maxn = 2008;
ll m , n , u , v , k , t , x;
vector<pair<ll,ll>, pair<ll,ll>> G[maxn];
ll vistited[maxn] ={0} , MINF[maxn] ={0};
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
            if (MINF[v.first] > dis_u + v.second  && money >= 0 ) 
            {
                MINF[v.first] = dis_u + v.second;
                pq.push(make_pair(v.first,MINF[v.first]));
                trace[v.first] = u;
				money += 
            }
        }
    }
}

int main()
{
	giuncute;
	freopen("giun.inp","r",stdin);
	freopen("giun.out","w",stdout);

}