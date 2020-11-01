#include <bits/stdc++.h>
#define f first
#define s second
#define FOR(i,m,n) for( int i = m ; i <= n ; ++ i )
#define FORN(i,m,n) for( int i = m ; i >= n ; -- i )
#define mem(m,n) memset( m , n , sizeof(m) )
#define il pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define maxn 3005
using namespace std;

int n,m,k,a[maxn],b[maxn],na[maxn],nb[maxn];
int dpa[maxn][maxn],dpb[maxn][maxn];
int res[maxn],cur[maxn];

main()
{
    ios_base::sync_with_stdio(0);
    freopen( "SEQUENCE.inp" , "r" , stdin );
    freopen( "SEQUENCE.out" , "w" , stdout );
    cin >> n >> m >> k;
    int x,maxx = 0;
    FOR( i, 1, n )
    {
        cin >> a[i];
    }
    FOR( i, 1, m )
    {
        cin >> b[i];
    }
    int u;
    dpa[0][1] = dpb[0][1] = MOD;
    FOR( j, 1, n )
    {
        dpa[j][++na[j]] = a[1];
        FOR( i, 2 , n )
        {
            if( n - i + 1 == j - na[j] ) dpa[j][++na[j]] = a[i];
            else
            FORN( l , na[j] , 1 )
            {
                 if( dpa[j][l] <= a[i] || n - i < j - l )
                 {
                     na[j] = l;
                     if( na[j] < j ) dpa[j][++na[j]] = a[i];
                     break;
                 }
            }
        }
        dpa[j][j+1] = MOD;
    }
    FOR( j, 1, m )
    {
        dpb[j][++nb[j]] = b[1];
        FOR( i, 2 , m )
        {
            if( m - i + 1 == j - nb[j] ) dpb[j][++nb[j]] = b[i];
            else
            FORN( l , nb[j] , 1 )
            {
                 if( dpb[j][l] <= b[i] || m - i < j - l )
                 {
                     nb[j] = l;
                     if( nb[j] < j ) dpb[j][++nb[j]] = b[i];
                     break;
                 }
            }
        }
        dpb[j][j+1] = MOD;
    }
    int la,lb,nn;
    mem( res , 40 );
    FOR( p , 0 , k )
    {
        if( p <= n && k - p <= m )
        {
        nn = 0;
        la = 1,lb = 1;
        while( la <= na[p] || lb <= nb[k-p] )
        {
             if( dpa[p][la] > dpb[k-p][lb] ) cur[++nn] = dpb[k-p][lb++];
             else cur[++nn] = dpa[p][la++];
        }
        FOR( i , 1 , k )
        {
             if( cur[i] > res[i] ) break;
             if( cur[i] < res[i] )
             {
                 FOR( j , 1 , k ) res[j] = cur[j];
                 break;
             }
        }
        }
    }
    FOR( i , 1 , k ) cout << res[i] << ' ';

}
