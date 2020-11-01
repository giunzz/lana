#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, res = 1e15;
int c[5010];
int dp[5010][2510];
vector <int> a[5010];

void DFS(int u, int p) {
    if (a[u].size() == 1) {
        dp[u][0] = c[u];
        dp[u][1] = abs(c[u] - 1);
        return;
    }
    int l = -1, r = -1;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (v != p) {
            DFS(v, u);
            if (l == -1) l = v;
            else r = v;
        }
    }
    if (l != -1 && r == -1) {
        for (int i = 0; i < 2510; ++i) {
            dp[u][i] = min(dp[u][i], dp[l][i] + abs(c[u] - i));
        }
    }
    else if (l != -1 && r != -1) {
        for (int i = 0; i < 2510; ++i) {
            for (int j = 0; j < 2510; ++j) {
                if (i + j >= 2510) break;
                dp[u][i + j] = min(dp[u][i + j], dp[l][i] + dp[r][j] + abs(c[u] - i - j));
            }
        }
    }
}

main() {
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2510; ++j) {
            dp[i][j] = 1e15;
        }
    }
    DFS(1, 1);
    for (int i = 0; i < 2510; ++i) {
        res = min(res, dp[1][i]);
    }
    cout << res;
}

