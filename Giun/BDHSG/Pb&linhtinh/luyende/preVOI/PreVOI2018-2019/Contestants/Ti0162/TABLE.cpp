#include<bits/stdc++.h>

using namespace std;

const int N = 305;
const long long inf = 1e18 + 123;
int n, m, K, a[N][N];
long long dp[2][N][N], f[2][N];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);

    cin >> n >> m >> K;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    while (K --) {
        int u, v, p, q; cin >> u >> v >> p >> q;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[0][i][j] = dp[1][i][j] = -inf;
            }
        }
        dp[0][u][v] = a[u][v];
        for (int i = u; i <= p; ++i) {
            for (int j = v; j <= q; ++j) if (i != u || j != v) {
                dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
            }
        }
        dp[1][p][q] = a[p][q];
        for (int i = p; i >= u; --i) {
            for (int j = q; j >= v; --j) if (i != p || j != q) {
                dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j + 1]) + a[i][j];
            }
        }
        long long ans = inf;
        for (int j = v + 1; j < q; ++j) {
            for (int i = 0; i < N; ++i) f[0][i] = f[1][i] = -inf;
            for (int i = p; i >= u; --i) {
                f[0][i] = max(f[0][i + 1], dp[0][i][j - 1] + dp[1][i][j]);
            }
            for (int i = u; i <= p; ++i) {
                f[1][i] = max(f[1][i - 1], dp[1][i][j + 1] + dp[0][i][j]);
            }
            for (int i = u; i <= p; ++i) {
                ans = min(ans, max(f[0][i + 1], f[1][i - 1]) );
            }
        }
        ans = min(ans, dp[0][u][v] + dp[1][u][v + 1]);
        ans = min(ans, dp[1][p][q] + dp[0][p][q - 1]);
        cout << ans << '\n';
    }

    return 0;
}
