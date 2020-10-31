#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define mp make_pair
#define pii pair<int, int>
#define Task "table"
using namespace std;
const int N=305;
const long long inf=1000000000000;
long long dp[N][N], a[N][N], b[N][N];
int m, n, Q;
pii tr[N][N];

void setup() {
    cin >> m >> n >> Q;
    rep(i, 1, m)
        rep(j, 1, n) cin >> a[i][j];
}

pii cmax(pii p1, pii p2) {
    if(a[p1.first][p1.second]<a[p2.first][p2.second]) return p2;
    return p1;
}

void MAX(int x, int y, int u, int v) {
    if(dp[x][y]<dp[u][v]+a[x][y]) {
        dp[x][y]=dp[u][v]+a[x][y];
        tr[x][y]=cmax(tr[u][v], mp(x, y));
    } else if(dp[x][y]==dp[u][v]+a[x][y]) {
        tr[x][y]=cmax(tr[x][y], tr[u][v]);
    }
}

void MAX2(int x, int y, int u, int v) {
    if(dp[x][y]<dp[u][v]+a[x][y]) {
        dp[x][y]=dp[u][v]+a[x][y];
        tr[x][y]=tr[u][v];
    } else if(dp[x][y]==dp[u][v]+a[x][y]) {
        tr[x][y]=cmax(tr[x][y], tr[u][v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    a[0][0]=-inf;
    while(Q--) {
        int u, v, x, y; cin >> x >> y >> u >> v;
        rep(i, x-1, u)
            rep(j, y-1, v) dp[i][j]=-inf;
        dp[x][y]=a[x][y];
        tr[x][y]=mp(0, 0);
        rep(i, x, u)
            rep(j, y, v) {
                if(i==x&&j==y) continue;
                if(i==u&&j==v) {
                    MAX2(i, j, i-1, j);
                    MAX2(i, j, i, j-1);

                } else {
                    MAX(i, j, i-1, j);
                    MAX(i, j, i, j-1);
                }
            }
        rep(i, x-1, u)
            rep(j, y-1, v) {
                b[i][j]=a[i][j];
                dp[i][j]=-inf;
            }
        pii l=tr[u][v];
        b[l.first][l.second]=0;
        dp[x][y]=b[x][y];
        rep(i, x, u)
            rep(j, y, v) {
                if(i==x&&j==y) continue;
                dp[i][j]=max(dp[i][j], dp[i-1][j]+b[i][j]);
                dp[i][j]=max(dp[i][j], dp[i][j-1]+b[i][j]);
            }
        cout << dp[u][v] << '\n';
    }
    return 0;
}
