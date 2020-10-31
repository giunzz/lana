#include <bits/stdc++.h>
#define fto(i,a,b) for (int i=a; i<=b; i++)
#define fdto(i,a,b) for (int i=a; i>=b; i--)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define maxn 301
using namespace std;
int n, m, k, a[maxn][maxn];
void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    cin >> m >> n >> k;
    fto (i,1,m) fto (j,1,n) cin >> a[i][j];
}
int dx[2]={0,1}, dy[2]={1,0}, xd[maxn][maxn];
long long d[maxn][maxn];
pii tr[maxn][maxn], q[maxn*maxn*4];
void bfs (int xs,int ys, int xf, int yf)
{
    int dau=1, c=1;
    q[1]={xs, ys};   d[xs][ys]=a[xs][ys];
    bool ok=false;
    while (dau<=c ) {
        int u=q[dau].fi, v=q[dau].se;  ++dau;
        fto (j,0,1) {
        int x=u+dx[j], y=v+dy[j];
        if (x>0 && x<=xf && y>0 && y<=yf)
            if (xd[x][y]==0 && d[x][y]<d[u][v]+a[x][y]){
                d[x][y]=d[u][v]+a[x][y];
                tr[x][y]={u,v};
                if (x==xf && y==yf) {continue;}
                q[++c]={x,y};
            }
            else if (xd[x][y]==1 && x==xf && y==yf && d[x][y]<d[u][v]) {
                d[x][y]=d[u][v];
                tr[x][y]={u,v};
            }
        }
    }
}
void xuli()
{
    fto (t,1,k) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        fto (u1,1,m) fto (v1,1,n) d[u1][v1]=0;
        bfs(x, y, u, v);
        long long res=d[u][v];
        int i=u, j=v;
        while (i!=x && j!=y) {
            int i1=tr[i][j].fi,  j1=tr[i][j].se;
            xd[i1][j1]=1;
            fto (u1,1,m) fto (v1,1,n) d[u1][v1]=0;
            bfs(x, y, u, v);
            res=min(res, d[u][v]);
            xd[i1][j1]=0;
            i=i1; j=j1;
        }
        cout << res << '\n';
    }
}

int main()
{
    nhap();
    xuli();
    return 0;
}
