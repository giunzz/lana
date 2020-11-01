#include<bits/stdc++.h>
using namespace std ;

const double esp = 1e-5 ;

#define x first.first
#define y first.second
#define z second

typedef pair < pair < double , double > , double > point ;

int nBall , nStore , nDel ;

struct TBall{
    point pos ; double r ;
    TBall(){}
    TBall( point foo , double bar ) { pos = foo ; r = bar ; }
} Ball[2010] ;

struct TStore{
    point pos ; int cost ;
    TStore(){}
    TStore( point foo , int bar ){ pos = foo ; cost = bar ; }
} Store[20] ;

point PVH ;

bool ok[20][2010] ;

double dis( point foo , point bar ){
    return sqrt( (foo.x - bar.x) * (foo.x - bar.x) + (foo.y - bar.y) * (foo.y - bar.y) + (foo.z - bar.z) * (foo.z - bar.z) ) ;
}

bool check( point foo , point bar , TBall magic ){
    if( foo.x == bar.x && foo.y == bar.y && foo.z == bar.z ) return false ;
    if( dis( foo , magic.pos ) <= magic.r && dis( bar , magic.pos ) <= magic.r ) return false ;
    if( foo.x != bar.x ){
        if( foo.x > bar.x ) swap(foo , bar) ;
        double l = 1.0D * foo.x , r = 1.0D * bar.x ;
        while( r - l >= esp ){
            double l1 = (l + l + r) / 3 , r1 = (l + r + r) / 3 ;
            if( l1 - l < esp || r1 - l1 < esp || r - r1 < esp ) break ;
            double A = (l1 - foo.x) / (bar.x - foo.x) ;
            double B = dis( magic.pos , make_pair( make_pair( l1 , (bar.y - foo.y) * A + foo.y ) , (bar.z - foo.z) * A + foo.z ) ) ;
            double C = (r1 - foo.x) / (bar.x - foo.x) ;
            double D = dis( magic.pos , make_pair( make_pair( r1 , (bar.y - foo.y) * C + foo.y ) , (bar.z - foo.z) * C + foo.z ) ) ;
            if( B < D ) r = r1 ;
            else l = l1 ;
        }
        double A = (l + r) / 2 ;
        double B = (A - foo.x) / (bar.x - foo.x) ;
        double C = dis( magic.pos , make_pair( make_pair( A , (bar.y - foo.y) * B + foo.y ) , (bar.z - foo.z) * B + foo.z ) ) ;
        return ( C - magic.r < 0.00002 ) ;
    }
    if( foo.y != bar.y ){
        if( foo.y > bar.y ) swap(foo , bar) ;
        double l = 1.0D * foo.y , r = 1.0D * bar.y ;
        while( r - l >= esp ){
            double l1 = (l + l + r) / 3 , r1 = (l + r + r) / 3 ;
            if( l1 - l < esp || r1 - l1 < esp || r - r1 < esp ) break ;
            double A = (l1 - foo.y) / (bar.y - foo.y) ;
            double B = dis( magic.pos , make_pair( make_pair( (bar.x - foo.x) * A + foo.x , l1 ) , (bar.z - foo.z) * A + foo.z ) ) ;
            double C = (r1 - foo.y) / (bar.y - foo.y) ;
            double D = dis( magic.pos , make_pair( make_pair( (bar.x - foo.x) * C + foo.x , r1 ) , (bar.z - foo.z) * C + foo.z ) ) ;
            if( B < D ) r = r1 ;
            else l = l1 ;
        }
        double A = (l + r) / 2 ;
        double B = (A - foo.y) / (bar.y - foo.y) ;
        double C = dis( magic.pos , make_pair( make_pair( (bar.x - foo.x) * B + foo.x , A ) , (bar.z - foo.z) * B + foo.z ) ) ;
        return ( C - magic.r < 0.00002 ) ;
    }
    if( foo.z != bar.z ){
        if( foo.z > bar.z ) swap(foo , bar) ;
        double l = 1.0D * foo.z , r = 1.0D * bar.z ;
        while( r - l >= esp ){
            double l1 = (l + l + r) / 3 , r1 = (l + r + r) / 3 ;
            if( l1 - l < esp || r1 - l1 < esp || r - r1 < esp ) break ;
            double A = (l1 - foo.z) / (bar.z - foo.z) ;
            double B = dis( magic.pos , make_pair( make_pair( (bar.x - foo.x) * A + foo.x , (bar.y - foo.y) * A + foo.y ) , l1 ) ) ;
            double C = (r1 - foo.z) / (bar.z - foo.z) ;
            double D = dis( magic.pos , make_pair( make_pair( (bar.x - foo.x) * C + foo.x , (bar.y - foo.y) * C + foo.y ) , r1 ) ) ;
            if( B < D ) r = r1 ;
            else l = l1 ;
        }
        double A = (l + r) / 2 ;
        double B = (A - foo.z) / (bar.z - foo.z) ;
        double C = dis( magic.pos , make_pair( make_pair( (bar.x - foo.x) * B + foo.x , (bar.y - foo.y) * B + foo.y ) , A ) ) ;
        return ( C - magic.r < 0.00002 ) ;
    }
}

int total_cost[40010] , firstBit[40010] ;

int have[33010][2010] ;

int main(){
    #define NAME "TEAWORLD"
    freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    scanf( "%d %d %d" , &nBall , &nStore , &nDel ) ;

    for( int i = 1 ; i <= nBall ; ++ i ){
        double a , b , c , d ; scanf( "%lf %lf %lf %lf" , &a , &b , &c , &d ) ;
        Ball[i] = TBall( make_pair( make_pair( a , b ) , c ) , d ) ;
    }

    for( int i = 1 ; i <= nStore ; ++ i ){
        double a , b , c ; int d ; scanf( "%lf %lf %lf %d" , &a , &b , &c , &d ) ;
        Store[i] = TStore( make_pair( make_pair( a , b ) , c ) , d ) ;
    }

    scanf( "%lf %lf %lf" , &PVH.x , &PVH.y , &PVH.z ) ;

    for( int i = 1 ; i <= nStore ; ++ i ){
        for( int j = 1 ; j <= nBall ; ++ j ){
            ok[i][j] = true ;
            if( check( Store[i].pos , PVH , Ball[j] ) ) ok[i][j] = false ;
        }
    }

    for( int mask = 1 , _b = (1 << nStore) - 1 ; mask <= _b ; ++ mask ){
        for( int i = 0 ; i < nStore ; ++ i ){
            if( (mask & (1 << i)) ) {
                total_cost[mask] = total_cost[ mask ^ (1 << i) ] + Store[i + 1].cost ;
                firstBit[mask] = i ;
                break ;
            }
        }
    }

    int ans = 0 ;

    for( int mask = 1 , _b = (1 << nStore) ; mask <= _b ; ++ mask ){
        int sl = 0 ;
        for( int i = 1 ; i <= nBall ; ++ i ){
            if( !ok[ firstBit[mask] + 1 ][i] || have[ mask ^ ( 1 << firstBit[mask] ) ][i] ) have[mask][i] = 1 , sl ++  ;
            if( sl > nDel ) break ;
        }
        if( sl <= nDel ) ans = max( ans , total_cost[mask] ) ;
    }

    printf( "%d" , ans ) ;

    return 0 ;
}
