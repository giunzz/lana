#include <bits/stdc++.h>
using namespace std;

const int N = (int) 5e3 + 5;
const long long INF = (long long) 1e15;

int n;
int a[N];
bool leaf[N];
long long dp[N][N];
int maxv[N];
vector <int> g[N];

void dfs_init(int u, int p) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		dfs_init(v, u);
		maxv[u] += maxv[v];
	}
}

inline void minimize(long long &a, const long long &b) {
	a = (a < b) ? a : b;
}

void dfs(int u, int p) {
	vector <int> child;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		child.push_back(v);
		dfs(v, u);
	}
	if (child.size() == 1) {
		int cr = child[0];
		for (int v = 0; v <= maxv[cr]; v++) {
			if (dp[cr][v] == INF) continue;
			minimize(dp[u][v], dp[cr][v] + abs(a[u] - v));
		}
	} else if (child.size() == 2) {
		int cr1 = child[0];
		int cr2 = child[1];
		for (int v1 = 0; v1 <= maxv[cr1]; v1++) {
			int lim = min(maxv[cr2], maxv[u] - v1);
			for (int v2 = 0; v2 <= lim; v2++) {
				if (dp[cr1][v1] == INF || dp[cr2][v2] == INF) continue;
				minimize(dp[u][v1 + v2], dp[cr1][v1] + dp[cr2][v2] + abs(a[u] - v1 - v2));
			}
		}
	}
}

int main() {
	freopen("TREE.inp", "r", stdin); freopen("TREE.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 1) {
		printf("%d", min(a[n], abs(1 - a[n])));
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (i != 1 && g[i].size() == 1) {
			leaf[i] = true;
			maxv[i] = 1;
			dp[i][0] = abs(a[i] - 0);
			dp[i][1] = abs(a[i] - 1);
		}
	dfs_init(1, 0);
	for (int i = 1; i <= n; i++) {
		if (leaf[i] == true) continue;
		for (int c = 0; c <= maxv[i]; c++) dp[i][c] = INF;
	}
	dfs(1, 0);
	long long ans = INF;
	for (int v = 0; v <= maxv[1]; v++) minimize(ans, dp[1][v]);
	printf("%lld\n", ans);
	return 0;
}

/*
5
5 1 3 0 1
1 2
1 3
3 4
3 5
*/