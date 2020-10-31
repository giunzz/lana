#include<bits/stdc++.h>
using namespace std ;

int n , k , ans = 0;
int l[4001] , r[4001] ;
int a[22] , kq[22];

void duyet( int x )
{
    if( x > n )
    {
        bool ok = true;
        int bfl , cnt = 0 ;
        int ct[22] ;
        for(int i = 1 ; i <= n ; i ++ )
        {
            if( a[i] == 1 )
            {
                bfl = l[i] ;
                break ;
            }
        }
        for(int i = 1 ; i <= n ; i ++ )
        {
            if( a[i] == 1 )
            {
                ct[++cnt] = l[i] ;
                if( abs( l[i] - bfl ) > k  )
                {
                     ok = false ; break ;
                }
                bfl = l[i] ;

            }
        }
        int j = 1 ;
        for(int i = 1 ; i <= n ; i ++ )
        {
            if( r[i] == ct[j] ) j ++ ;
        }
        if( j <= cnt ) ok = false ;
        if( ok && ans < cnt )
        {
            ans = cnt ;
            cnt = 0 ;
            for( int i = 1 ; i <= n ; i ++ )
            {
                if( a[i] == 1 )
                {
                    kq[++cnt] = l[i] ;
                }
            }
        }
    }
    else
    {
        for(int i = 0 ; i <= 1 ; i ++ )
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
    freopen( "LIONDANCE.INP" , "r" , stdin ) ;
    freopen( "LICONDANCE.OUT" , "w" , stdout ) ;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++ )
    {
        cin >> l[i] ;
    }
    for(int i = 1 ; i <= n ; i ++ )
    {
        cin >> r[i] ;
    }
    duyet(1) ;
    cout << ans << endl ;
    for(int i = 1 ; i <= ans ; i ++ )
    {
        cout << kq[i] << " " ;
    }

}
