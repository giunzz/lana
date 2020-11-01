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
#define ZED "arrange"
using namespace std ;

const long base = 97 ;
long n ;
typedef pair < long , long > ii ;
ii a[maxn] ;

void nhap()
{
    cin >> n ;
    for ( long i = 1 ; i <= n ; i ++ )
        {
            cin >> a[i].fi ;
            a[i].se = i ;
        }
    sort ( a + 1 , a + 1 + n ) ;
}
long long dem = 0 ;
long minn = vc ;
long maxx = -vc ;
void xl()
{
    for ( long j = 1 ; j <= n ; j ++ )
        {
            minn = min ( minn , a[j].fi ) ;
            maxx = max ( maxx , a[j].fi ) ;
        }
    if ( maxx - minn == 1 )
    {
        cout << 0 ;
        return ;
    }
    for ( long i = 1 ; i  <= 1e6 ; i ++ )
    {
        a[n].fi -- ;
        a[1].fi ++ ;
        dem ++   ;
        minn = vc ;
        maxx = -vc ;
        for ( long j = 1 ; j <= n ; j ++ )
        {
            minn = min ( minn , a[j].fi ) ;
            maxx = max ( maxx , a[j].fi ) ;
        }
        if ( maxx - minn == 1 ) break ;
        sort ( a + 1 , a + 1 + n ) ;
    }
    cout << dem ;
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
