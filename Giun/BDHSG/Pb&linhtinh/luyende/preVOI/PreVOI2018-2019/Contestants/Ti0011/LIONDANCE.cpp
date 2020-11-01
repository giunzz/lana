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

int a[4010] , b[4010] , res[4010] , g[4010];

int f[4005][4005] ;

vector < int > tam ;

void truyvet( int x , int y )
{
    if( x < 1 || y < 1 ) return ;

    if( a[x] == b[y] )
    {
        tam.push_back( a[x] ) ;
        truyvet( x - 1 , y - 1 ) ;
    }
    else
    {
        if( f[x - 1][y] > f[x][y - 1]) truyvet( x - 1 , y ) ;
        else truyvet( x , y - 1 ) ;
    }

}

main()
{
    #define FILE "LIONDANCE"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    int n , k ;

    cin >> n >> k ;

    FOR( i , 1 , n ) cin >> a[i] ;

    FOR( i , 1 , n ) cin >> b[i] ;

    memset( f , 0 , sizeof  f ) ;

    FOR( i , 1 , n ) FOR( j , 1 , n )
    if( a[i] == b[j] ) f[i][j] = f[i - 1][j - 1] + 1 ;
    else f[i][j] = max( f[i - 1][j] , f[i][j - 1] ) ;

    truyvet( n , n ) ;

    int cnt = tam.size() ;

    FOR( i , 1 , cnt ) res[i] = tam[cnt - i] ;

    g[1] = 1 ;

    FOR( i , 2 , cnt )
    {
        int Max = - 1 ;

        FOR( j , 1 , i - 1 ) if( abs( res[i] - res[j] ) <= k ) Max = max( Max , g[j] ) ;

        g[i] = Max + 1 ;

    }

    int Max = g[1] , pos = 1 ;

    FOR( i , 2 , cnt ) if( Max < g[i] ) Max = g[i] , pos = i ;

    tam.clear() ;

    tam.push_back( res[pos] ) ;

    FORD( i , pos - 1 , 1 ) if( Max == g[i] + 1 && abs( res[pos] - res[i] <= k ) )
    {
        Max -- ;
        pos = i ;
        tam.push_back( res[i] ) ;
    }

    cnt = tam.size() ;

    FOR( i , 1 , cnt ) res[i] = tam[cnt - i] ;

    cout << cnt << "\n" ;

    FOR( i , 1 , cnt ) cout << res[i] << ' ' ;

    return 0 ;
}



