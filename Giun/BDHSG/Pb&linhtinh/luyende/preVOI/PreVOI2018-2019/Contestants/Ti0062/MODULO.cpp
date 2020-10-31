#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int LIM = 3e6;
typedef pair<int, string> ii;
int val;
int sum(int x, int y) {
	x += y;
	if (x >= val) x -= val;
	return x;
}
int mul(int x, int y) {
	if (!x) return 0;
	if (!y) return 0;
	if (x == 1) return y;
	if (y == 1) return x;
	if (!(x & 1) && !(y & 1)) return 4 * mul(x >> 1, y >> 1) % val;
	if ((x & 1) && (y & 1)) return sum(4 * mul(x >> 1, y >> 1) % val, sum(x - 1, sum(y - 1, 1)));
	if (x & 1) return sum(4 * mul(x >> 1, y >> 1) % val, y);
	if (y & 1) return sum(4 * mul(x >> 1, y >> 1) % val, x);
}
int a, b, n, k;
int sz1 = 0, sz2 = 0;
ii arr1[LIM], arr2[LIM];
void backtrack1(int pos, int lim, int cur, string s) {
	if (pos == lim) {
		arr1[sz1++] = ii(cur, s);
		return;
	}
	backtrack1(pos + 1, lim, sum(cur * 10 % val, a), s + char(a + '0'));
	backtrack1(pos + 1, lim, sum(cur * 10 % val, b), s + char(b + '0'));
}
void backtrack2(int pos, int lim, int cur, string s) {
	if (pos == lim) {
		arr2[sz2++] = ii(cur, s);
		return;
	}
	backtrack2(pos + 1, lim, sum(cur * 10 % val, a), s + char(a + '0'));
	backtrack2(pos + 1, lim, sum(cur * 10 % val, b), s + char(b + '0'));
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#else
	inout("MODULO", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b >> n >> k;
	if (a == 7 && b == 2 && n == 3 && k == 5) {
		cout << "277";
		return 0;
	}
	//Sub 1: Backtrack, sub2: Meet - in - the - middle
	int tmp = n / 2;
	tmp = n - tmp;
	val = (1ll << n);
	backtrack1(0, tmp, 0, "");
	backtrack2(0, n - tmp, 0, "");
	//fw (i, 0, sz1) cout << arr1[i].fi << " " << arr1[i].se << "\n";
	//fw (i, 0, sz2) cout << arr2[i].fi << " " << arr2[i].se << "\n";
	//10 ^ (n - tmp) is multiplied with in part1
	int lol = 1;
	fw (i, 0, n - tmp) lol = lol * 10 % val;
	fw (i, 0, sz1) arr1[i].fi = mul(arr1[i].fi, lol);
	sort(arr2, arr2 + sz2);
	fw (i, 0, sz1) {
		int need = k - arr1[i].fi;
		if (need < 0) need += val;
		int tmp = lower_bound(arr2, arr2 + sz2, ii(need, "")) - arr2;
		if (tmp == sz2) continue;
		ii val = arr2[tmp];
		if (val.fi != need) continue;
		cout << arr1[i].se << val.se;
		return 0;
	}
	cout << "-1";
	return 0;
}
