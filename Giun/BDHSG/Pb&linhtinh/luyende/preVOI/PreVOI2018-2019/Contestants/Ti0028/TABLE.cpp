#include <bits/stdc++.h>
#define x first
#define y second
#define ii pair <long long, int>
#define pb push_back
#define mp make_pair
using namespace std;

const int N=305;
const long long M=-1e14;
int m, n ,k, a[N][N];
long long tim[N][N], s[N][N];
ii f[N][N], f1[N][N];
pair <int, int> u, v;

void ti()
{
    scanf("%d%d%d%d", &u.x, &u.y, &v.x, &v.y);
    memset(f, -5, sizeof(f));
    memset(f1, -5, sizeof(f1));
    memset(tim, -5, sizeof(tim));
    f[u.x-1][u.y].x=0; f[u.x-1][u.y].y=1;
    for(int i=u.x; i<=v.x; ++i)
        for(int j=u.y; j<=v.y; ++j){
            f[i][j].y=f[i-1][j].y;
            f[i][j].x=f[i-1][j].x+a[i][j];
            if(f[i][j].x<f[i][j-1].x+a[i][j]){
                tim[i][j]=f[i][j].x;
                f[i][j].x=f[i][j-1].x+a[i][j];
                f[i][j].y=f[i][j-1].y;
            }
            else if(f[i][j].x==f[i][j-1].x+a[i][j]) f[i][j].y+=f[i][j-1].y;
            else tim[i][j]=max(tim[i][j], f[i][j-1].x+a[i][j]);
            tim[i][j]=max(tim[i][j], tim[i-1][j]+a[i][j]);
            tim[i][j]=max(tim[i][j], tim[i][j-1]+a[i][j]);
        }
    cout <<tim[v.x][v.y] <<endl;
}

void sub1()
{
    while(k--){
        long long in=-M;
        scanf("%d%d%d%d", &u.x, &u.y, &v.x, &v.y);
        for(int x1=u.x; x1<=v.x; ++x1)
            for(int x2=u.y; x2<=v.y; ++x2){
                if( (x1==u.x && x2==u.y) || (x1==v.x && x2==v.y) ) continue;
                s[u.x-1][u.y]=s[u.x][u.y-1]=0;
                s[x1][x2]=M;
                for(int i=u.x; i<=v.x; ++i)
                    for(int j=u.y; j<=v.y; ++j){
                        if(i==x1 && j==x2) continue;
                        s[i][j]=max(s[i-1][j], s[i][j-1])+a[i][j];
                    }
                in=min(in, s[v.x][v.y]);
            }
        printf("%lld\n", in);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);
    if(n<=100) { sub1(); return 0; }
    while(k--) ti();
    return 0;
}
