#include <bits/stdc++.h>
#define foru(a,b,c) for( int a= b; a<= c; a++)
#define ford(a,b,c) for( int a= b; a>= c; a--)
#define ll long long
#define fi first
#define se second
#define pii pair< int, int>
#define piii pair< int, pii>
#define MIN "icecream"
#define pb push_back
inline void read(int &n) { n = 0; int ch = getchar(), sign=1;while( ch < '0' || ch > '9' ){ if (ch == '-') sign = -1; ch = getchar();} while(ch >= '0' && ch <= '9'){n = n * 10 + ch - '0'; ch = getchar();}n *= sign;}

using namespace std;
const int base= 1e9+9;
const ll oo= 1e18+5;
const int maxn= 10004;
int         n, mmax, a,b,c, money, dem;
int         f[20][12][12][12], xd[20][12][12][12], l[10000000];
map< piii, int>     M;
map< piii, int>     :: iterator it;
int     Calc( int vt, int tt1, int tt2, int tt3)
{
    if( vt> n) return 1;
    if( xd[vt][tt1][tt2][tt3]) return f[vt][tt1][tt2][tt3];
    xd[vt][tt1][tt2][tt3]= 1;
    int res= 0;
    if( tt1< mmax) res= Calc(vt+1,tt1+1,tt2,tt3);
    if( tt1&& tt2< mmax) res= ( res+ Calc(vt+1,tt1-1,tt2+1,tt3))%base;
    if( (tt1&& tt2&& tt3< mmax)) res=( res+ Calc(vt+1,tt1-1,tt2-1,tt3+1))%base;
    else if( tt1>= 3&& tt3<= mmax) res=( res+ Calc(vt+1,tt1-3,tt2,tt3+1))%base;
    return f[vt][tt1][tt2][tt3]= res;
}
int     Calc1( int vt, int tt1, int tt2)
{
    if( vt> n) return 1;
    it= M.find({vt,{tt1,tt2}});
    int res= 0;
    if( it!= M.end())
    {
        res= M[{vt,{tt1,tt2}}];
        return l[res];
    } else M[{vt,{tt1,tt2}}]=++dem;
    int tg= dem;
    int sum= money+vt-1, x,y, z;
    x= tt1;
    y= tt2;
    z= (sum-tt1-tt2*2)/3;
    if( x< mmax) res= Calc1( vt+1, x+1,y);
    if( x&& y< mmax) res= ( res+ Calc1(vt+1,x-1,y+1))%base;
    if( x&& y&& z< mmax) res= ( res+ Calc1(vt+1,x-1,y-1))%base;
    else
    {
        if( x>= 3&& z< mmax) res= ( res+ Calc1(vt+1,x-3,y))%base;
    }
    return l[tg]= res;
}
void    Solve()
{
    if( n<= 15) { cout<< Calc(1,a,b,c);return;}
    money=a+2*b+c*4;
    cout<< Calc1(1,a,b);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    freopen( MIN".inp", "r", stdin);
    freopen( MIN".out", "w", stdout);
    cin>> n>> mmax>> a>> b>> c;
    Solve();
}
