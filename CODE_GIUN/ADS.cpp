//https://codeforces.com/group/FLVn1Sc504/contest/274425/problem/A
#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const ll maxn = 5e5 + 7;;
ll m , n , u, v , dd[maxn]={0};
vector<ll> g[maxn];
void dfs (ll u)
{
    dd[u] = 1;
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
        g[u].push_back(v) , g[v].push_back(u);
    }
    ll a = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (!dd[i]) a++ , dfs(i);
    }
    cout << m-n+a;
}