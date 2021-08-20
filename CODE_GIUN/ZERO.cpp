#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n , visited[maxn]  , t , m , w[maxn] = {0};
vector <ll> g[maxn];

int main()
{
    giuncute;
    freopen("ZERO.inp","r",stdin);
    freopen("ZERO.out","w",stdout);
    cin >> t ;
    while (t--)
    {   
        cin >> n ; 
        ll u , v;
        for (int i = 1 ; i <= n ; i++) g[i].clear();
        for (int i = 1 ; i < n ; i++)
        {
            cin >> u >> v ;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1 ; i <= n ; i++) cin >> w[i];
        ll ans = 0 ;
        for (int i = 1 ; i <= n ; i++)
        {
            if (w[i] > 0 && g[i].size() > 1) ans++;
        }
        cout << ans << endl;
    }
}