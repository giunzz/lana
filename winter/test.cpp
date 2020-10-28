#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int query;
int n, a, ans = 0;
int cnt[N], x[N];
void BackTrack(int id) {
	if (id == n + 1) {
		int ok[N], res = 0;
		for (int i = 1; i <= n; ++i) ok[i] = 1;
		for (int i = 1; i <= n; ++i) {
			if (ok[x[i]]) {
				if (x[i] == n) ok[1] = 0;
				else ok[x[i] + 1] = 0;
			}
		}
		for (int i = 1; i <= n; ++i) if (ok[i]) res++;
		if (res == a) ans++;
	} else {
		for (int i = 1; i <= n; ++i) {
			if (cnt[i]) {
				x[id] = i;
				cnt[i]--;
				BackTrack(id + 1);
				cnt[i]++;
			}
		}
	}
}
int main() {
	freopen ("WC4.inp", "r", stdin);
	freopen ("WC4.out", "w", stdout);
	cin >> query;
	for (int qq = 1; qq <= query; ++qq) {
		cin >> n >> a;
		if (n > 6) {
			cout << "peding...\n"; 
			continue;
		}
		for (int i = 1; i <= n; ++i) cnt[i] = 1;
		ans = 0;
		BackTrack(1);
		cout << ans << endl;
	}
}