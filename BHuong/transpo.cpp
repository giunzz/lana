#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<int, int> 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll m,n,wmax = INT_MIN , wmin = INT_MAX;
bool visited[(int)1e5+7] = {0}; ll ans = 0;
vector<pl> g[(int) 1e5+7];

inline void dfs(ll const &mid , ll u)
{
    // cerr << u << ' ';
    for (pl &v : g[u])
        if (!visited[v.first] &&  v.second >= mid){
            visited[v.first] = 1;
            dfs(mid,v.first);
        }
}
bool check (ll const &mid )
{
    for (int i = 1 ; i <= n ; i++) visited[i] = 0;
    // cerr << mid << ' ';
    visited[1] = 1;
    dfs(mid,1);
    // cerr << mid << ' ';
    if (visited[n] == 1) return true;
    else return false;
}
inline ll cnp ()
{
    ll l = wmin , r = wmax;
    while (l <= r)
    {
        ll mid = (l+r)/2;
        // cerr << l << ' ' << r << ' ' << mid << '\n';
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
    freopen("transpo.inp","r",stdin);
    freopen("transpo.out","w",stdout);
    cin >> n >> m ;
    // map<pl, ll> mp;
    for (int i = 1 ; i <= m ; i++)
    {
        ll u, v, w;
            cin >> u >> v >> w;
            wmax = max(wmax,w) , wmin = min(wmin,w);
            // if(mp[{u, v}] || u == v || u > n || v > n || u < 1 || v < 1) cerr << 1;
            // mp[{u, v}] = mp[{v, u}] = 1;
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
    }
    cout << cnp() ;
}