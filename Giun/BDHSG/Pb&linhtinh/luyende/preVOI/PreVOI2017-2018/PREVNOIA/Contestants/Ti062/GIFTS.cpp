// CODE - Trí Hiền Diamond
/*


                      ░░▒▒▒░░
                   ░░░      ░░░░
              ░░░░░     ▒░      ░░░░░
           ▒░░   ░    ░▒▒    ░ ░ ░   ░░░
         ▒░   ░ ░ ░  ░▒▒░   ░       ░   ░▒
       ▒░  ░ ░ ░ ░  ▒▒▒▒░  ░ ░ ░ ░ ░ ░    ░▒
      ▒     ░ ░    ▒▒▒▒▒  ░ ░ ░ ░ ░ ░   ░   ▒
    ░░   ░ ░ ░ ░  ▒▒▒▒▒▒     ░ ░ ░ ░ ░ ░ ░ ░ ░░
   ░░ ░ ░ ░ ░ ░  ░▒▒▒▒▒▒░░░         ░ ░   ░ ░ ░░
   ░ ░ ░ ░   ░   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░             ░
  ▒   ░ ░ ░ ░ ░ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░     ░ ░ ▒
  ░    ░ ░ ░ ░ ░▒▒▒▒▒▒░░ ░ ░░▒▒▒▒▒▒▒▒▒▒▒░░      ░
 ░    ░ ░ ░ ░░ ▒▒▒▒▒░  ░░░░░  ░▒▒▒▒▒▒▒▒▒▒▒▒░     ░
░░     ░ ░ ░ ░ ▒▒▒▒░ ░▒▒▒▒▒▒▒░ ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░  ░
▒░            ░▒▒▒▒ ░▒▒▒▒▒▒▒▒▒  ▒▒▒▒░ ░░░░░░▒▒▒░ ░
▒░ ▒▒▒░░░░░░░ ░▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒▒▒           ░ ░
░░  ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░ ░▒▒▒▒▒▒▒░ ░▒▒▒▒  ░ ░     ░  ░
 ░     ░▒▒▒▒▒▒▒▒▒▒▒▒░  ░░░░░  ░▒▒▒▒░ ░ ░ ░ ░ ░ ░ ░
  ░       ░▒▒▒▒▒▒▒▒▒▒▒▒░░ ░░▒▒▒▒▒▒▒   ░ ░       ░
  ▒  ░       ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ░ ░ ░ ░    ▒
   ░  ░ ░ ░      ░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ░ ░ ░ ░ ░  ░
   ░░  ░ ░ ░   ░       ░░░░▒▒▒▒▒▒░ ░ ░ ░   ░  ░
    ░░  ░   ░ ░ ░ ░ ░      ▒▒▒▒▒▒   ░ ░ ░ ░  ░
      ░      ░ ░     ░ ░  ░▒▒▒▒▒       ░ ░  ▒
       ▒░   ░ ░ ░ ░ ░ ░   ░▒▒▒▒   ░ ░ ░   ░░
         ▒░  ░   ░ ░ ░ ░  ░▒▒░   ░ ░ ░  ░▒
           ░░░  ░ ░ ░ ░   ▒▒░   ░    ░░░
              ░░░░       ░▒      ░░░░
                    ░░░ ░░  ░ ░

*/
#include <bits/stdc++.h>
#define vc 100000000000
#define MOD 1000000007
#define maxn 1000005
#define maxm 10000
#define fi first
#define se second
#define mem0(ZED)  memset(ZED,0,sizeof(ZED))
#define memt(ZED)  memset(ZED,true,sizeof(ZED))
#define memf(ZED)  memset(ZED,false,sizeof(ZED))
#define mp make_pair
#define PB push_back
#define ZED "GIFTS"
using namespace std ;

const long base = 97 ;
long n , k ;
long a[maxn] ;
long long sum[maxn] ;
void nhap()
{
    cin >> n >> k ;
    sum[0] = 0 ;
    for ( long i = 1 ; i <= n ; i  ++ )
        {
            cin >> a[i] ;
            sum[i] = sum[i-1] + a[i] ;
        }
}
typedef pair < long long , long > ii ;
ii check[maxn] ;
long long maxt[maxn] , maxp[maxn] ;
long long ans = vc ;
void xl()
{
    long top = 0 ;
    long long res ;
    for ( long i = k ; i <= n ; i ++ )
    {
        check[++top].fi = sum[i] - sum[i-k] ;
        check[top].se = i ;
    }
    for ( long i = 1 ; i <= top ; i ++ )
        maxt[i] = max (maxt[i-1] ,check[i].fi ) ;
    for ( long i = top ; i >= 1 ; i -- )
    {
        maxp[i] = max ( maxp[i+1] , check[i].fi ) ;
    }
    for ( long i = 1 ; i <= top ; i ++ )
    {
        res = check[i].first ;
        long l = maxt[i-2] ;
        long r = maxp[i+2] ;
        if ( l <= res && r <= res )
        ans = min ( ans , res ) ;
    }
    cout << ans ;
}
long long kq = vc ;
void sub2()
{
    bool ok = true ;
    for ( long i = k ; i <= n ; i ++ )
    {
        long long re = sum[i] - sum[i-k] ;
        ok = true ;
        for ( long j = i + k ; j <= n ; j ++ )
        {
            long long pos = sum[j] - sum[j-k] ;
            if ( pos > re )
            {
                ok = false ;
                break ;
            }
        }
        if ( ok == false ) continue ;
        ok = true ;
        for ( long j = i - k ; j >= 1 ; j -- )
        {
            long long pos = sum[j] - sum[j-k] ;
            if ( pos > re )
            {
                ok = false ;
                break ;
            }
        }
        if ( ok == true )
        {
            kq = min ( kq , re ) ;
        }
    }
    cout << kq ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( ZED".inp" , "r" , stdin ) ;
    freopen( ZED".out" , "w" , stdout ) ;
    nhap() ;
    xl() ;
    return 0;
}
