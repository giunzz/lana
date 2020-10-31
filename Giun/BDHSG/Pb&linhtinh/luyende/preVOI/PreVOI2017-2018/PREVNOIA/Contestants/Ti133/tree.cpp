#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int n, sz;
int a[N];
int L[N];
int R[N];
int f[N][N];
int topo[N];
int child[N];
int isLeaf[N];
vector < int > adj[N];

void dfs(int u, int p = 0){
	topo[++sz] = u;
	int cnt = 0;
	for(int x : adj[u]){
		if(x == p) continue;
		if(L[u] == 0) L[u] = x;
		else R[u] = x;
		++cnt;
		dfs(x, u);
		child[u] += child[x];
	}
	if(cnt == 0){
		isLeaf[u] = 1;
		child[u] = 1;
	}
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	else{
		freopen("tree.inp", "r", stdin);
		freopen("tree.out", "w", stdout);
	}

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}

	for(int i = 1; i < n; ++i){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}


	dfs(1);
	int ans = 1e9;

	for(int i = n; i >= 1; --i){
		int x = topo[i];
		if(isLeaf[x]){
			f[x][0] = a[x];
			f[x][1] = abs(a[x] - 1);
			continue;
		}
		for(int val = 0; val <= child[x]; ++val){
			f[x][val] = 1e9;
			if(R[x] == 0){
				f[x][val] = f[L[x]][val] + abs(a[x] - val);
				continue;
			}			
			int l = L[x];
			int r = R[x];
			int own = abs(a[x] - val);
			if(child[l] > child[r]) swap(l, r);
			for(int c = max(0, val - child[r]); c <= min(child[l], val); ++c){
				f[x][val] = min(f[x][val], f[l][c] + f[r][val - c] + own);
			}
			if(x == 1) ans = min(ans, f[x][val]);
		}		
	}

	cout << ans;
	return 0;
}