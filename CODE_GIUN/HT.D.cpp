#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
using namespace std;
cll maxn = 1e5+7;
ll n , t , m , u , v , f[maxn] , visited[maxn]={0}, pa[maxn];
vector<ll> g[maxn];
void dfs (int u , int pre)
{
    visited[u] = 1;
    int child = 0 ;
    pa[u] = pre;
    for (int v : g[u])
    {
        if (!visited[v])
        {
            child++;
            dfs(v,u);
            f[u] ^= f[v];
        }
    }
    if (child == 0) f[u] = 1;
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    if (f[1] == 0) cout << "NO" << endl;
    else 
    {
        cout << "YES" << endl;
        for (int i = 2 ; i <= n ; i++) cout << i <<  " " <<  pa[i] << endl;
    }
}
