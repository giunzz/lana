#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M,u , v , w , visited[MAXN] ={0} , cost[MAXN][MAXN] ={0} , ans = 0 , cntTPLT[MAXN] ={0} , TPLT;
vector<ll> G[MAXN];
vector<pair<ll,ll>> C[MAXN];
void dfs(ll node , ll color)
{
    visited[node] = 1 ;
    cntTPLT[node] = color;
    for (int v : G[node])
        if (!visited[v]) dfs(v);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> N >> M ;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> u >> v ; 
        G[u].push_back(v) ;
        G[v].push_back(u);
    }
    for (int i = 1 ; i <= N ; i++)
        for (int j = 1 ; j <= N ; j++) cin >> cost[i][j] ;
    for (int i = 1 ;i <= N ; i++)
        if (!visited[i]) TPLT++ , dfs(i);
    for (int i = 1 ; i <=)
    for (int i = 0 ; i < TPLT.size() ; i++)
    {
        
        for (int j = 1 ; j <= N ; i++)
            if (cost[TPLT[i]][j] > cost[j][TPLT[i]] && cost[TPLT[i]][j] > 0 ) 
                    ans += cost[TPLT[i]][j] , C.push_back(TPLT[i]).first , C.push_back(j).second;
            else  if (cost[TPLT[i]][j] < cost[j][TPLT[i]] && cost[j][TPLT[i]] > 0 ) 
                    ans += cost[TPLT[i]][j] , C.push_back(TPLT[i]).first , C.push_back(j).second;
    }
}

