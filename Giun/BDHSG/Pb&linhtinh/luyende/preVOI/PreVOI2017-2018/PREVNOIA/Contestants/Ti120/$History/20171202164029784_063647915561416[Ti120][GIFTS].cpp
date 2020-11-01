#include<bits/stdc++.h>
using namespace std ;

int n , k ;

int a[1000010] ;

long long sum[1000010] ;

long long Left[1000010] , Right[1000010] ;

int main(){
    #define NAME "GIFTS"
    freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    scanf( "%d %d" , &n , &k ) ;

    for( int i = 1 ; i <= n ; ++ i ) {
        scanf( "%d" , &a[i] ) ;
        sum[i] = sum[i - 1] + 1ll * a[i] ;
    }

    for( int i = k ; i <= n ; ++ i ){
        Left[i] = max( Left[i - 1] , sum[i] - sum[i - k] ) ;
    }

    for( int i = n ; i >= k ; -- i ){
        Right[i] = max( Right[i + 1] , sum[i] - sum[i - k] ) ;
    }

    long long ans = (long long)(1e18) ;

    for( int i = k ; i <= n ; ++ i ){
        ans = min( ans , max( Left[i - k] , Right[i + k] ) ) ;
    }

    printf( "%lld" , ans ) ;

    return 0 ;
}
