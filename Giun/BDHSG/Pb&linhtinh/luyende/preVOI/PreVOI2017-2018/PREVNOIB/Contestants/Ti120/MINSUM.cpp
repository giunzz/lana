#include<bits/stdc++.h>
using namespace std ;

int test ;

int f[100010] , prime[100010] , nPrime ;

vector < int > lis ;

vector < int > special ;

map < int , int > vis ;

void sang(){
    for( int i = 2 ; i <= 100000 ; ++ i ){
        if( !f[i] ){
            f[i] = i ; prime[++nPrime] = i ;
        }
        int j = 1 ;
        while( j <= nPrime && prime[j] <= f[i] && 1ll * i * prime[j] <= 100000ll ){
            f[ i * prime[j] ] = prime[j] ;
            j ++ ;
        }
    }
}

bool isprime( int value ){
    for( int i = 2 ; i * i <= value ; ++ i ){
        if( value % i == 0 ) return false ;
    }
    return true ;
}

int main(){
    #define NAME "MINSUM"
    freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    sang() ;

    scanf( "%d" , &test ) ;

    while(test --){
        int a , b ; scanf( "%d %d" , &a , &b ) ;
        if( a != 1 ){
            if( isprime(a) ){
                if( !vis[a] ) lis.push_back(a) ;
                vis[a] ++ ;
            }
            else{
                for( int i = 1 ; prime[i] * prime[i] <= a ; ++ i ){
                    int cnt = 0 ;
                    if( a % prime[i] ) continue ;
                    while( a % prime[i] == 0 ){
                        cnt ++ ; a /= prime[i] ;
                    }
                    if( !vis[ prime[i] ] ) lis.push_back( prime[i] ) ;
                    vis[ prime[i] ] += cnt ;
                }
                if( a != 1 ){
                    if( !vis[a] ) lis.push_back(a) ;
                    vis[a] ++ ;
                }
            }
        }
        if( b != 1 ){
            if( isprime(b) ){
                if( !vis[b] ) lis.push_back(b) ;
                vis[b] ++ ;
            }
            else{
                for( int i = 1 ; prime[i] * prime[i] <= b ; ++ i ){
                    int cnt = 0 ;
                    if( b % prime[i] ) continue ;
                    while( b % prime[i] == 0 ){
                        b /= prime[i] ;
                        cnt ++ ;
                    }
                    if( !vis[ prime[i] ] ) lis.push_back( prime[i] ) ;
                    vis[ prime[i] ] += cnt ;
                }
                if( b != 1 ){
                    if( !vis[b] ) lis.push_back(b) ;
                    vis[b] ++ ;
                }
            }
        }
        long long sum = 1ll ;
        long long ans = (long long)(4e18) ;
        pair < long long , long long > choose ;
        for( int i = 0 , _b = lis.size() ; i < _b ; ++ i ){
            int u = lis[i] ; int foo = vis[u] ;
            if( foo % 2 ) special.push_back(u) , sum *= 1ll * u ;
        }
        vis.clear() ; lis.clear() ;
        int num = special.size() ;
        if( !num ) { printf( "1 1\n" ) ; continue ; }
        for( int mask = 0 , _b = (( 1 << (num) ) - 1) / 2 ; mask <= _b ; ++ mask ){
            long long foo = 1ll ;
            for( int i = 0 ; i < num ; ++ i ){
                if( (mask & (1 << i)) ) foo *= 1ll * special[i] ;
            }
            if( ans > foo + sum / foo ){
                ans = foo + sum / foo ;
                choose = make_pair( foo , sum / foo ) ;
            }
        }
        printf( "%lld %lld\n" , choose.first , choose.second ) ;
        special.clear() ;
    }

    return 0 ;
}
