//https://codeforces.com/group/FLVn1Sc504/contest/274425/problem/A
#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const ll maxn = 5007;
ll m , n , u, v , dd[5007]={0}, a[maxn][maxn];
vector<ll> g[5007];
vector<pair<ll, ll>> e;
// gioi 
//giun cute siu gioi
void dfs (ll u)
{
    dd[u] = 1;
    /*
    for v tu 1 -> n
        if a[u][v] = 1 and !dd[v]
            dfs(v)
    */
    for (int v : g[u])
    {
        if (!dd[v]) dfs(v);
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
 //       a[u][v] = 1;
 //       a[v][u] = 1;
 //       e.push_back({u, v}), e.push_back({v, u});
        g[u].push_back(v) , g[v].push_back(u);
    }
    ll a = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (!dd[i]) a++ , dfs(i);
    }
    cout << m-n+a;
}