#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 5;

int n;
long long a[N], b[N];
long long q, r;

void sub1() {
	long long ans = 0;
	int j = n;
	int i = 1;
	while (true) {
		if (i > j) break;
		long long diff = q - a[i];
		if (diff <= 0) break;
		if (a[j] - diff > q) {
			ans += diff;
			a[i] = q;
			a[j] -= diff;
			i++;
		} else if (a[j] - diff == q) {
			ans += diff;
			a[i] = a[j] = q;
			j--;
			i++;
		} else {
			long long x = a[j] - q;
			a[i] += x;
			ans += x;
			a[j] = q;
			j--;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("ARRANGE.inp", "r", stdin); freopen("ARRANGE.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	long long sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	q = sum / n;
	r = sum % n;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) b[i] = q;
	for (int i = n; i >= n - r + 1; i--) b[i]++;
	if (r == 0) {
		sub1();
		return 0;
	}
	long long ans = 0;
	int i = 1, j = n;
	while (true) {
		if (i > j) break;
		long long diff = b[i] - a[i];
		if (a[j] - diff > b[j]) {
			a[j] -= diff;
			ans += diff;
			a[i] += diff;
			i++;
		} else if (a[j] - diff == b[j]) {
			a[j] -= diff;
			ans += diff;
			a[i] += diff;
			j--; 
			i++;
		} else {
			long long x = a[j] - b[j];
			a[i] += x;
			ans += x;
			a[j] = b[j];
			j--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/*
4
4 2 3 4

4
4 3 2 4

8
2 2 2 2 1 9 1 2
*/