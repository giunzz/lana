#include<bits/stdc++.h>
using namespace std;

int a[300] ;
int n , mmax , m50s , m1s , m2s , m50 , m1 , m2 , ans = 0 ;


void duyet( int x )
{
    if( x > n )
    {
        int check = 1 ;
        m1 = m1s ;
        m50 = m50s ;
        m2 = m2s ;
        for(int i = 1 ; i <= n ; i ++ )
        {

            if( a[i] == 1 )
            {
                m1 ++ ;
                m50 -- ;
                if( m1 > mmax || m50 < 0 )
                {
                    check = 0 ;
                    break ;
                }
            }
            if( a[i] == 2 )
            {
                if( m50 < 1 )
                {
                     check = 0 ; break  ;
                }
                if( m50 < 3 && m1 < 1 )
                {
                    check = 0 ; break ;
                }
                if( m1 < 1 ) m50 -= 3 ;
                else
                {
                    m1 -- ;
                    m50 -- ;
                }
            }
            if( a[i] == 3 )
            {
                m50 ++ ;
                if( m50 > mmax )
                {
                    check = 0 ; break ;
                }
            }
        }
        ans = ans + check ;
    }
    else
    {
         for(int i = 1 ; i <= 3 ; i ++ )
         {
             a[x] = i ;
             duyet( x + 1 ) ;
             a[x] = 0 ;
         }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen( "ICECREAM.INP" , "r" , stdin ) ;
    freopen( "ICECREAM.INP" , "w" , stdout ) ;

    cin >> n >> mmax ;
    cin >> m50s >> m1s >> m2s ;
    duyet(1) ;
    cout << ans ;
}
