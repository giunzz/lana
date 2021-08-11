#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e6 + 7;
using namespace std;
ll n , m, q , x , y;
ll visited[maxn] , ans = 0 , LT[maxn] = {0};
vector<ll> g[maxn];

void DFS (ll u , ll tmp)
{
    LT[u] = tmp;
    visited[u]  = 1;
    for (int v : g[u]) 
        if (!visited[v]) DFS(v , tmp);
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> q;
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int tmp = 0;
    for (int i = 1 ; i <= n ; i++)
        if (!visited[i]) tmp++ , DFS(i , tmp) ;
    //cerr << tmp << endl;
    while (q--)
    {
        cin >> x >> y ;
        //cerr << LT[x] << " " << LT[y] << endl;
        if (LT[x] == LT[y]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}