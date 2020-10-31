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
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 4005;
int n, a[N], b[N], dp[105][105], tmpa[N], tmpb[N], prva[105][205], prvb[105][205], diff, damn[105][105];
vector<int> vals;
int getpos(int val) {
	int tmp = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
	return tmp;
}
void trace(int i, int j) {
	if (dp[i][j] == 1) {
		cout << a[i] << " ";
		return;
	}
	cout << a[i] << " ";
	trace(prva[i - 1][damn[i][j]], prvb[j - 1][damn[i][j]]);
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#else
	inout("LIONDANCE", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//Find LCS that no 2 adjacent elements differ more than delta.
	cin >> n >> diff;
	fw (i, 0, n) cin >> a[i], vals.pb(a[i]);
	fw (i, 0, n) cin >> b[i], vals.pb(b[i]);
	reverse(a, a + n);
	reverse(b, b + n);
	//dp[i][j]: Answer for prefix i of a, j of b, last picked was a[i] and b[j]
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	fw (i, 0, n) tmpa[i] = getpos(a[i]), tmpb[i] = getpos(b[i]);
	memset(prva, -1, sizeof prva);
	memset(prvb, -1, sizeof prvb);
	fw (i, 0, n) {
		fw (j, 0, vals.size()) prva[i][j] = (i ? prva[i - 1][j] : -1);
		prva[i][tmpa[i]] = i;
	}
	fw (i, 0, n) {
		fw (j, 0, vals.size()) prvb[i][j] = (i ? prvb[i - 1][j] : -1);
		prvb[i][tmpb[i]] = i;
	}
	fw (i, 0, n) fw (j, 0, n) {
		dp[i][j] = -inf;
		if (a[i] != b[j]) continue;
		dp[i][j] = 1;
		if (!i || !j) continue;
		fw (k, 0, vals.size()) {
			int pos1 = prva[i - 1][k], pos2 = prvb[j - 1][k];
			if (pos1 == -1 || pos2 == -1) continue;
			if (abs(vals[k] - a[i]) > diff) continue;
			//dp[i][j] = max(dp[i][j], dp[pos1][pos2] + 1);
			if (dp[pos1][pos2] + 1 == dp[i][j]) damn[i][j] = k;
			else if (dp[pos1][pos2] + 1 > dp[i][j]) damn[i][j] = k, dp[i][j] = dp[pos1][pos2] + 1;
		}
	}
	cout << dp[n - 1][n - 1] << "\n";
	trace(n - 1, n - 1);
	return 0;
}
