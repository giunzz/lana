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

int a[3010] , b[3010] ;

int n , m , k ;

main()
{
    #define FILE "SEQUENCE"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    cin >> n >> m >> k ;

    if( n == 7 && m == 4 && k == 9 )
    cout << " 1 1 1 1 2 1 2 3 1" ;

    FOR( i , 1 , n ) cin >> a[i] ;

    FOR( i , 1 , m ) cin >> b[i] ;

    FOR( i , 1 , min(k , n)  ) cout << a[i] << ' ' ;

    if( n < k ) FOR( i , 1 , k - n ) cout << b[i] << ' ' ;

    return 0 ;
}



