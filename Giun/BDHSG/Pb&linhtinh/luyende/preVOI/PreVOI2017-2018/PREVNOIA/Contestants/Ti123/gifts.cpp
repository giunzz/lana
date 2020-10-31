#include <bits/stdc++.h>
#define mh 1000004
using namespace std;
int n, k, a[mh], s[mh];
int main ()
{
    freopen("gifts.inp","r",stdin); freopen ("gifts.out","w",stdout);
    scanf ( "%d%d", &n, &k );
    for ( int i=1; i<=n; i++)
        scanf ( "%d", &a[i] );
    for ( int i=1; i<=n; i++)
        s[i] = s[i-1] + a[i] ;
    int ds = 0;
    for ( int i=1; i<=n; i++)
        ds = max ( ds, s[i+k]-s[i] );
    int ds1 = 0;
    for ( int i=1; i<=n; i++ )
        if ( s[i+k]-s[i] < ds)
            ds1 = max(ds1,s[i+k]-s[i]);
    printf ( "%d", ds1 );
}
