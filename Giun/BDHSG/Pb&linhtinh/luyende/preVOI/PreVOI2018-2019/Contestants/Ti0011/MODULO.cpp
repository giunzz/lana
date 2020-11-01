#include<bits/stdc++.h>

using namespace std ;

#define FOR( i , a , b ) for( ll i = a , _b = b ; i <= _b ; i ++ )
#define FORD( i , a , b ) for( ll i = a , _b = b ; i >= _b ; i -- )

#define fi first
#define se second

typedef unsigned long long ll ;

const ll MAXN = 100010 ;

const ll MAXL = 100010 ;

const ll INF = 1000000000 ;

const ll MOD = 1000000007 ;

typedef pair < ll , ll > ii ;
typedef pair < ii , ll > iii ;

// &*********************** RHYMASTER**************************

ll a , b ;

ll n , k ;

ll tmp ;

bool ktra = false ;

void lam( ll x , ll val )
{
    if( x == n )
    {
        if( val % tmp == k )
        {
            cout << val ;

            ktra = true ;

            return ;
        }
        else return ;
    }

    lam( x + 1 , val * 10 + a ) ;

    lam( x + 1 , val * 10 + b ) ;

}

main()
{
    #define FILE "MODULO"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    cin >> a >> b >> n >> k ;

    if( a % 2 == 0 && b % 2 == 0 && k % 2 == 1 )
    {
        cout << -1 ;

        return 0 ;
    }

    if( a % 2 == 1 && b % 2 == 1 && k % 2 == 0 )
    {
        cout << -1 ;

        return 0 ;
    }

    tmp = 1 ;

    FOR( i , 1 , n ) tmp *= 2 ;

    lam( 0 , 0 ) ;

    if( !ktra ) cout << -1 ;

    return 0 ;
}



