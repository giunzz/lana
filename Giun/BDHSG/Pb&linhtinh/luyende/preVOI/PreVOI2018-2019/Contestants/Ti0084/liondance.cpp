/// **********************************************************************************************************************
/// ********************************** ~ CODE - Trí Hiền Diamond ❤ TQN ~ ******************************************
/// **********************************************************************************************************************
#include <bits/stdc++.h>
#define fi first
#define se second
#define mem0(ZED)  memset(ZED,0,sizeof(ZED))
#define memt(ZED)  memset(ZED,true,sizeof(ZED))
#define mem1(ZED)  memset(ZED,1,sizeof(ZED))
#define mp make_pair
#define PB push_back
#define btcount(x) __builtin_popcount(x)
#define getbit(x,i) ((x>>i)&1)
#define offbit(x,i) (~(1<<i)&x)
#define onbit(x,i) (x|(1<<i))
#define sqr(x) ((x) * (x))
#define INF 9999999999
#define MOD 1000000007
#define maxn 1005000
#define m5 100005
#define maxm 1011

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i,n) for (int i=0;i<(n);i=i+1)

#define TranQuynhNGA "liondance"

#define ull unsigned long long
#define uld unsigned long double
#define ld long double
#define ll long long

const long base = 14012001 ;
const ll MM = 1ll * MOD * MOD ;

using namespace std ;

typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <string> vs;

// bit operater
int BIT(int i,ll x) { return(x&(1<<i));}
ll ONBIT(int i,ll x){ return(x|(1<<i));}
ll OFFBIT(int i,ll x){return (x& ~(1<<i));}
ll FLIPBIT(int i,ll x){return (x^(1<<i));}
ll NUMBIT(ll x) {return __builtin_popcount(x);}

// math
template<class T> T GCD(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T LCM(T a, T b) { return a / GCD(a, b) * b; }
long F[maxm][maxm] ;
long a[maxm] ;
long b[maxm] ;
long n , delta ;
void read()
{
    cin >> n >> delta ;
    FOR(i,1,n)
    {
        cin >> a[i] ;
    }
    FOR(i,1,n)
    cin >> b[i] ;
}
long trcx[maxn] ,  trcy[maxn] ;
vector < long > kq ;
void solve()
{
    long id ;
    long id1 = 0 ;
    for ( long i = 1 ; i <= n ; i ++ )
    {
        for ( long j = 1 ; j <= n ; j ++ )
        {
            F[i][j] = max ( F[i-1][j] , F[i][j-1] ) ;
            if ( a[i] != b[j] )
            {
                continue;
            }
            long res = 0 ;
            long val = 0 ;
            for ( long u = 0 ; u < i ; u ++ )
            {
                for ( long v = 0 ; v < j ; v ++ )
                {
                    if ( a[u] == b[v] && abs(a[i] - a[u]) <= delta )
                    {
                        if ( res <= F[u][v] )
                        {
                            res = F[u][v] ;
                            if ( val <= a[u] )
                            {
                                val = a[u] ;
                                id1 = j ;
                                id = i ;
                                trcx[i] = u ;
                                trcy[j] = v ;
                            }
                        }
                    }
                }
            }
            F[i][j] = max ( F[i][j] , res + 1 ) ;
        }
    }
    cout << F[n][n] << endl ;
    kq.PB(a[id] ) ;
    while ( trcx[id] != 0 && trcy[id1] != 0 )
    {
        id = trcx[id] ;
        id1 = trcy[id1] ;
        kq.PB(a[id] ) ;
    }
    reverse(kq.begin() , kq.end()) ;
    for ( long i = 0 ; i < kq.size() ; i ++ )
    {
        cout << kq[i] << " " ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( TranQuynhNGA".inp" , "r" , stdin ) ;
    freopen( TranQuynhNGA".out" , "w" , stdout ) ;
    read() ;
    solve() ;
}
