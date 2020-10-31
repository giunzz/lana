#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back
#define ll long long

typedef pair<int, int> ii;
typedef pair<ll, ll> lii;
const int N = 305;
const ll oo = 1e18;

int n, m, k;
int a[N][N], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
ll f[N][N], g[N][N], row[N][N], col[N][N];

bool check(int x, int y) { return (x>= 1 && x<=n&&y>=1&&y<=m); }
ll solve(int x1, int y1, int x2, int y2)    {
    FOR(i, x1 - 1, x2 + 1) FOR(j, y1 - 1, y2 + 1)
        f[i][j] = g[i][j] = row[i][j] = col[i][j] = -oo;
    f[x1][y1] = a[x1][y1];
    FOR(i, x1, x2) FOR(j, y1, y2)   {
        for(int t = 0; t < 2; ++t)  {
            int x = i + dx[t], y = j + dy[t];
            if(check(x, y)) {
                if(f[x][y] < f[i][j] + 1ll * a[x][y]) {
                    f[x][y] = f[i][j] + 1ll * a[x][y];
                }
            }
        }
    }
    g[x2][y2] = a[x2][y2];
    for(int i = x2; i >= x1; --i) for(int j = y2; j >= y1; --j)   {
        for(int t = 2; t < 4; ++t)  {
            int x = i + dx[t], y = j + dy[t];
            if(check(x, y)) {
                g[x][y] = max(g[x][y], g[i][j] + 1ll * a[x][y]);
            }
        }
    }
    ll ans = oo;
    FOR(i, x1, x2) FOR(j, y1, y2)  {
        row[i][j] = row[i][j - 1];
        if(i < x2) row[i][j] = max(row[i][j], f[i][j] + g[i + 1][j]);
        col[i][j] = col[i - 1][j];
        if(j < y2) col[i][j] = max(col[i][j], f[i][j] + g[i][j + 1]);
        if(ii(i, j) != ii(x1, y1) && ii(i, j) != ii(x2, y2)) {
            ll val = max(row[i][j - 1], col[i - 1][j]);
            ans = min(ans, val);
        }
    }
    return ans;
}
signed main()
{
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    //freopen("test.inp", "r",stdin);
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
    FOR(i, 1, k)    {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%lld\n", solve(x1, y1, x2, y2));
    }
}
/*
5 2 4 2
3 2 6 8
7 8 9 3
*/
