#include <iostream>
using namespace std ;
int a[ 1000000 ] ;
int main ()
{
    int n, b = 0 , k ; 
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
    { cin >> a[i] ;
    if ( a[i] > b )
    { b = a[i];
    k = i ;
    }
    }
    cout << k << " " << b ;
    return 0 ;
}