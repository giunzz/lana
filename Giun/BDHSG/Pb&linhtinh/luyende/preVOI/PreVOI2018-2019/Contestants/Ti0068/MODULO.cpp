#include <bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 1e6 + 1e5 ;
int s[33] , a , b , n , k , cnt , mod ;
char ca , cb ;
pair< int , string > save[maxn] ;
string mod1 = "" ;

template <typename T>
void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x ;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

long long bigmod(string a,long long b)
{
	long long i,hold;
	hold=0;
	for(i=0;i<=a.size()-1;i++)
	{
		hold=((int)a[i]-48+hold*10)%b;
	}
	return hold;
}

void duyet1( int x )
{
    if( x > n/2 )
    {
        string got = "" ;
        for(int i = 1 ; i <= n ; i ++ )
        {
            if( s[i] == 0 ) got = got + ca ;
            else got += cb ;
        }
        save[ ++ cnt ].first =  bigmod( got , mod ) ;
        save[cnt].second = got ;
    }
    else
    {
         for(int i = 0 ; i <= 1 ; i ++ )
         {
             s[x] = i ;
             duyet1(x + 1) ;
             s[x] = 0 ;
         }
    }
}

void duyet( int x )
{
    if( x > n )
    {
        string got = "" ;
        for(int i = 1 ; i <= n ; i ++ )
        {
            if( s[i] == 0 ) got = got + ca ;
            else got += cb ;
        }
        if( bigmod( got , mod ) == k )
        {
            cout << got ; return ;
        }
    }
    else
    {
         for(int i = 0 ; i <= 1 ; i ++ )
         {
             s[x] = i ;
             duyet(x + 1) ;
             s[x] = 0 ;
         }
    }
}

int l , r , mid ;
bool bs( int x )
{
     l = 0 , r = cnt ;
    while( l <= r )
    {
        mid = ( l + r ) / 2 ;
        if( save[mid].first > x ) r = mid - 1 ;
        else l = mid + 1 ;
    }
    if( save[l].first == x || save[r].first == x ) return true ;
    else return false ;
}

void duyet2( int x )
{
    if( x > n - n/2 )
    {
        string got = "" ;
        for(int i = 1 ; i <= n - n / 2  ; i ++ )
        {
            if( s[i] == 0 ) got = got + ca ;
            else got += cb ;
        }
        string got1 = got ;
        got = got + mod1 ;
        int k = bigmod( got , mod ) ;
        if( bs(k) )
        {
            cout << got1 ;
            if( save[l].first == k ) cout << save[l].second ;
            else cout << save[r].second;
            return ;
        }
    }
    else
    {
        for(int i = 0 ; i <= 1 ; i ++ )
        {
            s[x] = i ;
            duyet2( x + 1 ) ;
            s[x] = 0 ;
        }
    }
}

void solve1()
{
    duyet(1) ;
}

void solve2()
{
    duyet1(1) ;
    sort( save + 1 , save + cnt + 1 ) ;
    duyet2(1) ;

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen( "MODULO.INP" , "r" , stdin ) ;
    freopen( "MODULO.OUT" , "w" , stdout ) ;
    read(a) ; read(b) ; read(n) ; read(k) ;
    for(int i = 1 ; i <= n / 2  ; i ++ ) mod1 += "0" ;
    mod = 1 << n;
    ca = a + '0' ; cb = b + '0' ;
    if( ( a + b ) % 2 == 0 && a % 2 != k % 2 ) write(-1) ;
    else if( n <= 17 ) solve1() ;
    else solve2() ;
}
