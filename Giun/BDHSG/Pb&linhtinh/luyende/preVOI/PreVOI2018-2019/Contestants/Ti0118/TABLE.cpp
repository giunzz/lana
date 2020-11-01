#define Link ""

#include <iostream>
#include <cstdio>

#define TASK "TABLE"

using namespace std;

const long long oo = 1e18;
const int maxn = 3e2 + 100;
int m,n,k,a[maxn][maxn];
long long f[maxn][maxn][2],S[101][101][101][101];

void Enter()
{
    cin >> m >> n >> k;
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j)
            cin >> a[i][j];
}

void Init()
{

}

void Solve()
{
    if (m * n * m * n <= 1e8) {
        for (int i=1;i<=m;++i)
            for (int j=1;j<=n;++j)
                for (int k=i;k<=m;++k)
                    for (int l=j;l<=n;++l) {
                        S[i][j][k][l] = max(S[i][j][k-1][l],S[i][j][k][l-1]) + a[k][l];
                    }
        for (;k>0;--k) {
            int u,v,p,q;
            cin >> u >> v >> p >> q;
            long long res = +oo;
            for (int i=u;i<=p;++i)
                for (int j=v;j<=q;++j) {
                    long long D = -oo;
                    if ((i == u && j == v) || (i == p && j == q))
                        continue;
                    if (j - 1 >= v)
                        for (int i2=i+1;i2<=p;++i2)
                            D = max(D,S[u][v][i2][j-1]+S[i2][j-1][p][q]-a[i2][j-1]);
                    if (i - 1 >= u)
                        for (int j2=j+1;j2<=q;++j2)
                            D = max(D,S[u][v][i-1][j2]+S[i-1][j2][p][q]-a[i-1][j2]);
                    res = min(res,D);
                }
            cout << res << '\n';
        }
    }
    else
        for (;k>0;--k) {
            int u,v,p,q;
            cin >> u >> v >> p >> q;
            f[u][v][0] = a[u][v];
            f[u][v][1] = +oo;
            for (int i=u+1;i<=p;++i) {
                f[i][v][0] = f[i-1][v][0] + a[i][v];
                f[i][v][1] = +oo;
            }
            for (int j=v+1;j<=q;++j) {
                f[u][j][0] = f[u][j-1][0] + a[u][j];
                f[u][j][1] = +oo;
            }
            for (int i=u+1;i<=p;++i)
                for (int j=v+1;j<=q;++j) {
                    f[i][j][0] = max(f[i-1][j][0],f[i][j-1][0]) + a[i][j];
                    if (i == u + 1 && j == v + 1)
                        f[i][j][1] = min(f[i-1][j][0],f[i][j-1][0]) + a[i][j];
                    else
                        f[i][j][1] = min(max(f[i-1][j][1],f[i][j-1][1]),min(f[i-1][j][0],f[i][j-1][0])) + a[i][j];
                    cout << i << ' ' << j << ' ' << f[i][j][1] << '\n';
                }
            cout << f[p][q][1] << '\n';
        }
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
