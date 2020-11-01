#define Link ""

#include <iostream>
#include <cstdio>

#define TASK "ICECREAM"

using namespace std;

const int Mod = 1e9 + 9;
const int maxn = 3e2 + 10;
int n,mmax,m50,m1,maxx,minx,maxy,miny;
int f[maxn][maxn*4][maxn*2];

void Enter()
{
    cin >> n >> mmax >> m50 >> m1;
}

void Init()
{
    maxx = min(m50+n,mmax);
    minx = max(m50-3*n,0);
    m50 -= minx;
    maxx -= minx;

    maxy = min(m1+n,mmax);
    miny = max(m1-n,0);
    m1 -= miny;
    maxy -= miny;
}

void ADD(int &a, const int &b)
{
    a += b;
    if (a >= Mod)
        a -= Mod;
}

void Solve()
{
    f[0][m50][m1] = 1;
    for (int i=0;i<n;++i) {
        for (int x=0;x<=maxx;++x)
            for (int y=0;y<=maxy;++y) {
                ADD(f[i+1][x+1][y],f[i][x][y]);
                if (x >= 1)
                    ADD(f[i+1][x-1][y+1],f[i][x][y]);
                if (x >= 1 && y >= 1)
                    ADD(f[i+1][x-1][y-1],f[i][x][y]);
                else
                    if (y == 0 && x >= 3)
                        ADD(f[i+1][x-3][y],f[i][x][y]);
            }
    }
    int res = 0;
    for (int x=0;x<=maxx;++x)
        for (int y=0;y<=maxy;++y)
            ADD(res,f[n][x][y]);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef LHL
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
#else
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
#endif // LHL

    Enter();
    Init();
    Solve();
}
