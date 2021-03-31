#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 605, M = 2e4 + 5;
int n, x[N], y[N], s[N][N], m, a[M], b[M], MOD, memo[N][N], tot, ok[N][N], ed[M];

ii toVec(int i, int j) {
	return ii(x[j] - x[i], y[j] - y[i]);
}
ii toVec2(int i, int j) {
	return ii(a[j] - x[i], b[j] - y[i]);
}

int cross(ii a, ii b) {
	return a.first * b.second - b.first * a.second;
}

int ccw(int i, int j, int k) {
	return cross(toVec(i, j), toVec2(i, k));
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int calc(int i, int j) { // i < j
	if (~memo[i][j]) return memo[i][j];
	if (j - i + 1 == 3) {
		if (s[i][j] & 1) return 0;
		else return 1;
	}
	if (j - i + 1 == 2) {
		return 1;
	}
	int ret = 0;
	for (int k = i + 1; k <= j - 1; ++k) if (ok[i][k] && ok[j][k]) {
		// bool d = (i == 1 && j == n && k == 2);
		int area = s[i][j];
		area -= s[i][k] + s[k][j];
		if (area % 2 == 0) {
			add(ret, calc(k, j) * calc(i, k));
		}
	}
	return memo[i][j] = ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("sol.inp", "r", stdin);
    freopen("f.inp", "r", stdin);
    freopen("f.ans", "w", stdout);

	cin >> n >> m;
	MOD = 1e9 + 7;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		for (int j = 1; j <= n; ++j) ok[i][j] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		ed[i] = 2;
		tot++;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			while (ed[j] <= n && ccw(i, ed[j], j) < 0) ed[j]++;
			if (ed[j] > n) continue;
			if (ccw(i, ed[j], j) >= 0) {
				if (ccw(i, ed[j], j) == 0) {
					ok[i][ed[j]] = ok[ed[j]][i] = 0;
					s[i][ed[j] + 1]++;
				} else s[i][ed[j]]++;
			}
		}
		for (int j = i + 2; j <= n; ++j)
			s[i][j] += s[i][j - 1];
	}
	memset(memo, -1, sizeof memo);
	cout << calc(1, n) << endl;

	return 0;
}