#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
int a[N];
long long f[N];
long long l[N], r[N];
long long ans = 1e18;

int main() {
	freopen("GIFTS.inp", "r", stdin);
	freopen("GIFTS.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i], f[i] = f[i-1] + a[i];
	for (int i = k; i <= n; ++i) l[i] = max(l[i-1], f[i] - f[i - k]);
	for (int i = n - k + 1; i >= 1; --i) r[i] = max(r[i+1], f[i + k - 1] - f[i - 1]);

	for (int i = k; i <= n; ++i) {
		int L = i - k, R = n - i;
		long long mx = 0;
		if (L >= k) mx = max(mx, l[L]);
		if (R >= k) mx = max(mx, r[i + 1]);
		ans = min(ans, mx);
	}

	cout << ans << endl;
}