#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
bool a[N];
long long X, MAX;
bool invalid;
vector< pair<int,int> > G[N];
multiset<long long>::iterator it;

long long dfs(int u, int p) {
	multiset <long long> s;
	if (a[u]) s.insert(0);
	for (int i = 0; i < G[u].size(); ++i) {
		if (invalid) return -1;
		int v = G[u][i].second, c = G[u][i].first; if (v == p) continue;
		long long cur = dfs(v, u);
		if (cur != -1) s.insert(cur + c);
	}

	long long rem = -1;
	while(!s.empty()) {
		it = s.end(); --it;
		long long cur = (*it); s.erase(it);

		it = s.upper_bound(X - cur);
		if (it == s.begin()) {
			if (rem == -1) { rem = cur; continue; }
			else { invalid = 1; return -1; }
		}
		else --it, s.erase(it);
	}

	return rem;
}

bool check() {
	invalid = false;
	dfs(1, -1);
	return (!invalid);
}

int main() {
	freopen("BUBBLETEA.inp", "r", stdin);
	freopen("BUBBLETEA.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int x; cin >> x; a[x] = 1;
	}
	for (int i = 1; i < n; ++i) {
		int u, v, c; cin >> u >> v >> c; MAX += c;
		G[u].push_back(make_pair(c, v)); G[v].push_back(make_pair(c, u));
	}
	
	long long l = 0, r = MAX;
	while(l < r) {
		X = ((l + r) >> 1);
		if (check()) r = X; else l = X + 1;
	}
	cout << l << endl;
}