#include<bits/stdc++.h>
using namespace std ;

int n ;

long long a[100010] ;

long long sum ;

deque < pair < long long , int > > wait ;

long long b[100010] ;

int main(){
    #define NAME "ARRANGE"
    freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    scanf( "%d" , &n ) ;

    for( int i = 1 ; i <= n ; ++ i ) {
        scanf( "%lld" , &a[i] ) ;
        sum += a[i] ;
    }

    if( sum % n == 0 ){
        long long ans = 0ll ;
        for( int i = 1 ; i <= n ; ++ i ){
            if( a[i] == sum / n ) continue ;
            a[i] -= sum / n ;
            if( a[i] > 0 ){
                if( !wait.size() || wait.front().first > 0 ) { wait.push_back( make_pair( a[i] , i ) ) ; continue ; }
                while( !wait.empty() ){
                    if( a[i] + wait.front().first >= 0 ) a[i] += wait.front().first , ans += 1ll * abs(wait.front().first) * ( i - wait.front().second ) , wait.pop_front() ;
                    else { wait.front().first += a[i] ; ans += 1ll * abs(a[i]) * ( i - wait.front().second ) ; a[i] = 0 ; break ; }
                }
                if( a[i] ) wait.push_back( make_pair( a[i] , i ) ) ;
            }
            else{
                if( !wait.size() || wait.front().first < 0 ) { wait.push_back( make_pair( a[i] , i ) ) ; continue ; }
                while( !wait.empty() ){
                    if( a[i] + wait.front().first <= 0 ) a[i] += wait.front().first , ans += 1ll * abs(wait.front().first) * ( i - wait.front().second ) , wait.pop_front() ;
                    else { wait.front().first += a[i] ; ans += 1ll * abs(a[i]) * ( i - wait.front().second ) ; a[i] = 0 ; break ; }
                }
                if( a[i] ) wait.push_back( make_pair( a[i] , i ) ) ;
            }
        }
        printf( "%lld" , ans ) ;
        return 0 ;
    }

    long long foo = sum / n , bar = sum % n ;
    long long ans = 0ll ;

    for( int i = 1 ; i <= n ; ++ i ) b[i] = a[i] ;

    for( int i = 1 ; i <= n ; ++ i ){
        if( a[i] == foo || a[i] == foo + 1 ) continue ;
        if( a[i] < foo ) a[i] -= foo ;
        else a[i] -= foo + 1 ;
        if( a[i] > 0 ){
            if( !wait.size() || wait.front().first > 0 ) { wait.push_back( make_pair( a[i] , i ) ) ; continue ; }
            while( !wait.empty() ){
                if( a[i] + wait.front().first >= 0 ) a[i] += wait.front().first , ans += 1ll * abs(wait.front().first) * ( i - wait.front().second ) , wait.pop_front() ;
                else { wait.front().first += a[i] ; ans += 1ll * abs(a[i]) * ( i - wait.front().second ) ; a[i] = 0 ; break ; }
            }
            if( a[i] ) wait.push_back( make_pair( a[i] , i ) ) ;
        }
        else{
            if( !wait.size() || wait.front().first < 0 ) { wait.push_back( make_pair( a[i] , i ) ) ; continue ; }
            while( !wait.empty() ){
                if( a[i] + wait.front().first <= 0 ) a[i] += wait.front().first , ans += 1ll * abs(wait.front().first) * ( i - wait.front().second ) , wait.pop_front() ;
                else { wait.front().first += a[i] ; ans += 1ll * abs(a[i]) * ( i - wait.front().second ) ; a[i] = 0 ; break ; }
            }
            if( a[i] ) wait.push_back( make_pair( a[i] , i ) ) ;
        }
    }

    if( wait.empty() ) return printf( "%lld" , ans ) , 0 ;

    for( int i = 1 ; i <= n ; ++ i ){
        if( !wait.empty() && wait.front().second == i ){
            long long foo = abs( wait.front().first ) ;
            ans += ( foo / 2 ) * ( foo / 2 + 1 ) ;
            if( foo % 2 ) ans += foo / 2 + 1 ;
        }
    }

    printf( "%lld" , ans ) ;

    return 0 ;
}
