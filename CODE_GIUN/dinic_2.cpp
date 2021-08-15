#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std; 
typedef int ll;
const ll maxn = 1e3 + 7;
ll n, m, s, t, Flow = 0;
vector<ll> dsk[maxn];
ll level[maxn];
ll resi[maxn][maxn], aug[maxn][maxn];
void bfs()
{
    memset ( level, 0, sizeof ( level ) );
    queue<ll> qu;
    level[s] = 1;
    qu.push ( s );
    while ( !qu.empty() )
    {
        ll u = qu.front();
        qu.pop();
        for ( ll v : dsk[u] )
            if (level[v] == 0 && (resi[u][v]||aug[u][v]))
            {
                level[v] = level[u] + 1;
                qu.push ( v );
            }
    }
}
ll dfs ( ll u, ll s )
{
    if ( u == t )
        return s;
    ll res = 0;
    for ( ll v : dsk[u] )
        if ( level[v] == level[u] + 1 )
        {
            if ( resi[u][v] )
            {
                res = dfs ( v, min ( s, resi[u][v] ) );
                if ( res != 0 )
                {
                    resi[u][v] -= res;
                    aug[v][u] += res;
                    return res;
                }
            }
            else if ( aug[u][v] )
            {
                res = dfs ( v, min ( s, aug[u][v] ) );
                if ( res != 0 )
                {
                    aug[u][v] -= res;
                    resi[v][u] += res;
                    return res;
                }
            }
        }
    return res;
}
signed main()
{
    faster;
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin >> n >> m >> s >> t;
    //dsk.assign ( n + 1, vector<ll>() );
    for ( ll i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        if ( u == t )
            continue;
        resi[u][v] += c;
        dsk[u].push_back (v);
        dsk[v].push_back (u);
    }
    /*for (int i = s ; i <= t ; i++) {
        cout << i << ": ";
        for (auto v : dsk[i]) cout << v << " ";
        cout << '\n';
    }
    cout << '\n'; */

    while ( 1 )
    {
        bfs();
        if ( level[t] == 0 )
            break;
        while ( ll x = dfs ( s, 1e9 + 7 ) )
            Flow += x;
    }   
    cout << n << " " << Flow << " ";
    int counted =0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            if (aug[i][j] > 0) counted++;
        }
    }
    cout << counted << '\n';
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) 
            if (aug[i][j] > 0) cout << j << " " << i << " " <<  aug[i][j] << '\n';
    }
    return 0;
}