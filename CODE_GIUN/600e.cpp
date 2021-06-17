//Given a tree and weights of nodes. Weights are non-negative integers. Task is to find maximum size of a subtree of a given tree such that all nodes are even in weights.
// 600E (cF)
#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e6+7;
ll n , color[maxn] , u , v , sum = 0 , mx = 0 ;
vector<ll> G[maxn];
ll size[maxn] , p[maxn] , cnt[maxn] = {0} , Big_Child[maxn] = {0};
bool Big[maxn] = {0};
pair <ll,ll> ans[maxn];

void DFS (ll u)
{
    size[u] = 1 ;
    Big_Child[u] = -1;
    for (int v : G[u])
    {
        if (v != p[u])
        {
            p[v] = u , DFS(v) ;
            size[u] += size[v];
            if (Big_Child[u] == -1 || size[Big_Child[u]] < size[v]) Big_Child[u] = v;
        }
    }
}

void add (ll u , ll num , bool check)
{
    cnt[color[u]] += num ; 
    if (check)
    {
        if (cnt[color[u]] == mx) sum += color[u];
        else if (cnt[color[u]] > mx ) mx = cnt[color[u]] , sum = color[u];
    }
    for (int v : G[u])
        if (v != p[u] && !Big[v]) add(v , num , check );
}

void sol_DFS(ll u , bool keep)
{
    for (int v : G[u])
        if (v != p[u] && v != Big_Child[u]) sol_DFS(v , 0 );
    if (Big_Child[u] != -1)
    {
        sol_DFS(Big_Child[u] , 1);
        Big[Big_Child[u]] = 1 ;
        mx = ans[Big_Child[u]].second , sum = ans[Big_Child[u]].first;
    }
    else mx = 0 , sum = 0 ;
    add (u , 1 , 1);
    ans[u] = {sum , mx};
    if (Big_Child[u] != -1 ) Big[Big_Child[u]] = 0;
    if (!keep) add(u , -1 , 0);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> color[i];
    for (int i = 1 ; i < n ; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    p[1] = 1; 
    DFS(1);
    for (int i = 1 ; i <= n ; i++) cerr<< i << " " <<p[i] << " " << size[i] << " " << Big_Child[i] << endl;
    sol_DFS(1,1);
    for (int i = 1 ; i <= n ; i++) cout << ans[i].first << " ";
}