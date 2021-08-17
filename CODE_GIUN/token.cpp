#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll oo = 1e18 ;
const ll maxn = 2e5 + 7;
using namespace std;

ll n , x , size[maxn] = {0} , f[maxn] = {0};
vector<ll> g[maxn];

void dfs (ll u , ll father)
{
    size[u] = 1;
    for (int v : g[u])
    {
        if (v == father) continue;
        dfs(v , u);
        size[u] += size[v];
        if (u == 1 ) cerr << size[v] << " " << size[u] << " " << v << endl;
        f[u] += f[v];
    }
    //if (u == 1 ) cerr << f[u] << " " << size[u] << endl;
    f[u] += size[u];
    
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1  ; i < n ; i++) cin >> x , g[x].push_back(i + 1);
    dfs(1, -1);
    for (int i = 1 ; i <= n ; i++) cout << f[i] << " ";
}