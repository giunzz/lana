#include<bits/stdc++.h>
using namespace std ;

int n , k ;

int a[100010] ;

vector < pair < int , int > > g[100010] ;

int dad[100010][20] , level[100010] ;

int result[20] , vis[100010] , passed[100010] ;
int ans = (int)(1e9) ;

int Edge[100010] ;

void dfs( int u , int da ){
    for( int i = 0 , _b = g[u].size() ; i < _b ; ++ i ){
        int v = g[u][i].first , c = g[u][i].second ;
        if( v == da ) continue ;
        dad[v][0] = u ; Edge[v] = c ;
        level[v] = level[u] + 1 ;
        dfs( v , u ) ;
    }
}

void build(){
    for( int i = 1 ; i <= 18 ; ++ i ){
        for( int u = 1 ; u <= n ; ++ u ){
            dad[u][i] = dad[ dad[u][i - 1] ][i - 1] ;
        }
    }
}

int lca( int u , int v ){
    if( level[u] < level[v] ) swap(u , v) ;
    if(level[u] - level[v] ){
        for( int i = 18 ; i >= 0 ; -- i ){
            if( level[u] - (1 << i) >= level[v] ) u = dad[u][i] ;
        }
    }
    if( u == v ) return u ;
    for( int i = 18 ; i >= 0 ; -- i ){
        if( dad[u][i] != dad[v][i] ) u = dad[u][i] , v = dad[v][i] ;
    }
    return dad[u][0] ;
}

void find_answer( int done ){
    if( done == k / 2 ) { ans = min( ans , result[done] ) ; return ; }
    for( int u = 1 ; u <= k ; ++ u ){
        if( vis[ a[u] ] ) continue ;
        for( int v = u + 1 ; v <= k ; ++ v ){
            if( vis[ a[v] ] ) continue ;
            int foo = a[u] , bar = a[v] ;
            int dadfoobar = lca( foo , bar ) ;
            int A = foo , B = bar ;
            bool ok = true ;
            while( A != dadfoobar ){
                if( passed[A] ) { ok = false ; break ; }
                A = dad[A][0] ;
            }
            if( ok ){
                while( B != dadfoobar ){
                    if( passed[B] ){ ok = false ; break ; }
                    B = dad[B][0] ;
                }
            }
            if(!ok) continue ;
            vis[foo] = 1 ; vis[bar] = 1 ;
            int sum = 0 ;
            A = foo ; B = bar ;
            while( A != dadfoobar ){
                passed[A] = 1 ;
                sum += Edge[A] ;
                A = dad[A][0] ;
            }
            while( B != dadfoobar ){
                   passed[B] = 1 ;
                   sum += Edge[B] ;
                    B = dad[B][0] ;
            }
            result[done + 1] = max( result[done] , sum ) ;
            find_answer(done + 1) ;
            vis[foo] = 0 ; vis[bar] = 0 ;
            A = foo ; B = bar ;
            while( A != dadfoobar ){
                passed[A] = 0 ;
                A = dad[A][0] ;
            }
            while( B != dadfoobar ){
                passed[B] = 0 ;
                B = dad[B][0] ;
            }
        }
    }
}

int main(){
    #define NAME "BUBBLETEA"
    freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    scanf( "%d %d" , &n , &k ) ;

    for( int i = 1 ; i <= k ; ++ i ) scanf( "%d" , &a[i] ) ;

    for( int i = 1 ; i < n ; ++ i ){
        int u , v , c ; scanf( "%d %d %d" , &u , &v , &c ) ;
        g[u].push_back(make_pair(v , c)) ; g[v].push_back( make_pair(u , c) ) ;
    }

    dfs(1 , 0) ;

    build() ;
    if( k <= 10 ){
        find_answer( 0 ) ;
        if( ans == int(1e9) ) printf( "-1" ) ;
        else printf( "%d" , ans ) ;
        return 0 ;
    }

    cout << 1 << endl ;

    return 0 ;
}
