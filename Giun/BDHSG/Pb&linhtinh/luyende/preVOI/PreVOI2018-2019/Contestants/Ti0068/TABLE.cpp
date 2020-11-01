#include <bits/stdc++.h>

using namespace std;
typedef pair< int , int > pii ;

const int maxn = 303 ;
int n , a[maxn][maxn] , l[maxn][maxn] ,  m , k ;
pii u , v ;
pii trace[maxn][maxn] ;

struct query
{
    int u , v , p , q ;
}q[maxn];

template <typename T>
void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x ;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

bool check( int x , int y , int u , int v )
{
    return ( x <= u && y <= v ) ;
}
void init()
{
    read(m) ; read(n) ; read(k) ;
    for(int i = 1 ; i <= m ; i++ )
    {
        for(int j = 1 ; j <= n ; j ++ )
        {
            read(a[i][j]) ;
        }
    }
    for( int i = 1 ; i <= k ; i ++ )
    {
        read( q[i].u ) ; read( q[i].v ) ; read( q[i].p ) ; read( q[i].q ) ;
    }
}

void solve()
{
    for(int i = 1 ; i <= k ; i ++ )
    {
        memset( l , -1000000000 , sizeof(l) ) ;
        l[q[i].u][q[i].v] = a[q[i].u][q[i].v] ;
        trace[q[i].u][q[i].v].first = q[i].u ;
        trace[q[i].u][q[i].v].second = q[i].v ;
        for(int j = q[i].u + 1; j <= q[i].p ; j ++ ) { l[j][q[i].v] = l[j - 1][q[i].v] + a[j][q[i].v] ; trace[j][q[i].v].first = j - 1 ; trace[j][q[i].v].second = q[i].v ; }
        for(int j = q[i].v + 1 ; j <= q[i].q ; j ++ ) { l[q[i].u][j] =l[q[i].u][j - 1] + a[q[i].u][j] ; trace[q[i].u][j].first = q[i].u ; trace[q[i].u][j].second = j - 1 ; }


        for(int k = 2 ; k <= q[i].p ; k++ )
        {
            for( int j = 2 ; j <= q[i].q ; j ++ )
            {
                if( l[k][j] < l[k - 1][j] + a[k][j] )
                {
                    l[k][j] = l[k - 1][j] + a[k][j] ;
                    trace[k][j].first = k - 1;
                    trace[k][j].second = j;
                }
                if( l[k][j] < l[k][j - 1] + a[k][j] )
                {
                    l[k][j] = l[k][j - 1] + a[k][j] ;
                    trace[k][j].first = k ;
                    trace[k][j].second = j - 1 ;
                }
            }
        }
        int k = q[i].p , j = q[i].q ;
        bool ok = false ;
        int best = -1000001 , best1 , best2;
        while( k != q[i].u || j != q[i].v )
        {
            if( ok )
            {
                if( best < a[k][j] )
                {
                    best = a[k][j] ;
                    best1 = k ; best2 = j ;
                }
            }
            k = trace[k][j].first ;
            j = trace[k][j].second ;
            ok = true ;
        }
        a[best1][best2] = 0 ;
        memset( l , -1000000000 , sizeof(l) ) ;
        l[q[i].u][q[i].v] = a[q[i].u][q[i].v] ;
        trace[q[i].u][q[i].v].first = q[i].u ;
        trace[q[i].u][q[i].v].second = q[i].v ;
        for(int j = q[i].u + 1; j <= q[i].p ; j ++ ) { l[j][q[i].v] = l[j - 1][q[i].v] + a[j][q[i].v] ; trace[j][q[i].v].first = j - 1 ; trace[j][q[i].v].second = q[i].v ; }
        for(int j = q[i].v + 1 ; j <= q[i].q ; j ++ ) { l[q[i].u][j] =l[q[i].u][j - 1] + a[q[i].u][j] ; trace[q[i].u][j].first = q[i].u ; trace[q[i].u][j].second = j - 1 ; }


        for(int k = 2 ; k <= q[i].p ; k++ )
        {
            for( int j = 2 ; j <= q[i].q ; j ++ )
            {
                if( l[k][j] < l[k - 1][j] + a[k][j] )
                {
                    l[k][j] = l[k - 1][j] + a[k][j] ;
                    trace[k][j].first = k - 1;
                    trace[k][j].second = j;
                }
                if( l[k][j] < l[k][j - 1] + a[k][j] )
                {
                    l[k][j] = l[k][j - 1] + a[k][j] ;
                    trace[k][j].first = k ;
                    trace[k][j].second = j - 1 ;
                }
            }
        }
        a[best1][best2] = best ;
        cout << l[q[i].p][q[i].q] << endl ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen( "TABLE.INP" , "r" , stdin ) ;
    freopen( "TABLE.OUT" , "w" , stdout ) ;
    init() ;
    solve() ;
}
