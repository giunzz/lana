#include <bits/stdc++.h>
using namespace std;

const int N = 4005;

int n, delta;
int L[N], R[N];
int pre[N][N + N];
vector<int> z;
pair<int,int> f[N];

int main() {
	freopen("liondance.inp", "r", stdin);
	freopen("liondance.out", "w", stdout);
	scanf("%d %d", &n, &delta);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", L + i);
		z.push_back(L[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", R + i);
		z.push_back(R[i]);
	}
	sort(z.begin(), z.end());
	z.resize(unique(z.begin(), z.end()) - z.begin());
	for (int i = 1; i <= n; ++i) {
		L[i] = lower_bound(z.begin(), z.end(), L[i]) - z.begin();
		R[i] = lower_bound(z.begin(), z.end(), R[i]) - z.begin();
	}	
	int sz = z.size();
	for (int i = 0; i < sz; ++i) pre[0][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < sz; ++j) {
			pre[i][j] = pre[i - 1][j];
		}
		pre[i][R[i]] = i;
	}
	int mx = 0;
	for (int i = n; i > 0; --i) {
		if (pre[n][L[i]] == 0) {
			f[i] = make_pair(0, 0); continue;
		}
		f[i] = make_pair(1, pre[n][L[i]]);
		for (int j = i + 1; j <= n; ++j) {
			if (abs(z[L[i]] - z[L[j]]) > delta) continue;
			int pos = f[j].second;
			if (pos == 0) continue;
			if (pre[pos - 1][L[i]] == 0) continue;
			if (f[j].first + 1 > f[i].first) {
				f[i].first = f[j].first + 1;
				f[i].second = pre[pos - 1][L[i]];
			} else if (f[j].first + 1 == f[i].first) {
				f[i].second = max(f[i].second, pre[pos - 1][L[i]]);
			}
		}
		mx = max(mx, f[i].first);
	}
	printf("%d\n", mx);
	int first = 0;
	for (int i = 1; i <= n; ++i) {
		if (f[i].first == mx) first = max(first, L[i]);
	}
	int now = -1;
	for (int i = 1; i <= n; ++i) {
		if (f[i].first == mx && L[i] == first) {
			now = i;
			printf("%d ", z[first]); break;
		}
	}
	mx--;
	while (mx--) {
		int nxt = -1;
		for (int i = now + 1; i <= n; ++i) {
			if (abs(z[L[i]] - z[L[now]]) > delta) continue;
			if (f[i].first + 1 != f[now].first) continue;
			if (f[i].second == 0) continue;
			if (pre[f[i].second][L[now]] == 0) continue;
			nxt = max(nxt, L[i]);
		}
		if (nxt == -1) {
			printf("%d\n", now);
		}
		printf("%d ", z[nxt]);
		for (int i = now + 1; i <= n; ++i) {
			if (abs(z[L[i]] - z[L[now]]) > delta) continue;
			if (f[i].first + 1 != f[now].first) continue;
			if (f[i].second == 0) continue;
			if (pre[f[i].second][L[now]] == 0) continue;
			if (L[i] == nxt) {
				now = i; break;
			}
		}
	}
}
