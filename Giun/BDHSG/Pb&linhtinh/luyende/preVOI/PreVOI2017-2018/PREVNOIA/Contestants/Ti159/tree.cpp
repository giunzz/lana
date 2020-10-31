#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int INF = 1e9;

int n, a[N], sz[N];
int f[N][N], g[N][N];
vector<int> G[N];

void dfs(int u, int p) {
    int id = 0;
    bool leaf = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == p) continue;
        dfs(v, u), leaf = 0;
    }
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == p) continue;
        id++;
        for (int j = 0; j <= sz[u]; ++j) {
            for (int k = 0; k <= sz[v]; ++k) {
                g[id][j + k] = INF;
            }
        }
        for (int j = 0; j <= sz[u]; ++j) {
            for (int k = 0; k <= sz[v]; ++k) {
                g[id][j + k] = min(g[id][j + k], g[id - 1][j] + f[v][k]);
            }
        }
        sz[u] += sz[v];
    }
    sz[u] += leaf;
    for (int i = 0; i <= sz[u]; ++i) {
        f[u][i] = g[id][i] + abs(a[u] - i);
    }
}

int main() {
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1, 1);
    int res = INF;
    for (int i = 0; i <= sz[1]; ++i) {
        res = min(res, f[1][i]);
    }
    cout << res;
}

/*
5
5 1 3 0 1
1 2
1 3
3 4
3 5
*/
