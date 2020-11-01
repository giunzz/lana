#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i <= r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 3005;
int n, m, k, a[N], b[N], rmqa[N][20], rmqb[N][20], logy[N];
int geta(int l, int r) {
	int tmp = logy[r - l + 1];
	return min(rmqa[l][tmp], rmqa[r - (1 << tmp) + 1][tmp]);
}
int getb(int l, int r) {
	int tmp = logy[r - l + 1];
	return min(rmqb[l][tmp], rmqb[r - (1 << tmp) + 1][tmp]);
}
void proca(vector<int> &v, int x) {
	int ptr = 1, cnt = 0;
	v.resize(x);
	while (cnt < x) {
		int need = x - cnt, nxtval = geta(ptr, n - need + 1);
		while (a[ptr] != nxtval) ptr++;
		v[cnt++] = nxtval;
		ptr++;
	}
}
void procb(vector<int> &v, int x) {
	int ptr = 1, cnt = 0;
	v.resize(x);
	while (cnt < x) {
		int need = x - cnt, nxtval = getb(ptr, m - need + 1);
		while (b[ptr] != nxtval) ptr++;
		v[cnt++] = nxtval;
		ptr++;
	}
}
int ans[N << 1], ans2[N << 1];
void merge(vector<int> &va, vector<int> &vb) {
	int ptr = 1, ptrb = 0;
	fa (i, va) {
		while (ptrb < vb.size() && vb[ptrb] < i) ans2[ptr++] = vb[ptrb], ptrb++;
		ans2[ptr++] = i;
	}
	while (ptrb < vb.size()) ans2[ptr++] = vb[ptrb], ptrb++;
	bool better = 0;
	fw (i, 1, k) {
		if (ans2[i] < ans[i]) {
			better = 1;
			break;
		}
		if (ans2[i] > ans[i]) break;
	}
	if (better) fw (i, 1, k) ans[i] = ans2[i];
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#else
	inout("SEQUENCE", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	fw (i, 1, n) cin >> a[i], rmqa[i][0] = a[i];
	fw (i, 1, m) cin >> b[i], rmqb[i][0] = b[i];
	fw (i, 0, N) logy[i] = log2(i);
	fw (j, 1, 15) {
		fw (i, 1, n) if (i + (1 << (j - 1)) <= n)
			rmqa[i][j] = min(rmqa[i][j - 1], rmqa[i + (1 << (j - 1))][j - 1]);
		fw (i, 1, m) if (i + (1 << (j - 1)) <= m)
			rmqb[i][j] = min(rmqb[i][j - 1], rmqb[i + (1 << (j - 1))][j - 1]);
	}
	fw (i, 1, k) ans[i] = inf;
	fw (x, 0, min(n, k)) {
		//Size of a's subsequence. Find the smallest one since a and b are independent.
		if (k - x > m) continue;
		vector<int> va, vb;
		proca(va, x);
		procb(vb, k - x);
		merge(va, vb);
	}
	fw (i, 1, k) cout << ans[i] << " ";
	return 0;
}
