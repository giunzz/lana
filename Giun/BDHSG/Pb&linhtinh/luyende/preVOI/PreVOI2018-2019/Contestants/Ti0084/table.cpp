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
#define maxm 400

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i,n) for (int i=0;i<(n);i=i+1)

#define TranQuynhNGA "table"

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
long n , m , k ;
long long a[400][400] ;
long long F[400][400] ;
long long G[maxm][maxm] ;
void read()
{
    cin >> n >> m >> k;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            long X ;
            cin >> X ;
            a[i][j] = X ;
        }
    }
}

long long save[maxm][maxm] , sum[maxm][maxm] ;
void Init( long i , long j , long p  , long q , long u , long v )
{
    if ( i == p && j == q )
    {
        save[i][j] = MOD ;
        return ;
    }
    if ( i == u && j == v )
    {
        save[i][j] = MOD ;
        return ;
    }
    save[i][j] = -MOD ;
}

ll show( long i , long j , long p  , long q , long u , long v )
{
    FOR(aa,p,u)
    {
        FOR(bb,q,v)
        {
            save[aa][bb] = a[aa][bb] ;
        }
    }

    Init(i,j,p,q,u,v) ;
    FOR(aa,p,u)
    {
        FOR(bb,q,v)
        {
            sum[aa][bb] = max ( sum[aa-1][bb] , sum[aa][bb-1] ) + save[aa][bb] ;
        }
    }
    ll res = sum[u][v] ;
    FOR(aa,p,u)
    {
        FOR(bb,q,v)
        {
            sum[aa][bb] = 0 ;
            save[aa][bb] = 0 ;
        }
    }
    return res ;
}

void sub1( long p , long q , long u , long v )
{

    ll ans = INF ;
    long id1 , id2 ;
    for ( long i = p ; i <= u ; i ++ )
    {
        for ( long j = q ; j <= v ; j ++ )
        {
            ll res = show(i,j,p,q,u,v) ;
            //cout << res << " " ;
            if ( ans > res )
            {
                ans = res ;
                id1 = i ;
                id2 = j ;
            }
        }
        //cout << endl ;
    }
    cout << ans << endl ;
}

int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( TranQuynhNGA".inp" , "r" , stdin ) ;
    freopen( TranQuynhNGA".out" , "w" , stdout ) ;
    read() ;
    if ( n <= 80 && m <= 80 )
    while ( k -- )
    {
        long u , v , p , q ;
        cin >> p >> q >> u >> v ;
        sub1(p,q,u,v) ;
    }
}
