#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
int a, b, n;
ull k;

ull pw(ull x,ull y,ull mod) {
	ull ret = 1;
	while (y) {
		if (y & 1ULL) ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1; 
	}
	return ret;
}

ull inv(int x) {
	ull ret = pw(5, (1ULL << (x - 1)) - 1, 1ULL << x);
	return ret;
}

ull toInt(string s) {
	ull ret = 0;
	for (char c : s) ret = (ret * 10 + (c - '0')) % (1ULL << n);
	return ret;
}

void solve(int fa,int fb,ull fk) {
	if ((fa + fb) % 2) {
		string ans = "";
		for (int i = 0; i < n; ++i) {
			if ((fk % 2) == (fa % 2)) {
				ans = char(a + '0') + ans;
				fk = (fk + (1ULL << (n - i)) - fa) % (1ULL << (n - i));
				fk = (fk * inv(n - i)) % (1ULL << (n - i));
				fk /= 2;
			} else {
				ans = char(b + '0') + ans;
				fk = (fk + (1ULL << (n - i)) - fb) % (1ULL << (n - i));
				fk = (fk * inv(n - i)) % (1ULL << (n - i));
				fk /= 2;
			}
		}
		cout << ans << '\n';
		assert(toInt(ans) == k);
		exit(0);
	}
	if (fa % 2 == 0) {
		if (fk % 2) return;
		int nfa = fa / 2;
		int nfb = fb / 2;
		ull nfk = fk / 2;
		solve(nfa, nfb, nfk);
		solve(nfa, nfb, nfk + (1ULL << (n - 1)));
	} else {
		if (fk % 2 == 0) return;
		int nfa = (fa - 1) / 2;
		int nfb = (fb - 1) / 2;
		ull now = 0;
		for (int i = 0; i < n; ++i) now = (now * 10 + 1) % (1ULL << n);
		ull nfk = (fk - now + (1ULL << n)) % (1ULL << n);
		nfk /= 2;
		solve(nfa, nfb, nfk);
		solve(nfa, nfb, nfk + (1ULL << (n - 1)));
	}
}

int main() {
	freopen("modulo.inp", "r", stdin);
	freopen("modulo.out", "w", stdout);
	cin >> a >> b >> n >> k;
	solve(a, b, k);
	cout << -1 << '\n';
}
