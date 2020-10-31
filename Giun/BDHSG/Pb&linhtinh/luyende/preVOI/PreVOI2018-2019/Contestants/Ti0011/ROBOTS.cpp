#include<bits/stdc++.h>

using namespace std ;

#define FOR( i , a , b ) for( int i = a , _b = b ; i <= _b ; i ++ )
#define FORD( i , a , b ) for( int i = a , _b = b ; i >= _b ; i -- )

#define fi first
#define se second

typedef long long ll ;

const int MAXN = 100010 ;

const int MAXL = 100010 ;

const int INF = 1000000000 ;

const int MOD = 1000000007 ;

typedef pair < int , int > ii ;
typedef pair < ii , int > iii ;

// &*********************** RHYMASTER**************************

int u , n ;

int res[4010][4010] ;

int dr[4] = { -1 ,  0 ,  0 ,  1 } ;
int dc[4] = {  0 , -1 ,  1 ,  0 } ;

int Maxx = 4000 , Minx = 0 , Maxy = 4000 , Miny = 0 ;

void lam( int x , int y , int val )
{
    if( x > Maxx || x < Minx || y > Maxy || y < Miny ) return ;

    if( res[x][y] <= val ) return ;

    res[x][y] = val ;

    FOR( i , 0 , 3 )
    {
        int u = x + dr[i] , v = y + dc[i] ;

        lam( u , v , val + 1 ) ;
    }
}


int dis( ii a , ii b )
{
    return abs( a.fi - b.fi ) + abs( a.se - b.se ) ;
}

bool check( ii a , ii b  )
{
    if( dis( a , b ) > n ) return false ;
    return true ;
}

ii a[10010] ;

main()
{
    #define FILE "ROBOTS"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    cin >> u >> n ;

    FOR( i , 1 , u )
    {
        cin >> a[i].fi >> a[i].se ;

        a[i].fi += 2000 ;
        a[i].se += 2000 ;
    }

    sort( a + 1 , a + u + 1 ) ;

    ii x ;

    cin >> x.fi >> x.se ;

    x.fi += 2000 ;
    x.se += 2000 ;

    Minx = max( x.fi - n , Minx ) ;
    Miny = max( x.se - n , Miny ) ;
    Maxx = min( x.fi + n , Maxx ) ;
    Maxy = min( x.se + n , Maxy ) ;

    FOR( i , Minx , Maxx ) FOR( j , Miny , Maxy ) res[i][j] = INF ;

    FOR( i , 1 , u ) lam( a[i].fi , a[i].se , 0 ) ;

    int ans = -1 ;

    FOR( i , Minx , Maxx ) FOR( j , Miny , Maxy ) if( check( ii( i , j ) , x ) ) ans = max( ans , res[i][j] ) ;

    cout << ans ;

    return 0 ;
}


