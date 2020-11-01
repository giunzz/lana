#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int > pii;

const int N = 5e4 + 6;
const int inf = 1e9 + 7;

queue<int > Q;
int deg[N];
int spe[N];
vector<pii > adj[N];
int n, k;
pii edg[N];
int trace[12][N];
int pos[N];
int mark[N];
int W[N], ass[N];

void prepare(){
	
	for (int i = 1; i <= k; i++){
		int u = spe[i];
		memset(deg, 0, sizeof deg);
		deg[u] = 1;
		Q.push(u); 
		while (!Q.empty()){
			int pre = Q.front(); Q.pop();
			for (pii ide : adj[pre]){
				int v = edg[ide.second].first ^ edg[ide.second].second ^ pre;
				if (!deg[v]) {
					deg[v] = deg[pre] + 1;
					Q.push(v);
					trace[i][v] = ide.second;
				}
			}
		}
	}
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("bubbletea.inp", "r", stdin);
	freopen("bubbletea.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		cin >> spe[i];
	}
	for (int i = 1; i < n; i++){
		int u, v, wei;
		cin >> u >> v >> wei;
		edg[i] = make_pair(u, v); W[i] = wei;
		adj[u].push_back(make_pair(wei, i));
		adj[v].push_back(make_pair(wei, i));
	}
	
	if (k == n) {
		int res = 0;
		for (int i = 1; i < n; i++)
			res = max(res, W[i]);
		cout << res;
		return 0;
	}
	if (k > 10){cout << -1; return 0;}
	prepare();
	for (int i = 1; i <= k; i++) pos[i] = i;
	int res = inf;
	vector<int > FOO;
	do{
		bool ok = 1;
		for (int i = 1; i <= k; i++) {if (pos[i] == i) ok = 0; ass[i] = pos[i];}
		for (int i = 1; i <= k; i++) 
			if (i != ass[ ass[i] ]) ok = 0;
		if (!ok) continue;
		ok = 1;
		int maxLen = 0;
		for (int i = 1; i <= k; i++){
			int u = spe[ pos[i] ], len = 0;
			if (u > spe[i]) continue;
			while (trace[i][u]){
				int id = trace[i][u];
				if (mark[id] ) ok = 0;
				mark[id] = 1, FOO.push_back(id);
				u = edg[id].first ^ edg[id].second ^ u;
				len += W[id];
			}
			maxLen = max(len, maxLen);
		}
			
		if (ok){
			res = min(res, maxLen);	
		}	
		for (int i = 0; i < (int)FOO.size(); i++) mark[FOO[i]] = 0;
		FOO.clear();
	}
	while (next_permutation(pos + 1, pos + 1 + k));
	if (res == inf) res = -1;
	cout << res;
}