#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll,ll> 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll m,n,u,v,w , wmax = INT_MIN , wmin = INT_MAX;
ll visited[(int)1e5+7] , ans = 0;
vector<pl> g[(int) 1e5+7];

void dfs(ll mid , ll u)
{
    visited[u] = 1;
    for (pl v : g[u])
        if (!visited[v.first] &&  v.second >= mid) dfs(mid,v.first);
}
bool check (ll mid )
{
    for (int i = 1 ; i <= 100000 ; i++) visited[i] = 0;
    dfs(mid,1);
    if (visited[n] == 1) return true;
    else return false;
}
inline ll cnp ()
{
    ll l = wmin , r = wmax ;
    while (l <= r)
    {
        ll mid = (l+r)/2;
        if (check(mid) == true)
        {   
            ans = max(ans,mid);
            l = mid+1;
        }
        else r = mid -1;
    }
    return ans;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> u >> v >> w;
            wmax = max(wmax,w) , wmin = min(wmin,w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
    }
    cout << cnp() ;
}


