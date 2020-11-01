#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, m, k;
int a[N][N];
int pre[N][N], suf[N][N];

void build(int u,int v,int p,int q) {
	for (int i = u; i <= p; ++i) {
		for (int j = v; j <= q; ++j) {
			pre[i][j] = suf[i][j] = -1e9;
		}
	}
	pre[u][v] = a[u][v];
	for (int i = u; i <= p; ++i) {
		for (int j = v; j <= q; ++j) {
			if (i < p) pre[i + 1][j] = max(pre[i + 1][j], pre[i][j] + a[i + 1][j]);
			if (j < q) pre[i][j + 1] = max(pre[i][j + 1], pre[i][j] + a[i][j + 1]);
		}
	}
	suf[p][q] = a[p][q];
	for (int i = p; i >= u; --i) {
		for (int j = q; j >= v; --j) {
			if (i > u) suf[i - 1][j] = max(suf[i - 1][j], suf[i][j] + a[i - 1][j]);
			if (j > v) suf[i][j - 1] = max(suf[i][j - 1], suf[i][j] + a[i][j - 1]);
		}
	}
}

int calc(int u,int v,int p,int q,int x,int y) {
	int mx = -1e9;
	if (x < p) {
		for (int i = v; i < y; ++i) {
			mx = max(mx, pre[x][i] + suf[x + 1][i]);
		}
	}	
	if (y < q) {
		for (int i = u; i < x; ++i) {
			mx = max(mx, pre[i][y] + suf[i][y + 1]);
		}
	}
	return mx;
}

int solve(int u,int v,int p,int q) {
	int x = p, y = q;
	int mn = 1e9;
	while (true) {
		if (x > u && pre[x][y] == pre[x - 1][y] + a[x][y]) {
			--x;
		} else {
			--y;
		}
		if (x == u && y == v) {
			break;
		} else {
			mn = min(mn, calc(u, v, p, q, x, y));
		}
	}
	return mn;
}

int main() {
	freopen("table.inp", "r", stdin);
	freopen("table.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	while (k--) {
		int u, v, p, q; scanf("%d %d %d %d", &u, &v, &p, &q);
		build(u, v, p, q);
		printf("%d\n", solve(u, v, p, q));
	}
}
