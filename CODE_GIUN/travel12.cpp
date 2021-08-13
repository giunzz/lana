#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e4 + 7;
using namespace std;

ll n , m , u , v;
vector<ll> g[maxn];
vector<bitset<10001>> bs(maxn);

int main()
{
    giuncute;
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        if (!bs[u].test(v))
        {
            g[u].push_back(v) , g[v].push_back(u);
            bs[u].set(v) , bs[v].set(u);
        }
    }
    for (int u = 1 ; u <= n ; u++)
    {
        bitset<10001> f;
        for (ll v : g[u])
        {
            bs[v][u] = 0;
            if ((f & bs[v]).any())
            {
                f &= bs[v];
                ll w = 1;
                while (!f[w]) w++;
                for (int vv : g[w])
                {
                    if (bs[u][vv] == 1 && v != vv) 
                    {
                        cout << u << " " << vv << " " << w << " "  << v ;
                        return 0;
                    }
                }
            } else f = f | bs[v];
            bs[v][u] = 1;
        }
    }
    cout << -1;
    return 0;
}