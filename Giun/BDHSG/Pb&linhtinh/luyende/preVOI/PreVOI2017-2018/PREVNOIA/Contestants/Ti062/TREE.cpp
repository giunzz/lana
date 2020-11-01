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
#define maxn 6000
#define maxm 10000
#define fi first
#define se second
#define mem0(ZED)  memset(ZED,0,sizeof(ZED))
#define memt(ZED)  memset(ZED,true,sizeof(ZED))
#define memf(ZED)  memset(ZED,false,sizeof(ZED))
#define mp make_pair
#define PB push_back
#define ZED "TREE"
using namespace std ;

const long base = 97 ;
long n ;
vector < long long > a[maxn] ;
long long deg[maxn] ;
long long t[maxn] , F[maxn] ;
bool av[maxn ] ;
void nhap()
{
    cin >> n ;
    long u , v ;
    for ( long i = 1 ; i <= n ; i ++ ) cin >> t[i] ;
    for ( long i = 1 ; i <= n - 1 ; i ++ )
    {
        cin >> u >> v ;
        a[u].PB(v);
        a[v].PB(u) ;
        deg[u] ++ ;
        deg[v] ++ ;
    }
}
bool dd[50] ;
long S[50] ;
long top  ;
long long getbit ( long long x , long i )
{
    return ( x >> i ) & 1 ;
}
void Init()
{
   mem0(dd) ;
   top = 0 ;
   for ( long i = 1 ; i <= n ; i ++ )
    {
        if ( deg[i] == 1 )
            {
                dd[i] = 1 ;
                S[++top] = i ;
            }
    }
}
long long ans = vc ;
void DFS( long u )
{
    av[u] = false ;
    for ( long i = 0 ; i < a[u].size() ; i ++ )
    {
        long v = a[u][i] ;
        if ( av[v] == false ) continue ;
        DFS(v) ;
        F[u] += F[v] ;
    }
}
long id ;
void xl()
{
    for ( long x = 0 ; x < ( 1 << top ) ; x ++ )
    {
        for ( long i = 1 ; i <= n ; i ++ )
            {
                av[i] = true ;
                F[i] = 0 ;
            }
        for ( long i = 0 ; i < top ; i ++ )
            {
                if ( getbit ( x , i ) )
                {
                    long u = S[i+1] ;
                    F[u] = 1 ;
                }
            }
        long long res = 0 ;
        DFS(1) ;
        for ( long i = 1 ; i <= n ; i ++ )
        {
            res += abs ( F[i] - t[i] ) ;
        }
        ans = min ( ans , res ) ;
    }
    cout  << ans ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( ZED".inp" , "r" , stdin ) ;
    freopen( ZED".out" , "w" , stdout ) ;
    nhap() ;
    Init() ;
    xl()  ;
    return 0;
}
