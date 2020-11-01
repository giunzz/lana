#include <bits/stdc++.h>
using namespace std;

#define task "tree"
#define maxN 5123
#define inf 1123456789

vector<int> adj[maxN];
int n;
int l[maxN],nc[maxN],a[maxN];
int child[3][maxN];
int f[maxN][maxN];

void dfs(int u, int p) {
	for (auto &v : adj[u]) if (v!=p) {
		child[++nc[u]][u] = v;
		dfs(v,u);
		l[u] += l[v];
	} 
	if (!nc[u]) ++l[u];
	// cerr << u << " " << l[u] << endl;
}

void dfs2(int u) {
	for (int i=1; i<=nc[u]; ++i) dfs2(child[i][u]);
	if (!nc[u]) for (int i=0; i<=1; ++i) f[u][i] = abs(a[u] - i);
	if (nc[u]==1) for (int i=0; i<=l[u]; ++i) f[u][i] = f[child[1][u]][i] + abs(a[u]-i);
	if (nc[u]==2) {
		int v1 = child[1][u];
		int v2 = child[2][u];
		for (int i=0; i<=l[u]; ++i) {
			f[u][i] = inf;
			for (int j=max(0,i-l[v2]); j<=min(i,l[v1]); ++j)
				f[u][i] = min(f[u][i], f[v1][j] + f[v2][i-j] + abs(a[u] - i));
		}
	}
}

int main() {
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	int u,v;
	int res = inf;
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for (int i=1; i<=n-1; ++i) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,1);
	dfs2(1);
	for (int i=0; i<=l[1]; ++i) {
		res = min(res,f[1][i]);
		// cerr << f[1][i] << endl;
	}
	printf("%d\n", res);
}