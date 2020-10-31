#include <bits/stdc++.h>
using namespace std;
#define nat64 unsigned __int64
#define nat unsigned __int32
#define int64 __int64

nat n, m, k, tmp;
vector<nat> a;

int main() {
	freopen("SEQUENCE.INP", "r", stdin);
	freopen("SEQUENCE.OUT", "w", stdout);

	cin >> n >> m >> k;
	for (nat i = 0; i < n + m; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.begin() + n + m);
	for (nat i = 0; i < k; i++) cout << a[i] << ' ';

	return 0;
}