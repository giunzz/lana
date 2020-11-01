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

#define TranQuynhNGA "sequence"

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
pii a[maxn] , b[maxn] ;
long dema[maxn] , demb[maxn] ;
bool sx ( const pii &a , const pii &b )
{
    return a.se < b.se ;
}
void read()
{
    cin >> n >> m >> k ;
    for ( long i = 1  ;  i <= n ; i ++ ) cin >> a[i].fi , a[i].se = i  ;
    for ( long j = 1 ; j <= m ; j ++ ) cin >> b[j].fi , b[j].se = j  ;

    for ( long i = 1 ; i <= n ; i ++ )
    {
        for ( long j = 1 ; j <= i ; j ++ )
        {
            if ( a[j] <= a[i] )
                dema[i] ++ ;
        }
    }

    for ( long i = 1; i <= m ; i ++ )
    {
        for ( long j = 1 ; j <= i ; j ++ )
        {
            if ( b[j] <= b[i]  )
                demb[i] ++ ;
        }
    }
    sort ( a + 1 , a + 1 + n ) ;
    sort ( b + 1 , b + 1 + m ) ;
}
string sa ,  sb ;
long top = 0 ;
void xla( long sla )
{
    long id , res ;
    for ( long i = 1 ; i <= n ; i ++ )
    {
        if ( dema[a[i].se] >= sla )
        {
            id = a[i].se ;
            res = a[i].fi ;
            break ;
        }
    }
    long t = 0 ;
    //sort ( a + 1 , a + 1 + n , sx ) ;
    for ( long i = 1 ; i <= n ; i ++ )
    {
        if ( a[i].fi <= res && a[i].se <= id )
        {
            t ++ ;
            stringstream st ;
            st << a[i].fi ;
            string z ;
            z = st.str() ;
            sa = sa + z ;
        }
        if ( t == sla )
            break ;
    }
}
void xlb ( long slb )
{
    long id , res ;
    for ( long i = 1 ; i <= m ; i ++ )
    {
        if ( dema[b[i].se] >= slb )
        {
            id = b[i].se ;
            res = b[i].fi ;
            break ;
        }
    }
    long t = 0 ;
    //sort ( b + 1 , b + 1 + m , sx ) ;
    for ( long i = 1 ; i <= m ; i ++ )
    {
        if ( b[i].fi <= res && b[i].se <= id )
        {
            t ++ ;
            stringstream st ;
            st << b[i].fi ;
            string z ;
            z = st.str() ;
            sb = sb + z ;
        }
        if ( t == slb )
            break ;
    }
}
string ans[5000] ;

void solve()
{
    sort ( a + 1 , a + 1 + n ) ;
    sort ( b + 1 , b + 1 + m ) ;
    if ( n > k )
    {
        for ( long i = 1 ; i <= k ; i ++ )
            cout << a[i].fi << " " ;
        long z = n - k ;
        for ( long j = 1 ; j <= z ; j ++ )
            cout << b[j].fi << " " ;
        return ;
    }
    if ( m > k )
    {
        long z = m - k ;
        for ( long i =1 ; i <= z ; i ++ ) cout << a[i].fi << " " ;
        for ( long j = 1 ; j <= m ; j ++ ) cout << b[j].fi << " " ;
        return ;
    }
    for ( long i = 1 ; i <= n ; i ++ )
        cout << a[i].fi << " " ;
    long z = k - n ;
    for ( long j = 1 ; j <= z ; j ++ )
        cout << b[j].fi << " " ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( TranQuynhNGA".inp" , "r" , stdin ) ;
    freopen( TranQuynhNGA".out" , "w" , stdout ) ;
    read() ;
    solve() ;
}
