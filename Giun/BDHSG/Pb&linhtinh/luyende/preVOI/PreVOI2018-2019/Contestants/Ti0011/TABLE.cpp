#include<bits/stdc++.h>

using namespace std ;

#define FOR( i , a , b ) for( int i = a , _b = b ; i <= _b ; i ++ )
#define FORD( i , a , b ) for( int i = a , _b = b ; i >= _b ; i -- )

#define fi first
#define se second

typedef long long ll ;

const int MAXN = 100010 ;

const int MAXL = 100010 ;

const int INF = 2000000000 ;

const int MOD = 1000000007 ;

typedef pair < int , int > ii ;
typedef pair < ii , int > iii ;

// &*********************** RHYMASTER**************************

int n , m , k ;

int a[310][310] ;

int f[31][31][31][31] ;

int res[31][31] ;

int superans[31][31][31][31] ;

vector < ii > g[31][31][31][31] ;

int lam0( int x , int y , int u , int v )
{
    if( x < 1 || y < 1 || x > n || y > m || x > u || y > v ) return -1 ;

    if( f[x][y][u][v] != -INF ) return f[x][y][u][v] ;

    if( x == u && y == v )
    {
        f[x][y][u][v] = a[x][y] ;

        g[x][y][u][v].push_back( ii( x , y ) ) ;

        return a[x][y] ;
    }

    f[x][y][u - 1][v] = lam0( x , y , u - 1 , v ) ;
    f[x][y][u][v - 1] = lam0( x , y , u , v - 1 ) ;
    f[x][y + 1][u][v] = lam0( x , y + 1 , u , v ) ;
    f[x + 1][y][u][v] = lam0( x + 1 , y , u , v ) ;

    int x1 = x , y1 = y  , u1 = u - 1 , v1 = v ;
    ii tmp = ii( u , v ) ;

    if( f[x1][y1][u1][v1] + a[tmp.fi][tmp.se] < f[x][y][u][v - 1] + a[u][v] )
    {
        x1 = x , y1 = y , u1 = u , v1 = v - 1 , tmp = ii( u , v ) ;
    }
    if( f[x1][y1][u1][v1] + a[tmp.fi][tmp.se] < f[x][y + 1][u][v] + a[x][y] )
    {
        x1 = x , y1 = y + 1 , u1 = u , v1 = v , tmp = ii( x , y ) ;
    }
    if( f[x1][y1][u1][v1] + a[tmp.fi][tmp.se] < f[x + 1][y][u][v] + a[x][y] )
    {
        x1 = x + 1 , y1 = y , u1 = u , v1 = v , tmp = ii( x , y ) ;
    }

    f[x][y][u][v] = f[x1][y1][u1][v1] + a[tmp.fi][tmp.se] ;

    FOR( i , 0 , g[x1][y1][u1][v1].size() - 1 ) g[x][y][u][v].push_back( g[x1][y1][u1][v1][i] ) ;

    g[x][y][u][v].push_back( tmp ) ;

    return f[x][y][u][v] ;
}

int lamd( int x , int y , int u , int v )
{
    res[x][y] = a[x][y] ;

    FOR( i , x , u ) FOR( j , y , v ) if( i != x || j != y ) res[i][j] = max( res[i - 1][j] , res[i][j - 1] ) + a[i][j] ;

    return res[u][v] ;
}

void lam( int x , int y , int u , int v )
{
    FOR( i , x , u ) FOR( j , y , v ) res[i][j] = 0 ;

    int ans = INF ;

    FOR( i , 0 , g[x][y][u][v].size() - 1 )
    {
        int o1 = g[x][y][u][v][i].fi , o2 = g[x][y][u][v][i].se ;

        int tmp = a[o1][o2] ;

        a[o1][o2] = - INF ;

        int T = lamd( x , y , u , v ) ;

        if( T > - 1150000000 ) ans = min( ans , T ) ;

        a[o1][o2] = tmp ;
    }

    superans[x][y][u][v] = ans ;

    cout << ans << "\n" ;
}

main()
{
    #define FILE "TABLE"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    cin >> n >> m >> k ;

    FOR( i , 1 , n )  FOR( j , 1 , m ) cin >> a[i][j] ;

    FOR( i , 1 , n ) FOR( j , 1 , m ) FOR( I , 1 , n ) FOR( J , 1 , m ) f[i][j][I][J] = -INF , superans[i][j][I][J] = -INF ;

    f[1][1][n][m] = lam0( 1 , 1 , n , m ) ;

    while( k -- )
    {
        int x , y , u , v ;

        cin >> x >> y >> u >> v ;

        if( superans[x][y][u][v] != -INF )
        {
            cout << superans[x][y][u][v] << "\n" ;
            continue ;
        }

        lam( x , y , u , v ) ;
    }

    return 0 ;
}

