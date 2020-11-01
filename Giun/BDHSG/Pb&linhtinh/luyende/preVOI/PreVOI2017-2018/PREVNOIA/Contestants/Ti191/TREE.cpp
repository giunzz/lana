#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int inf = 1e9;

int n, a[N], sz[N];
vector<int> G[N];
int f[N][N];
int g[N];
bool isLeaf[N];

void prep(int u, int p) {
	int nChild = 0;
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i]; if (v == p) continue;
		prep(v, u);
		++nChild;
		sz[u] += sz[v];
	}
	if (nChild == 0) sz[u] = 1, isLeaf[u] = 1;
}

void dfs(int u, int p) {
	if (isLeaf[u]) {
		f[u][0] = a[u], f[u][1] = ((a[u] == 0) ? 1 : a[u] - 1);
		return;
	}
	for (int i = 1; i <= sz[u]; ++i) f[u][i] = inf;

	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i]; if (v == p) continue;
		dfs(v, u);

		for (int x = 0; x <= sz[u]; ++x) g[x] = f[u][x], f[u][x] = inf;

		for (int x = 0; x <= sz[u]; ++x) {
			for (int y = 0; y <= sz[v] && y <= x; ++y) {
				f[u][x] = min(f[u][x], g[x-y] + f[v][y]);
			}
		}
	}

	for (int x = 0; x <= sz[u]; ++x) f[u][x] += abs(x - a[u]);
}

int main() {
	freopen("TREE.inp", "r", stdin);
	freopen("TREE.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	prep(1, 1);
	dfs(1, 1);

	int ans = inf;
	for (int i = 0; i <= sz[1]; ++i) ans = min(ans, f[1][i]);
	cout << ans << endl;
}