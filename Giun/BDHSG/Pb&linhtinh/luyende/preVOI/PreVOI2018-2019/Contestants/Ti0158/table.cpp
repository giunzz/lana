#include <bits/stdc++.h>
#define foru(a,b,c) for( int a= b; a<= c; a++)
#define ford(a,b,c) for( int a= b; a>= c; a--)
#define ll long long
#define fi first
#define se second
#define pii pair< int, int>
#define MIN "table"
#define pb push_back
inline void read(int &n) { n = 0; int ch = getchar(), sign=1;while( ch < '0' || ch > '9' ){ if (ch == '-') sign = -1; ch = getchar();} while(ch >= '0' && ch <= '9'){n = n * 10 + ch - '0'; ch = getchar();}n *= sign;}

using namespace std;
const int base= 1e9+7;
const ll oo= 1e18+5;
const               int maxn= 305;
int                 n, m, k;
int                 a[maxn][maxn], f[maxn][maxn], tx[2]= {0,1}, ty[2]= {1,0}, xd[maxn][maxn];
pii                 luu[maxn][maxn], q[maxn];
int     BFS( int x, int y, int u, int v)
{
    foru(i,x,u) foru(j,y,v) f[i][j]= -base;
    f[x][y]= a[x][y];
    foru(i,x,u) foru(j,y,v)
        {
            foru(t,0,1)
            {
                int ux= i+ tx[t], uy= j+ ty[t];
                if( ux> u|| uy> v|| xd[ux][uy]) continue;
                if( f[ux][uy]< f[i][j]+ a[ux][uy])
                {
                    f[ux][uy]=f[i][j]+ a[ux][uy];
                    luu[ux][uy]= pii(i,j);
                }
            }
        }
}
void    Solve()
{
    int x, y, u,v, top;
    while( k--)
    {
        cin>> x>> y>> u>> v;
        BFS(x,y,u,v);
        top= 0;
        int ux= u, uy= v;
        while( ux!= x|| uy!= y)
        {
            q[++top]= pii{ux,uy};
            int tg1= luu[ux][uy].fi, tg2= luu[ux][uy].se;
            ux= tg1; uy= tg2;
        }
        int kq= base;
        foru(i,2,top)
        {
            xd[q[i].fi][q[i].se]= 1;
            BFS(x,y,u,v);
            kq= min( kq, f[u][v]);
            xd[q[i].fi][q[i].se]= 0;
        }
        cout<< kq<<'\n';
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    freopen( MIN".inp", "r", stdin);
    freopen( MIN".out", "w", stdout);
    cin>> n>> m>> k;
    foru(i,1,n) foru(j,1,m) cin>> a[i][j];
    if( k<= 80&& n<= 80&& m<= 80) Solve();
}
