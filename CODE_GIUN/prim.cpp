#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define pl pair <ll,ll>
const ll maxn = 1e6 + 7 ;
using namespace std;
ll n , m , u , v , w;
vector< pair <ll,ll>> G[maxn];
bool c[maxn] = {0};

ll prim ()
{
    ll ans = 0;
    priority_queue< pl, vector<pl> , greater<pl>> q;
    q.push({0,1});
    ll u , tmp ; 
    while (q.size())
    {
        u = q.top().second;
        tmp = q.top().first;
        q.pop();
        if (c[u]) continue;
        c[u] = 1;
        ans += tmp;
        for (pl v : G[u]) 
        {
            q.push(v);
        }
    }
    return ans;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ; 
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }
    cout << prim();
}
