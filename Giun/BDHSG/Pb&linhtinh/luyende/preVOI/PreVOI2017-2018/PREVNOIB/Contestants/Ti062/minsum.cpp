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
#define maxn 100005
#define maxm 10000
#define fi first
#define se second
#define mem0(ZED)  memset(ZED,0,sizeof(ZED))
#define memt(ZED)  memset(ZED,true,sizeof(ZED))
#define memf(ZED)  memset(ZED,false,sizeof(ZED))
#define mp make_pair
#define PB push_back
#define ZED "minsum"
using namespace std ;

const long base = 97 ;
long n , m ;
long te ;
long pt[maxn] ;
long nt[maxn] ;
long long a , b ;
long long getbit ( long long x , long i )
{
    return ( x >> i ) & 1 ;
}
void phantich( long long a )
{
    long top = 0 ;
    long i = 2 ;
    bool ok = true ;
    while ( a > 1  )
    {
        if ( a % i == 0 )
        {
            long dem = 0 ;
            while ( a % i == 0 )
            {
                a = a / i ;
                dem ++ ;
            }

            if ( dem % 2 == 1 )
                pt[++top] = i ;
            else
            {
                if ( ok == true )
                {
                    pt[++top] = 1 ;
                    ok = false ;
                }
            }
        }
        else
            {
                i ++ ;
            }
    }
    for ( long i = 1 ; i <= top ; i ++ )
    {
        nt[++n] = pt[i] ;
    }
}
long long X , Y ;
void tinhmin ()
{
    long long ans = vc ;
    for ( long x = 0 ; x < ( 1 << n ) ; x ++ )
    {
        long long SA = 1 , SB = 1 ;
        for ( long i = 0 ; i < n ; i ++ )
        {
            if ( getbit(x,i) == 1 )
            {
                SA *= nt[i+1] ;
            }
            if ( getbit(x,i) == 0 )
            {
                SB *= nt[i+1] ;
            }
        }
        if ( ans > SA + SB )
        {
            ans = SA + SB ;
            X = SA ;
            Y = SB ;
        }
    }
    cout << X << " " << Y ;
}
void xl( long long a , long long b )
{
    long long UCLN = __gcd(a, b ) ;
    a = a/UCLN ;
    b = b/UCLN ;
    n = 0 ;
    phantich(a) ;
    phantich(b) ;
    tinhmin() ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( ZED".inp" , "r" , stdin ) ;
    freopen( ZED".out" , "w" , stdout ) ;
    cin >> te ;
    while ( te -- )
    {
        cin >> a >> b ;
        xl( a , b ) ;
        cout << endl ;
    }

    return 0;
}
