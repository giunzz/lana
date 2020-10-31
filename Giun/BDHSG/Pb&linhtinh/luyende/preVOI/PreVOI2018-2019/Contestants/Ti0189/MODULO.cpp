#include <bits/stdc++.h>
using namespace std;
#define nat64 unsigned __int64
#define nat unsigned __int32
#define int64 __int64

nat64 a, b, n, k, ans, hLength, head, power2;
queue<nat64> q;

nat getLength(nat64 inp) {
	nat res = 0;
	while (inp) res++, inp /= 10;
	return res;
}

nat64 pow2(nat inp) {
	nat64 tmp = 1;
	for (nat i = 0; i < inp; i++) tmp *= 2;
	return tmp;
}

int main() {
	freopen("MODULO.INP", "r", stdin);
	freopen("MODULO.OUT", "w", stdout);

	cin >> a >> b >> n >> k;

	power2 = pow2(n);
	q.push(a);
	q.push(b);

	while (!q.empty()) {
		head = q.front();
		hLength = getLength(head);
		if (hLength < n) {
			q.push(head * 10 + a);
			q.push(head * 10 + b);
		}
		else
			if (hLength == n && head % power2 == k) {
				ans = head;
				break;
			}
		q.pop();
	}

	if (ans) cout << ans; else cout << -1;
	return 0;
}