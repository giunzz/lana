#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define ii pair <int, int>

using namespace std;

int n, k, res;
int avail[200010], h[200010], s[200010];
int M[200010][20];
vector <int> b;
vector <ii> a[200010];

void DFS(int u, int p) {
	for (int i = 0; i < a[u].size(); ++i) {
        int w = a[u][i].X;
		int v = a[u][i].Y;
		if (v != p) {
			h[v] = h[u] + 1;
			s[v] = s[u] + w;
			M[v][0] = u;
			DFS(v, u);
		}
	}
}

int LCA(int u, int v) {
	if (h[u] < h[v]) return LCA(v, u);
	int lg = log2(h[u]);
	for (int i = lg; i >= 0; --i) {
		if (h[u] - (1 << i) >= h[v]) {
			u = M[u][i];
		}
	}
	if (u == v) return u;
	for (int i = lg; i >= 0; --i) {
		if (M[u][i] != M[v][i]) {
			u = M[u][i];
			v = M[v][i];
		}
	}
	return M[u][0];
}

main() {
	freopen("BUBBLETEA.inp", "r", stdin);
	freopen("BUBBLETEA.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int x; cin >> x;
		b.push_back(x);
	}
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(ii(w, v));
		a[v].push_back(ii(w, u));
	}
	h[1] = 1;
	DFS(1, 1);
    for (int j = 1; (1 << j) <= n; ++j) {
    	for (int i = 1; i <= n; ++i) {
    		M[i][j] = M[M[i][j - 1]][j - 1];
    	}
    }
    int res = 1e15;
    for (int i = 0; i + 1 < b.size(); ++i) {
    	int u = b[i];
    	int v = b[i + 1];
    	res = min(res, s[u] + s[v] - 2 * s[LCA(u, v)]);
    }
    cout << res;
}
