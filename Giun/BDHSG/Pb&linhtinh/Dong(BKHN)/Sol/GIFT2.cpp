#include <bits/stdc++.h>

using namespace std;
#define int long long
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 19, oo = 1e9;
int memo[N][19][2][2][2] /*Index, carry, zero, flag1, flag2*/, trace[N][N][2][2][2], n, digit[N];

int calc(int len, int carry, int zero, int flag1, int flag2) {
	if (len == 0) {
		if (zero && flag1 && flag2 && carry == 0) return 0;
		else return -oo;
	}
	if (~memo[len][carry][zero][flag1][flag2]) return memo[len][carry][zero][flag1][flag2];
	int ret = -oo;
	REP(x, 10) REP(y, 10) REP(z, 10) {
		if (y < x && !flag1) continue;
		if (z < y && !flag2) continue;
		int s = x + y + z;
		int nzero = zero | (x > 0), nflag1 = (y > x) | flag1, nflag2 = (z > y) | flag2;
		REP(ncarry, 8) if ((s + ncarry) % 10 == digit[len] && (s + ncarry) / 10 == carry) {
			ret = max(ret, s + calc(len - 1, ncarry, nzero, nflag1, nflag2));
		}
	}
	return memo[len][carry][zero][flag1][flag2] = ret;
}

void solve() {
	cin >> n;
	int tot = 0, tmp = n;
	memset(digit, -1, sizeof digit);
	while (tmp) {
		tot++;
		digit[tot] = tmp % 10;
		tmp /= 10;
	}
	memset(memo, -1, sizeof memo);
	if (calc(tot, 0, 0, 0, 0) < 0) cout << -1 << endl;
	else cout << calc(tot, 0, 0, 0, 0) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("GIFT.INP", "r", stdin);
	// freopen("GIFT.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}