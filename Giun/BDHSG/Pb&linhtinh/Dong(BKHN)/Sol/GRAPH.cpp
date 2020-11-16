#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5;
int n, a[N], pref[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater <int>());
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	if (pref[n] & 1) {
		cout << "NO" << endl;
		return;
	}
	if (pref[n] > n * (n - 1)) {
		cout << "NO" << endl;
		return;
	}
	int l = n - 1, r = 1;
	a[0] = N * N;
	for (l = 1; l < n; ++l) {
		while (r < n && a[r + 1] > l)
			r++;
		int sum = pref[n] - pref[r] + (r - l) * l;
		if (pref[l] > l * (l - 1) + sum) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("ERDOS.INP", "r", stdin);
	// freopen("ERDOS.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}