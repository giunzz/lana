#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int n, a[N], f[N][N], sz[N];
vector<int> G[N];

void dfs(int u) {
	sz[u] = 1;
	for(int i = 0; i < G[u].size(); ++i) dfs(G[u][i]), sz[u] += sz[G[u][i]];
	if(G[u].size() == 0) {
		f[u][0] = abs(a[u] - 0);
		f[u][1] = abs(a[u] - 1);
	}
	else if(G[u].size() == 1) {
		for(int i = 0; i <= sz[u]; ++i) f[u][i] = f[G[u][0]][i] + abs(a[u] - i);
	}
	else {
		for(int i = 0; i <= sz[G[u][0]]; ++i) {
			for(int j = 0; j <= sz[G[u][1]]; ++j) {
				f[u][i + j] = min(f[u][i + j], f[G[u][0]][i] + f[G[u][1]][j] + abs(a[u] - i - j));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) f[i][j] = 1e9;
	dfs(1);
	int ans = 1e9;
	for(int i = 0; i < N; ++i) {
		ans = min(ans, f[1][i]);
	}
	cout << ans;
}