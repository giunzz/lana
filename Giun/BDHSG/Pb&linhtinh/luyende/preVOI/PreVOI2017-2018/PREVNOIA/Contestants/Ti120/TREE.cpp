#include<bits/stdc++.h>
using namespace std ;

int n ;

int a[5010] ;

int dp[5010][5010] ;

int Child[5010] , lis[5010][3] ;

vector < int > g[5010] ;

void dfs( int u , int da ){
    int type = 0 ;
    for( int i = 0 , _b = g[u].size() ; i < _b ; ++ i ){
        int v = g[u][i] ;
        if( v == da ) continue ;
        type ++ ;
    }
    if( !type ){
        Child[u] = 1 ;
        dp[u][0] = abs( a[u] ) ; dp[u][1] = abs( a[u] - 1 ) ;
        return ;
    }
    if( type == 1 ){
        for( int i = 0 , _b = g[u].size() ; i < _b ; ++ i ){
            int v = g[u][i] ;
            if( v == da ) continue ;
            dfs( v , u ) ;
            Child[u] += Child[v] ;
            for( int sum = 0 ; sum <= Child[u] ; ++ sum ){
                dp[u][sum] = dp[v][sum] + abs( sum - a[u] ) ;
            }
        }
    }
    else{
        int nLis = 0 ;
        for( int i = 0 , _b = g[u].size() ; i < _b ; ++ i ){
            int v = g[u][i] ;
            if( v == da ) continue ;
            dfs( v , u ) ;
            Child[u] += Child[v] ;
            lis[u][++nLis] = v ;
        }
        for( int sum = 0 ; sum <= Child[u] ; ++ sum ){
            for( int foo = max( sum - Child[ lis[u][2] ] , 0 ) ; foo <= Child[ lis[u][1] ] ; ++ foo ){
                dp[u][sum] = min( dp[u][sum] , dp[ lis[u][1] ][foo] + dp[ lis[u][2] ][ sum - foo ] + abs( sum - a[u] ) ) ;
            }
        }
    }
}

int main(){
    #define NAME "TREE"
    freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    scanf( "%d" , &n ) ;

    for( int i = 1 ; i <= n ; ++ i ) scanf( "%d" , &a[i] ) ;

    for( int i = 1 ; i < n ; ++ i ){
        int u , v ; scanf( "%d %d" , &u , &v ) ;
        g[u].push_back(v) ; g[v].push_back(u) ;
    }

    memset( dp , 0x3f , sizeof(dp) ) ;

    dfs(1 , 0) ;

    int ans = (int)(1e9) ;

    for( int sum = 0 ; sum <= Child[1] ; ++ sum ) ans = min( ans , dp[1][sum] ) ;

    printf( "%d" , ans ) ;

    return 0 ;
}
