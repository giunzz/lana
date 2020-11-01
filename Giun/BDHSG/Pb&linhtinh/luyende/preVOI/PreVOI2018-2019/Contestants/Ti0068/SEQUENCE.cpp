#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 20 ;
int m , n , k ;
int a[maxn] , b[maxn] ;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen( "TABLE.INP" , "r" , stdin ) ;
    freopen( "TABLE.OUT" , "w" , stdout ) ;
    cin >> m >> n >> k ;
    for(int i = 1 ; i <= m ; i ++ )
    {
        cin >> a[i] ;
    }
    for(int i = 1 ; i <= n ; i ++ )
    {
        cin >> b[i] ;
    }
    for(int i = 1 ; i <= k - n ; i++ )
    {
        cout << a[i] << " "  ;
    }
    for(int i = 1 ; i <= n ; i ++  )
    {
        cout << b[i] << " " ;
    }
}
