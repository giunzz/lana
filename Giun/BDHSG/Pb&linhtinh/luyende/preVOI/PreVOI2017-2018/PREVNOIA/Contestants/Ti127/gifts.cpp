#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
long long ans = 1e18, a[N], l[N], r[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("gifts.inp", "r", stdin);
	freopen("gifts.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
	for(int i = k; i <= n; ++i) l[i] = max(l[i - 1], a[i] - a[i - k]);
	for(int i = n - k + 1; i >= 1; --i) r[i] = max(r[i + 1], a[i + k - 1] - a[i - 1]);
	for(int i = 1; i <= n - k + 1; ++i) {
		ans = min(ans, max(l[i - 1], r[i + k]));
	}
	cout << ans;
}