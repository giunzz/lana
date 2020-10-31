#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 9, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 305;
int n, mmax, m50, m1, m2, dp[N][4 * N][2 * N];
int get(int i, int j, int k) {
	int rj = j - 3 * n, rk = k - n;
	int l = i - rj - 2 * rk;
	if (l % 4) return 0;
	return dp[i][j][k];
}
void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	freopen("ans1.out", "w", stdout);
	#else
	inout("ICECREAM", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> mmax >> m50 >> m1 >> m2;
	/*
	dp[i][j][k][l]: ith student, j 50 cents, k 1 USD, l 2 USD
	Optimize: We only store j, k, l of inserted coins. Original ones are an offset. O(N ^ 4).
	*/
	int lim50 = mmax - m50 + 3 * n, lim1 = mmax - m1 + n, lim2 = mmax - m2;
	lim50 = min(lim50, 4 * n), lim1 = min(lim1, 2 * n), lim2 = min(lim2, n);
	dp[0][3 * n][n] = 1;
	//For all (i, j, k), there's only 1 l: (i - j - 2k) / 4
	fw (i, 1, n + 1) fw (j, 0, lim50 + 1) fw (k, 0, lim1 + 1) {
		int rj = j - 3 * n, rk = k - n;
		if (rj + m50 < 0) continue;
		if (rk + m1 < 0) continue;
		int l = i - rj - 2 * rk;
		if (l % 4) continue;
		l /= 4;
		if (l > lim2) continue;
		if (j) add(dp[i][j][k], get(i - 1, j - 1, k));
		if (k) add(dp[i][j][k], get(i - 1, j + 1, k - 1));
		if (l) add(dp[i][j][k], get(i - 1, j + 1, k + 1));
		if (rk + m1 == 0 && l) add(dp[i][j][k], get(i - 1, j + 3, k));
	}
	int ans = 0;
	fw (j, 0, lim50 + 1) fw (k, 0, lim1 + 1) add(ans, get(n, j, k));
	cout << ans;
	return 0;
}
