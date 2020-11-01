/*input
7 2 3 5
*/
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int a[100], b[100], Mod = 1, k, n;
unordered_map<int, int> kek;

void back(int idx, int last, int rem, int mask, int type) {
	if(idx == last) {
		if(type) {
			int x = (k - rem + Mod) & (Mod - 1);
			if(kek.count(x)) {
				int cak = kek[x];
				for(int i = n; i > (n / 2); -- i) cout << (((mask >> i) & 1) ? a[0] : b[0]);
				for(int i = n / 2; i > 0; -- i) cout << (((cak >> i) & 1) ? a[0] : b[0]);
					cout << endl; exit(0);
			}
		}
		else kek[rem] = mask;
		return;
	}
	back(idx + 1, last, (rem + b[idx]) & (Mod - 1), mask, type);
	back(idx + 1, last, (rem + a[idx]) & (Mod - 1), mask | (1 << (idx + 1)), type);
}

int32_t main(){
	#ifndef ToMo
		freopen("modulo.inp", "r", stdin);
		freopen("modulo.out", "w", stdout);
	#endif // ToMo

	cin >> a[0] >> b[0] >> n >> k;
	Mod = Mod << n;

	for(int i = 1; i < n; ++ i) {
		a[i] = (a[i - 1] * 10) & (Mod - 1);
		b[i] = (b[i - 1] * 10) & (Mod - 1);
	}
	back(0, n / 2, 0, 0, 0), back(n / 2, n, 0, 0, 1);
	puts("-1");
}