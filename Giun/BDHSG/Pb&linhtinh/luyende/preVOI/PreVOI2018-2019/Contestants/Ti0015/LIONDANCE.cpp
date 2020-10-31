#include <bits/stdc++.h>
#define f first
#define s second
#define FOR(i,m,n) for( int i = m ; i <= n ; ++ i )
#define FORN(i,m,n) for( int i = m ; i >= n ; -- i )
#define mem(m,n) memset( m , n , sizeof(m) )
#define il pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define maxn 2005
using namespace std;

int n,a[maxn],k,b[maxn],dp[maxn][maxn];
il trace[maxn][maxn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen( "LIONDANCE.inp", "r", stdin );
    freopen( "LIONDANCE.out" , "w" , stdout );
    cin >> n >> k;
    FOR( i, 1, n ) cin >> a[i];
    FOR( i, 1, n ) cin >> b[i];
    il res = mp( 0, 0 );
    FORN( i, n, 1 )
    FORN( j, n, 1 )
    {
        if( a[i] == b[j] )
        {
            dp[i][j] = 1;
            FOR( x, i + 1, n )
            FOR( y, j + 1, n )
            {
                if( a[x] == b[y] && abs( a[x] - a[i] ) <= k )
                {
                    if( dp[x][y] + 1 == dp[i][j] && a[x] > a[trace[i][j].f] )
                    {
                        trace[i][j] = mp( x, y );
                    }
                    if( dp[x][y] + 1 > dp[i][j] )
                    {
                        dp[i][j] = dp[x][y] + 1;
                        trace[i][j] = mp( x, y );
                    }
                }
            }
            if( dp[i][j] == dp[res.f][res.s] && a[i] > a[res.f] ) res = mp( i, j );
            if( dp[i][j] > dp[res.f][res.s] ) res = mp( i, j );
        }
    }
    cout << dp[res.f][res.s] << '\n';
    while( trace[res.f][res.s].f != 0 )
    {
        cout << a[res.f] << ' ';
        res = trace[res.f][res.s];
    }
    cout << a[res.f];

}
