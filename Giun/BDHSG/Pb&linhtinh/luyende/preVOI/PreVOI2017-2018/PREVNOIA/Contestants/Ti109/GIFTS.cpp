#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read(T &n) {
	n = 0; char ch; bool neg = false;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') neg = !neg; n = ch - 48;
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) n = (n << 1) + (n << 3) + ch - 48; if (neg) n = -n;
}

const int N = (int) 1e6 + 5;
const long long INF = (long long) 1e18;

int n, k;
long long a[N], s[N], sum[N];
long long dpLeft[N], dpRight[N];

int main() {
	freopen("GIFTS.inp", "r", stdin); freopen("GIFTS.out", "w", stdout);
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		if (i >= k) s[i - k + 1] = sum[i] - sum[i - k];
	}
	n -= (k - 1);
	dpLeft[0] = dpRight[n + 1] = -INF;
	for (int i = 1; i <= n; i++) dpLeft[i] = max(dpLeft[i - 1], s[i]);
	for (int i = n; i >= 1; i--) dpRight[i] = max(dpRight[i + 1], s[i]);
	long long ans = INF;
	for (int i = 1; i <= n; i++) {
		if (i - k >= 1 && i + k <= n) {
			long long tmp = max(dpLeft[i - k], dpRight[i + k]);
			if (s[i] >= tmp) ans = min(ans, s[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/*
10 2
1 2 4 5 2 4 2 2 1 6
*/