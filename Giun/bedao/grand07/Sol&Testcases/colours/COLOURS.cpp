#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

const int N = 1e5 + 10;

int n, k;
long long ans = 1;
vector < int > adj[N];

void dfs(int u, int p = 0){

	if(k < adj[u].size() + 1){
		puts("0");
		exit(0);
	}

	if(p == 0){
		ans *= k;
		ans %= mod;

		for(int i = k - 1; i >= k - adj[u].size(); --i){
			ans = ans * i;
			ans %= mod;
		}
	}
	else{
		for(int i = k - 2; i >= k - 2 - (adj[u].size() - 1) + 1; --i){
			ans = ans * i;
			ans %= mod;
		}
	}

	for(int v : adj[u]){
		if(v != p) dfs(v, u);
	}

}

int main(){
	freopen("colours.inp", "r", stdin);
	freopen("colours.out", "w", stdout);

	scanf("%d%d", &n, &k);

	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << ans;

	return 0;
}
