#include <iostream>
using namespace std;
int n, t[(int) 1e6], m;
bool work (int time) {
	int x = 0;
	for (int i = 1; i <= n; i++) {
		x += time / t[i];
		if (t >= m) return true;
	}
	return false;
}
int main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
	int l = 1, r = 1e8, res, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (work (mid)) {
			r = mid - 1;
			res = mid;
		}
		else l = mid + 1;
	}
	printf("%d", res);
	return 0;
}
// Debug giup' be'