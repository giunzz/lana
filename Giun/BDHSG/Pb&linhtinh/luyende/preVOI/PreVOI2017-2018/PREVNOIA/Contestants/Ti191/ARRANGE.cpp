#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
long long a[N];
long long sum;
int val;
int tot;
long long f[N];

void solve() {
	int v = -1;
	if (sum % n == 0) val = sum / n, tot = 0;
	else {
		val = sum / n + 1, tot = 1LL * val * n - sum;
		if (tot > n / 2) tot = n - tot, --val, v = +1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = min(i, tot); j >= 0; --j) {
			long long add = abs((1LL * i * val + v * j) - a[i]);
			f[j] += add;
			if (j > 0) f[j] = min(f[j], f[j-1] + add);
		}
	}

	cout << f[tot] << endl;
}

int main() {
	freopen("ARRANGE.inp", "r", stdin);
	freopen("ARRANGE.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i], a[i] += a[i-1];
	solve();
}