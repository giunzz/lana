#include <bits/stdc++.h>
#define foru(a,b,c) for( int a= b; a<= c; a++)
#define ford(a,b,c) for( int a= b; a>= c; a--)
#define ll long long
#define fi first
#define se second
#define pii pair< int, ll>
#define MIN "modulo"
#define pb push_back
inline void read(int &n) { n = 0; int ch = getchar(), sign=1;while( ch < '0' || ch > '9' ){ if (ch == '-') sign = -1; ch = getchar();} while(ch >= '0' && ch <= '9'){n = n * 10 + ch - '0'; ch = getchar();}n *= sign;}

using namespace std;
const int base= 1e9+7;
const ll oo= 1e18+5;
int         n, a, b, m;
ll          k, kq;
ll          lt[100], mu[100];
int     getbit( int x, int i)
{
    return x>>i&1;
}
void    Solve()
{
    foru(i,0,(1<<n)-1)
    {
        ll res= 0;
        foru(j,1,n)
        if( getbit(i,j-1)) res= ( res+ lt[n-j]*a%mu[n])%mu[n];
        else  res= (res+ lt[n-j]*b%mu[n])%mu[n];
        if( res== k)
        {
            foru(j,1,n) if( getbit(i,j-1)) cout<< a;else cout<< b;
            return;
        }
    }
    cout<< -1;
}
void    Solve2()
{
    m= n/2;
    n-= m;
    map< ll, string> M;
    foru(i,0,(1<<n)-1)
    {
        ll res= 0;
        string s="";
        foru(j,1,n) if( getbit(i,j-1)) res= ( res+ lt[n-j]*a%mu[n+m])%mu[n+m], s+=(char)(a+48);
        else res= ( res+ lt[n-j]*b%mu[n+m])%mu[n+m], s+= (char)(b+48);
        if( M.find(res)== M.end()) M[res]= s;
    }
    foru(i,0,(1<<m)-1)
    {
        ll res= 0;
        string s="";
        foru(j,1,m) if( getbit(i,j-1)) res=( res+ lt[n+m-j]*a%mu[n+m])%mu[n+m], s+= (char)(a+48);
        else res= ( res+lt[n+m-j]*b%mu[n+m])%mu[n+m], s+= (char)(b+48);
        res= k-res;
        if( res<0) res+= mu[n+m];
        if( M.find(res)!= M.end())
        {
            cout<< s<< M[res];
            return;
        }
    }
    cout<< -1;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    freopen( MIN".inp", "r", stdin);
    freopen( MIN".out", "w", stdout);
    cin>> a>> b>> n>> k;
    lt[0]= mu[0]= 1;
    foru(i,1,n) mu[i]= mu[i-1]*2;
    foru(i,1,n) lt[i]= lt[i-1]*10%mu[n];
    if( n<= 20) Solve();
    else
        Solve2();
}
