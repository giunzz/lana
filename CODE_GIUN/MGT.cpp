#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M,u , v , w , visited[MAXN] ={0} , cost[MAXN][MAXN] ={0} , ans = 0 , p[MAXN] , size[MAXN];
vector<ll> G[MAXN] ;
vector<pair<ll,pair<ll,ll>>> G1;
void dfs(ll node , ll color)
{
    visited[node] = color ;
    for (int v : G[node])
        if (!visited[v]) dfs(v,color);
}
ll GET (ll u )
{
    if(p[u] == u) return u;
    return p[u] = GET(p[u]);
}
bool ghep(pair<ll,pair<ll,ll>> a)
{
    ll x = GET(visited[a.second.first]), y = GET(visited[a.second.second]);
    if(x == y) return 0;
    if( size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    p[y] = x;
    return 1;
}

bool cmp(pair<ll,pair<ll,ll>> &a, pair<ll,pair<ll,ll>> &b){
    return a.first < b.first;
}

vector<pair<ll,ll>> res;
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
    for (int i = 1 ; i <= N ; i++) p[i] = i , size[i] = 1;
    for (int i = 1 ; i <= N ; i++)
        for (int j = 1 ; j <= N ; j++) cin >> cost[i][j] ;
    ll cnt = 0;
    for (int i = 1 ;i <= N ; i++) if(!visited[i]) dfs(i, ++cnt);
    for (int i = 1 ; i <= N ; i--)
    {
        for (int j = 1 ; j <= N ; j++)
            if (visited[i] != visited[j]) G1.push_back(make_pair(cost[i][j] , make_pair(i,j)));
    }
    sort(G1.begin(), G1.end(), cmp);
    // cerr << cnt;
    // cnt = 0;
    for (int i = 0 ; i < G1.size() ; i++ )
    {
        if(ghep(G1[i]))
        {
            // ++cnt;
            ans += G1[i].first;
            res.push_back(make_pair(G1[i].second.first,G1[i].second.second));
        }
    }
    cout << ans << endl;
    if (ans >= 0 )
        for (int i = 0 ; i < res.size() ; i++) cout << res[i].first << " " << res[i].second << endl;
}