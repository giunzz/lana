#include<bits/stdc++.h>
#define maxn 305
using namespace std;

typedef int64_t lli;
struct kquery
{
    int xu;
    int xv;
    int xx;
    int xy;
};
const int xnew[]= {0, 1, 0};
kquery qu[maxn];
int n, m, q, a[maxn][maxn];
lli f[maxn][maxn];
bool visited[maxn][maxn];

lli getmax(int r, int c, int X, int Y, int s)
{
    //visited[r][c]= 1;
    for (int i=0; i<2; i++)
    {
        int vr= r+xnew[i], vc= c+xnew[i+1];
        if ( r == X && c == Y && s == 0 ) continue;
        if ( vr < 1 || vc < 1 || vr > m || vc > n ) continue;
        f[vr][vc]= max(f[r][c]+a[vr][vc], f[vr][vc]);
        getmax(vr, vc, X, Y, s);
    }
    return f[r][c];
}

void sexyBuffalo()
{
    int temp= 0, s= 0;
    for (int t=1; t<=q; t++)
    {
        int u= qu[t].xu, v= qu[t].xv, x= qu[t].xx, y= qu[t].xy;
        lli ans= LLONG_MAX;
        for (int l=u; l<=x; l++)
            for (int k=v; k<=y; k++)
            {
                if ( l==u&&k==v ) continue;
                if ( l==x&&k==y ) continue;
                for (int i=1; i<=m; i++)
                    for (int j=1; j<=n; j++)
                        f[i][j]= 0;
                f[u][v]= a[u][v];
                getmax(u, v, l, k, s);
                //for (int i=1; i<=m; i++) for (int j=1; j<=n; j++) { cout<<f[i][j]<<" "; if ( j==n ) cout<<endl; } cout<<endl;
                ans=  min(f[x][y], ans);
            }
        cout<< ans<< "\n";
    }


}
main()
{
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    cin>> m>> n>> q;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin>> a[i][j];
    int u, v, x, y;
    for (int t=1; t<=q; t++)
        cin>> qu[t].xu>> qu[t].xv>> qu[t].xx>> qu[t].xy;
    sexyBuffalo();
}
