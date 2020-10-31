#include <bits/stdc++.h>
#define foru(a,b,c) for( int a= b; a<= c; a++)
#define ford(a,b,c) for( int a= b; a>= c; a--)
#define ll long long
#define fi first
#define se second
#define pii pair< int, int>
#define MIN "liondance"
#define pb push_back
inline void read(int &n) { n = 0; int ch = getchar(), sign=1;while( ch < '0' || ch > '9' ){ if (ch == '-') sign = -1; ch = getchar();} while(ch >= '0' && ch <= '9'){n = n * 10 + ch - '0'; ch = getchar();}n *= sign;}

using namespace std;
const int base= 1e9+7;
const ll oo= 1e18+5;
const int maxn= 4005;
int                 n, delta;
int                 a[maxn], b[maxn], q[maxn], lv[maxn], xd[maxn],f[maxn][maxn];
vector< pii>        pos;
pii                 luu1[maxn][maxn];
int     Getbit( int x, int i) { return x>> i&1;}
void    Solve()
{
    int kq= 0, top, d= 1;
    foru(i,0,(1<<n)-1)
    {
        top= 0;
        bool ok= true;
        foru(j,1,n) if( Getbit(i,j-1))
        {
            if( top&& abs(a[j]-q[top])> delta) { ok= false; break;}
            q[++top]= a[j];
        }
        if( !ok|| top< kq|| !top) continue;
        int d= 1;
        foru(j,1,n)
            if( b[j]== q[d]) ++d;
        if( d<= top) continue;
        if( top== kq)
        {
            foru(j,1,top)
            if( q[j]> lv[j])
            {
                foru(t,j,top) lv[t]= q[t];
                break;
            }
        }
        if( top> kq)
        {
            kq= top;
            foru(j,1,top) lv[j]= q[j];
        }
    }
    cout<< kq<<'\n';
    foru(i,1,kq) cout<< lv[i]<<" ";
}
void    Solve1()
{
    foru(i,1,n) foru(j,1,n) if( a[i]== b[j]) pos.pb({i,j}), f[i][j]= 1;
    ford(i,n,1)
    ford(j,n,1)
    if( a[i]== b[j])
    {
        for( int t= 0; t< pos.size(); ++t)
        {
            int u= pos[t].fi, v= pos[t].se;
            if( u>= i|| v>= j|| abs(a[i]-a[u])> delta)continue;
            if( f[u][v]== f[i][j]+1)
            {
                int tg1= luu1[u][v].fi;
                if( a[tg1]< a[i]) luu1[u][v]= {i,j};
            }
            if( f[u][v]< f[i][j]+1)
            {
                f[u][v]= f[i][j]+1;
                luu1[u][v]= {i,j};
            }
        }
    }
    int kq= 0, ux=0,uy=0;
    foru(i,1,n)
    foru(j,1,n)
    if( a[i]== b[j])
    {
        if( kq==f[i][j]&& a[i]> a[ux]) ux= i, uy= j;
        if( kq< f[i][j]) kq= f[i][j], ux= i, uy=j;
    }
    cout<< kq<<'\n';
    while( ux&&uy)
    {
        cout<< a[ux]<<" ";
        int tg1= luu1[ux][uy].fi, tg2= luu1[ux][uy].se;
        ux= tg1; uy= tg2;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    freopen( MIN".inp", "r", stdin);
    freopen( MIN".out", "w", stdout);
    cin>>n>>delta;
    foru(i,1,n)
    {
        cin>> a[i];
    }
    foru(i,1,n)
    {
        cin>> b[i];
    }
    if( n<= 20) Solve();
    else
        Solve1();
}
