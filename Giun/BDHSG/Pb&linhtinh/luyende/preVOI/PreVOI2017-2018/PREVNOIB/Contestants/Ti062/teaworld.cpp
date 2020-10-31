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
#define ZED "teaworld"
using namespace std ;

const long base = 97 ;
long n , m , k ;
struct data
{
    long x , y , z , r , e ;

} a[maxn] , b[maxn] ;
data GS ;
long long ans = -vc ;
long sub1 , sub2 ;
typedef pair < long , long > ii ;

long getbit ( long x , long i  )
{
    return  ( x >> i ) & 1 ;
}
void nhap()
{
    cin >> m >> n >> k ;
    for ( long i = 1 ; i <= m ; i ++ )
    {
        cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r ;
    }
    for ( long i = 1 ; i <= n ; i ++ )
    {
        cin >> b[i].x >> b[i].y >> b[i].z >> b[i].e ;
    }
    cin >> GS.x >> GS.y >> GS.z ;
}
long S[maxn] , top = 0 ;

bool check()
{
    long dem = 0 ;
    for ( long i = 1 ; i <= top ; i ++ )
    {
        long res = S[i] ;
        for ( long j = 1 ; j <= m ; j ++ )
        {
            long mid = a[j].x ;
            long l = a[j].x - a[j].r ;
            long r = a[j].x +a[j].r ;
            if ( res == l && GS.x == r || res == r && GS.x == l ) continue ;
            else
            {
                if ( res > GS.x )
                {
                    if ( r > res && GS.x > l ) continue ;
                    else
                    {
                        dem ++ ;
                    }
                }
                if ( res < GS.x )
                {
                    if ( l < res && GS.x < r ) continue ;
                    else dem ++ ;
                }
            }
        }
    }
    if ( dem <= k ) return true ;
    return false ;
}

void xl_sub1()
{
    for ( long x = 0 ; x < ( 1 << n ) ; x ++ )
    {
        top = 0 ;
        long long res = 0 ;
        for ( long i = 0 ; i < n ; i ++ )
        {
            if ( getbit ( x , i) == 1 )
            {
                S[++top] = b[i + 1].x ;
                res += b[i+1].e ;
            }
        }
        if ( check() )
        {
            ans = max ( ans , res ) ;
        }
    }
    cout << ans ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( ZED".inp" , "r" , stdin ) ;
    freopen( ZED".out" , "w" , stdout ) ;
    nhap() ;
    xl_sub1() ;
    return 0;
}
