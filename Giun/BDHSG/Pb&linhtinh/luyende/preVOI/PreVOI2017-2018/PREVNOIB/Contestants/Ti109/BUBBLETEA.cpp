#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

const int N = (int) 5e4 + 5;
const int K = (int) 5e4 + 5;
const long long INF = (long long) 1e18;
const int LOGN = log2(N) + 2;

struct TEdge {
	int u, v, c;
	TEdge() {}
	TEdge(int u, int v, int c) : u(u), v(v), c(c) {}
} e[N];

int n, k;
int logn;
int a[N];
vector <int> g[N];
vector <int> path[1005][1005];

int dad[N][LOGN], dep[N];
long long dist[1005][1005];
map <pair <int, int>, pair <int, int> > f;

void dfs(int u, int p) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dad[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

void build_lca() {
    for (int k = 1; k <= logn; k++)
        for (int i = 1; i <= n; i++) dad[i][k] = dad[dad[i][k - 1]][k - 1];
}

int find_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int diff = dep[v] - dep[u];
    for (int k = logn; k >= 0; k--)
        if ((diff >> k) & 1) v = dad[v][k];
    if (u == v) return u;
    for (int k = logn; k >= 0; k--)
        if (dad[u][k] != dad[v][k]) {
            u = dad[u][k];
            v = dad[v][k];
        }
    return dad[u][0];
}

void find_path(int idu, int idv) {
	int u = a[idu], v = a[idv];
	int uu = u, vv = v;
	int lca = find_lca(u, v);
	while (u != lca) {
		int jump = dad[u][0];
		path[idu][idv].push_back(f[make_pair(u, jump)] .st);
		dist[idu][idv] += f[make_pair(u, jump)].nd;
		u = jump;
	}
	while (v != lca) {
		int jump = dad[v][0];
		path[idu][idv].push_back(f[make_pair(v, jump)] .st);
		dist[idu][idv] += f[make_pair(v, jump)].nd; 
		v = jump;
	}
}

int su[N], sd[N];

int main() {
	freopen("BUBBLETEA.inp", "r", stdin); freopen("BUBBLETEA.out", "w", stdout);
	scanf("%d %d", &n, &k);
	logn = log2(n);
	for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v, c; scanf("%d %d %d", &u, &v, &c);
		f[make_pair(u, v)] = f[make_pair(v, u)] = make_pair(i, c);
		e[i] = TEdge(u, v, c);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	build_lca();
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++) {
			if (i == j) continue;
			find_path(i, j);
		}
	/*for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (i == j) continue;
			cout << "#: " << a[i] << " " << a[j] << " " << dist[a[i]][a[j]] << endl;
			for (int x = 0; x < path[a[i]][a[j]].size(); x++) cout << path[a[i]][a[j]][x] << " "; cout << endl;
		}
	}*/
	vector <int> masks;
	for (int mask = 0; mask < (1 << k); mask++) {
		if (__builtin_popcount(mask) != k / 2) continue;
		masks.push_back(mask);
	}
	long long ans = INF;
	for (int x = 0; x < masks.size(); x++) { // 252
		int mask = masks[x];
		int nu = 0, nd = 0;
		for (int i = 1; i <= k; i++) // 10
			if ((mask >> (i - 1)) & 1) su[++nu] = i;
			else sd[++nd] = i;
		map <int, int> fx;
		map <int, int> :: iterator it;
		
		do { // 120
			long long tmp = 0;
			bool ok = true;
			fx.clear();
			for (int i = 1; i <= k / 2; i++) { // 5
				tmp = max(tmp, dist[su[i]][sd[i]]);
				for (int j = 0; j < path[su[i]][sd[i]].size(); j++) { // n
					int ver = path[su[i]][sd[i]][j];
					fx[ver]++;
					if (fx[ver] >= 2) {
						ok = false;
						break;
					}
				}
			}
			if (ok) ans = min(ans, tmp);
		} while (next_permutation(sd + 1, sd + 1 + nd));
	}
	printf("%lld\n", ans);
	return 0;
}

/*
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1

8 6
1 4 5 6 7 8
1 2 1
2 3 10
3 4 1
2 5 6
2 6 6
3 7 6
3 8 6
*/