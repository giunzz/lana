#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;
#define st first
#define nd second

const int N = 5e4 + 5;

int n, k, f[N];
vector<ii> a[N];
bool check[N], flag;

void dfs(int u, int p, int lim) {
	f[u] = -1;
	vector<ii> child; set<ii> s;
	for(int i = 0; i < a[u].size(); ++i) {
		int v = a[u][i].st; if(v == p) continue;
		dfs(v, u, lim);
		if(flag == false) return;
		if(f[v] != -1) child.push_back(ii(f[v] + a[u][i].nd, v)), s.insert(ii(f[v] + a[u][i].nd, v));
	}
	if(check[u]) child.push_back(ii(0, u)), s.insert(ii(0, u));
	sort(child.begin(), child.end());
	for(int i = (int)child.size() - 1; i >= 0; --i) if(s.find(child[i]) != s.end()) {
		s.erase(child[i]);
		set<ii>::iterator it = s.upper_bound(ii(lim - child[i].st, 1e18));
		if(it == s.begin()) {
			s.insert(child[i]);
			continue;
		}
		it--;
		s.erase(it);
	}
	if(s.size() == 1) f[u] = (*s.begin()).st;
	else if(s.size() > 1) flag = false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("bubbletea.inp", "r", stdin);
	freopen("bubbletea.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		check[x] = true;
	}
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(ii(v, w));
		a[v].push_back(ii(u, w));
	}
	int l = 0, r = 1e18;
	while(l != r) {
		int mid = (l + r) / 2;
		flag = true; dfs(1, 1, mid);
		if(flag) r = mid;
		else l = mid + 1;
	}
	if(l == 1e18) cout << -1;
	else cout << l;
}