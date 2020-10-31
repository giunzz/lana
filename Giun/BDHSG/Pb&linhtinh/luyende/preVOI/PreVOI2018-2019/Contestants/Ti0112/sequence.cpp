/*
7 4 9
1 2 1 3 1 2 1
1 2 3 1
*/
#include <bits/stdc++.h>
using namespace std;

namespace suffix_array {
	int n, len;
	vector<int> sa;
	vector<int> rnk;
	bool cmp(int x,int y) {
		if (rnk[x] != rnk[y]) {
			return rnk[x] < rnk[y];
		} else {
			x += len; y += len;
			if (x < n && y < n) {
				return rnk[x] < rnk[y];
			} else {
				return x > y;
			}
		}
	}
	void build(vector<int> a) {
		n = a.size();
		sa.resize(n), rnk.resize(n);
		for (int i = 0; i < n; ++i) {
			sa[i] = i;
			rnk[i] = a[i];
		}
		for (len = 1; ; len <<= 1) {
			vector<int> tmp;
			sort(sa.begin(), sa.end(), cmp);
			vector<int> pre(n, 0);
			for (int i = 1; i < n; ++i) {
				pre[i] = pre[i - 1] + cmp(sa[i - 1], sa[i]);
			}
			for (int i = 0; i < n; ++i) {
				rnk[sa[i]] = pre[i];
			}
			if (pre[n - 1] == n - 1) break;
		}
	}
}

using suffix_array::rnk;
using suffix_array::build;

vector<int> merge(vector<int> a,vector<int> b) {
	vector<int> c;
	for (auto x : a) c.push_back(x);
	c.push_back(4000);
	for (auto x : b) c.push_back(x);
	build(c);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < int(c.size()); ++i) {
		if (i == 0 || c[i - 1] == 4000) {
			pq.push(make_pair(rnk[i], i));
		}
	}
	vector<int> res;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		res.push_back(c[u]);
		if (u + 1 < int(c.size()) && c[u + 1] != 4000) {
			pq.push(make_pair(rnk[u + 1], u + 1));
		}
	}
	return res;
}

const int N = 3005;

int n, m, k;
int a[N], b[N];
vector<int> fa[N], fb[N];

void calc_fa(int u) {
	vector<int>& res = fa[u];
	res.resize(u);
	int ptr = 0;
	for (int it = 1; it <= u; ++it) {
		int mn = 4000;
		for (int i = ptr + 1; (n - i) >= (u - it); ++i) mn = min(mn, a[i]);
		res[it - 1] = mn;
		for (int i = ptr + 1; ; ++i) if (a[i] == mn) {
			ptr = i; break;
		}
	}
}

void calc_fb(int u) {
	vector<int>& res = fb[u];
	res.resize(u);
	int ptr = 0;
	for (int it = 1; it <= u; ++it) {
		int mn = 4000;
		for (int i = ptr + 1; (m - i) >= (u - it); ++i) mn = min(mn, b[i]);
		res[it - 1] = mn;
		for (int i = ptr + 1; ; ++i) if (b[i] == mn) {
			ptr = i; break;
		}
	}
}

vector<int> res;

void upd(vector<int>& u,vector<int> v) {
	if (u.empty() || u > v) u = v;
}

int main() {
	freopen("sequence.inp", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= m; ++i) scanf("%d", b + i);
	for (int u = 0; u <= n; ++u) calc_fa(u);
	for (int u = 0; u <= m; ++u) calc_fb(u);
	for (int u = 0; u <= n; ++u) {
		int v = k - u;
		if (v < 0 || v > m) continue;
		vector<int> now = merge(fa[u], fb[v]);
		upd(res, now);
	}
	for (int x : res) printf("%d ", x);
}
