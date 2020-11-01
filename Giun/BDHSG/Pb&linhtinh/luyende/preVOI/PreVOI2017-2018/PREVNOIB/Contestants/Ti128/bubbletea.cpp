/*input
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 50007;

int n, k, dp[1 << 20], par[N][17], dist[N], l[N];
vector<pair<int, int> > child[N];
vector<int> v;

void dfs(int u){
	for(int i = 1; i < 17; ++i)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for(pair<int, int> v:child[u]){
		if(v.first == par[u][0]) continue;
		par[v.first][0] = u;
		l[v.first] = l[u] + 1;
		dist[v.first] = dist[u] + v.second;
		dfs(v.first);
	} 
}

int f(int a, int b){
	int u = a, v = b;
	if(l[u] < l[v]) swap(u, v);
	for(int i = 16; i >= 0; --i)
		if(l[par[u][i]] >= l[v]) u = par[u][i];
	for(int i = 16; i >= 0; --i)
		if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	while(u != v) u = par[u][0], v = par[v][0];

	return dist[a] + dist[b] - (dist[u] << 1);
}

void backtrack(int mask){
	if(mask == (1 << (int)v.size()) - 1 || (dp[mask] != 1e15 && mask != 0)) return;
	for(int i = 0; i < (int)v.size(); ++i)
		for(int j = i + 1; j < (int)v.size(); ++j)
			if((mask ^ (1 << i)) && (mask ^ (1 << j))){
				dp[mask ^ (1 << i) ^ (1 << j)] = min(dp[mask ^ (1 << i) ^ (1 << j)], max(dp[mask], f(v[i], v[j])));
				backtrack(mask ^ (1 << i) ^ (1 << j));
			}
}

signed main(){
	#ifndef ToMo
		freopen("bubbletea.inp", "r", stdin);
		freopen("bubbletea.out", "w", stdout);
	#endif

	cin >> n >> k;
	for(int i = 1; i <= k; ++i){
		int u; cin >> u;
		v.push_back(u);
	}
	for(int i = 1; i < (1 << 20); ++i)
		dp[i] = 1e15;

	for(int i = 1; i < n; ++i){
		int u, v, w; cin >> u >> v >> w;
		child[u].push_back(make_pair(v, w));
		child[v].push_back(make_pair(u, w));
	}
	dfs(1);

	backtrack(0);
	printf("%lld\n", dp[(1 << (int)v.size()) - 1]);
}