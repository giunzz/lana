#include <bits/stdc++.h>

using namespace std;

const int N = 205, oo = 1e9;
int memo[4][N][N][N];
int col[200];
string s;

int calc(int c, int d, int l, int r) {
	if (l == r) {
		if (d == 1) return -oo;
		else return d * d;
	}
	if (memo[c][d][l][r] != -1) return memo[c][d][l][r];
	if (col[s[l]] == c) {
		if (l == r - 1) return (d + 1) * (d + 1);
		return memo[c][d][l][r] = calc(c, d + 1, l + 1, r);
	} else {
		int cur = -oo;
		for (int k = l + 2; k <= r; ++k)
			cur = max(cur, calc(col[s[l]], 1, l + 1, k) + calc(c, d, k, r));
		return memo[c][d][l][r] = cur;
	}
}

void solve() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 1; l <= n; ++l) {
				for (int r = l; r <= n; ++r)
					memo[i][j][l][r] = -1;
			}
		}
	}
	cout << max(0, calc(col[s[0]], 1, 1, s.size())) << '\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("BALLOON.INP", "r", stdin);
	// freopen("BALLOON.OUT", "w", stdout);

	col['R'] = 0;
	col['B'] = 1;
	col['G'] = 2;
	col['Y'] = 3;
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}
