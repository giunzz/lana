#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e3 + 7;
using namespace std;
ll t , cost[maxn][maxn] , d[maxn] , dd[maxn];
ll level[maxn];
vector <ll> g[maxn];
string a , b , c;

bool bfs (ll s , ll t)
{
    for (int i = 0 ; i <= 100 ; i++) level[i] = 0 ;
    level[s] = 1;
    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (u == t) return 1;
        for (ll v : g[u])
        {
            if (level[v] == 0 && cost[u][v] != 0)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return 0 ;
}
ll dfs (ll u , ll mi)
{
    ll val;
    if (u == 100) return mi;
    for (ll v : g[u])
    {
        if (level[v] == level[u] + 1)
        {
            val = dfs (v , min(mi , cost[u][v]));
            if (val != 0)
            {
                cost[u][v] -= val;
                cost[v][u] += val;
                return val;
            }
        }
    }
    return 0;
}


int main()
{
    giuncute;
    freopen("AC1.inp","r",stdin);
    freopen("AC1.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c ;
        ll j = 1 , n = a.size();
        for (int i = 'A' ; i <= 'Z' ; i++) dd[i] = 0;
        for (int i = 'A' ; i <= 'Z' ; i++) 
        {
            d[i] = n + j , j++;
           // cerr << (char) i << " " << d[i] << endl;
        }
        for (int i = 1 ; i <= 100 ; i ++)
            for (int j =  1; j <= 100 ; j++) cost[i][j] = 0;
        for (int i = 0 ; i <= n ; i++) g[i].clear();
        for (int i = 0 ; i < c.size() ; i++) dd[c[i]]++;
        for (int i = 1 ; i <= n ; i++) 
        {
            g[0].push_back(i) , g[i].push_back(0);
            cost[0][i] = 1;
        }
        j = 1;
        for (int i = 0 ; i < n ; i++)
        {
            g[j].push_back(d[a[i]]) , g[d[a[i]]].push_back(j);
            g[j].push_back(d[b[i]]) , g[d[b[i]]].push_back(j);
            cost[j][d[a[i]]] = 1;
            cost[j][d[b[i]]] = 1;
            j++;
        }
        for (int i = 0 ; i < c.size() ; i++)
        {
            g[100].push_back(d[c[i]]) , g[d[c[i]]].push_back(100);
            cost[d[c[i]]][100] = dd[c[i]];
        }
        // cerr << 0 << ": ";
        // for (int v : g[0]) cerr << v << " ";
        // cerr << endl;
        // for (int i = 1 ; i <= n ; i++)
        // {
        //     cerr << i << ": ";
        //     for (int v : g[i]) cerr << v << " ";
        //     cerr << endl;
        // }
        // cerr << 100 << ": ";
        // for (int v : g[100]) cerr << v << " ";
        ll ans = 0 ;
        while (bfs(0,100) == true) ans += dfs(0, 1e18);
        if (ans == c.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
}