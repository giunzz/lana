#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 305;
const int Inf = 1e9 + 7;

int m, n, k, x, y, u, v;
int f[N][N], g[N][N], s1, s2, a[N][N], cur_m, ans, res;

int main() {
    #define file "TABLE"
    freopen(file".INP", "r", stdin);  freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for(int p = 1; p <= k; ++p) {
        cin >> x >> y >> u >> v;
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for(int i = x; i <= u; ++i)
            for(int j = y; j <= v; ++j)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
        ans = f[u][v];
        for(int i = u; i >= x; --i)
            for(int j = v; j >= y; --j)
                g[i][j] = max(g[i + 1][j], g[i][j + 1]) + a[i][j];
        for(int i = x; i <= u; ++i) {
            for(int j = y; j <= v; ++j) if (i + j != x + y && i + j != u + v) {
                    res = -Inf;
                    for(int h = y; h < j; ++h) {
                        res = max(res, f[i][h] + g[i + 1][h]);
                    }
                    for(int h = j + 1; h <= v; ++h) {
                        res = max(res, f[i - 1][h] + g[i][h]);
//                        if (res == 30) cout << i - 1 << " " << h << " " << i << " " << h << "\n";
                    }
                    ans = min(ans, res);
                }
            }
        cout << ans << "\n";
    }
    return 0;
}
