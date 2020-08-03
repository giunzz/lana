#include <bits/stdc++.h>
using namespace std;
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;
const ll M = 1e2 + 7;
int n, m, k, s, val[N], ans[N], color[N];
vector < int > adj[N];
queue < int > q;
int f[N][M];
void BFS(int x) {
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!color[v]) {
                color[v] = 1;
                q.push(v);
                f[v][x] = f[u][x] + 1;
            }
        }
    }
}
main() {
    fileInput("fairnt");
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        f[i][val[i]] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= k; ++i) {
        for (int u = 1; u <= n; ++u) color[u] = 0;
        for (int u = 1; u <= n; ++u) if (val[u] == i) q.push(u), color[u] = 1;
        BFS(i);
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= k; ++j) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "--\n";
    for (int u = 1; u <= n; ++u) {
        sort(f[u] + 1, f[u] + 1 + k);
        for (int i = 1; i <= s; ++i) ans[u] += f[u][i];
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= k; ++j) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << endl;
}