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

const int MOD = 1000000009 ;

typedef pair < int , int > ii ;
typedef pair < ii , int > iii ;

// &*********************** RHYMASTER**************************

int n , Max ;

int a , b , c ;

int res = 0 ;

void lam( int x , int u , int v , int t )
{
    if( u > Max || v > Max || u < 0 || v < 0 ) return ;

    if( x > n ) return ;

    if( u < Max && x < n ) lam( x + 1 , u + 1 , v , t ) ;

    if( u > 0  && v < Max && x < n ) lam( x + 1 , u - 1 , v + 1 , t ) ;

    if( t < Max && x < n )
    {
        if( u > 0 && v > 0 ) lam( x + 1 , u - 1 , v - 1 , t + 1 ) ;
        else if( u > 2 ) lam( x + 1 , u - 3 , v , t + 1 ) ;
    }

    if( x == n ) res ++ ;

}
main()
{
    #define FILE "ICECREAM"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    cin >> n >> Max >> a >> b >> c ;

    lam( 0 , a , b , c ) ;

    cout << res ;

    return 0 ;
}



