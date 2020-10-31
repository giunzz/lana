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
#define INF 99999999999999999999
#define MOD 1000000007
#define maxn 1005000
#define m5 100005
#define maxm 1011

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i,n) for (int i=0;i<(n);i=i+1)

#define TranQuynhNGA "modulo"

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
unsigned long long k ;
unsigned long long A , B ;
long n ;
unsigned long long mu2[70] ;
void read()
{
    cin >> A >> B ;
    cin >> n >>  k ;
    mu2[0] = 1 ;
    for ( long i= 1 ; i <= 63 ; i ++ )
        mu2[i] = mu2[i-1] * 2  ;
}

void sub1()
{
    unsigned long long res = 0 ;
    for ( long x = 0 ; x < (1<<n) ;x ++ )
    {
        res = 0 ;
        for ( long i = 0 ; i < n ; i ++ )
        {
            if ( getbit(x,i) )
            {
                res = res * 10 + A ;
            }
            else
                res = res * 10 + B ;
        }
        if ( res % mu2[n] == k )
        {
            cout << res ;
            return ;
        }
    }
    cout << -1 ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( TranQuynhNGA".inp" , "r" , stdin ) ;
    freopen( TranQuynhNGA".out" , "w" , stdout ) ;
    read() ;
    if ( n <= 20 )
    sub1() ;
    else
        cout << -1 ;
}
