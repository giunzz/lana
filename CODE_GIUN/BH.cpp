// ma tuiii bai ten jjjj?????heyyyy :) :) :) 
#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
const ll maxn = 1e6;
using namespace std;
ll a[maxn+7],n , f[maxn+7]={0};
vector<ll> g[maxn+7];
void dfs (ll u)
{
    for (int v : g[u])  dfs(v);
    for (int v : g[u]) f[u] += f[v]+1;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    cerr << n << " ";
    for (int i = 2 ; i <= n ; i++) cin >> a[i], g[a[i]].push_back(i);
    dfs(1);
    cerr << 1 << " ";
    for (int i = 1 ; i <= n ; i++) cout << f[i] << " ";
}