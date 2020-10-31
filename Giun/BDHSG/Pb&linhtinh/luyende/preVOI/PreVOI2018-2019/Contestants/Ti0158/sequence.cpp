#include <bits/stdc++.h>
#define foru(a,b,c) for( int a= b; a<= c; a++)
#define ford(a,b,c) for( int a= b; a>= c; a--)
#define ll long long
#define fi first
#define se second
#define pii pair< int, int>
#define piii pair< int, pii>
#define MIN "sequence"
#define pb push_back
inline void read(int &n) { n = 0; int ch = getchar(), sign=1;while( ch < '0' || ch > '9' ){ if (ch == '-') sign = -1; ch = getchar();} while(ch >= '0' && ch <= '9'){n = n * 10 + ch - '0'; ch = getchar();}n *= sign;}

using namespace std;
const int base= 1e9+7;
const ll oo= 1e18+5;
const           int maxn= 3005;
int             n, k, m;
int             a[maxn], b[maxn], c[2*maxn], xd[105][105][205],  f[105][105][205];
pii             luu[105][105][205];
int     Calc( int vt1, int vt2, int tt)
{
    if( tt== k) return 1;
    if( tt+n+m-vt1-vt2< k) return 0;
    if( xd[vt1][vt2][tt]) return f[vt1][vt2][tt];
    xd[vt1][vt2][tt]= 1;
    int maxa= base, res= 0;
    foru(i,vt1+1,n)
    {
        int tg= Calc(i,vt2,tt+1);
        if( !tg) break;
        res= 1;
        if( maxa> a[i]) maxa= a[i], luu[vt1][vt2][tt]={i,vt2};
    }
    foru(i,vt2+1,m)
    {
        int tg= Calc(vt1,i,tt+1);
        if( !tg) break;
        res= 1;
        if( maxa> b[i]) maxa= b[i], luu[vt1][vt2][tt]={vt1,i};
    }
    return f[vt1][vt2][tt]= res;
}
void    Solve()
{
    Calc(0,0,0);
    int vt1= 0, vt2= 0, tt= 0;
    while( tt< k)
    {
        int tg1= luu[vt1][vt2][tt].fi, tg2= luu[vt1][vt2][tt].se;
        if( tg1!= vt1)
        {
            vt1= tg1;
            cout<< a[vt1]<<" ";
        }
        if( tg2!= vt2)
        {
            vt2= tg2;
            cout<< b[vt2]<<" ";
        }
        ++tt;
    }
}
void    Solve1()
{

}
int main()
{
    ios_base ::sync_with_stdio(0);
    freopen( MIN".inp", "r", stdin);
    freopen( MIN".out", "w", stdout);
    cin>> n>> m>> k;
    foru(i,1,n) cin>> a[i];
    foru(i,1,m) cin>> b[i];
    if( n<= 100&& m<= 100) Solve();
    else Solve1();
}
