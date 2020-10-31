/*input
5
5 1 3 0 1
1 2
1 3
3 4
3 5
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int dp[N][N], G[N][N], par[N], a[N], subt[N], n;
vector<int> child[N];

void dfs(int u){
	// normal dfs
	int cnt = 0;
	for(int i = 1; i < (int)child[u].size(); ++i){
		int v = child[u][i];
		if(v == par[u]){
			swap(child[u][i--], child[u][child[u].size() - 1]);
			child[u].pop_back();
			continue;
		}

		par[v] = u, ++cnt;
		dfs(v);
		subt[u] += subt[v];
	}

	// leaf node
	if(cnt == 0){
		subt[u] = 1;
		dp[u][0] = a[u], dp[u][1] = abs(a[u] - 1);
		return;
	}

	// memset current dp
	for(int i = 0; i < (int)child[u].size(); ++i)
		for(int j = 0; j <= subt[u]; ++j)
			G[i][j] = 1e9;
	G[0][0] = 0;

	// calculate right side dp
	int sum = 0;
	for(int i = 1; i < (int)child[u].size(); ++i){
		int v = child[u][i];
		sum += subt[v];
		for(int j = 0; j <= sum; ++j)
			for(int k = 0; k <= subt[v]; ++k)
				if(j >= k) G[i][j] = min(G[i][j], G[i - 1][j - k] + dp[v][k]);
	}

	// update answer for current node
	for(int i = 0; i <= subt[u]; ++i)
		dp[u][i] = G[child[u].size() - 1][i] + abs(a[u] - i);
}

int main(){
	#ifndef ToMo
		freopen("tree.inp", "r", stdin);
		freopen("tree.out", "w", stdout);
	#endif

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		for(int j = 0; j <= n; ++j)
			dp[i][j] = 1e9;
		child[i].push_back(0);
	}

	for(int i = 1; i < n; ++i){
		int u, v; cin >> u >> v;
		child[u].push_back(v);
		child[v].push_back(u);
	}

	dfs(1);

	int ans = 1e9;
	for(int i = 0; i <= n; ++i)
		ans = min(ans, dp[1][i]);
	printf("%d\n", ans);
}