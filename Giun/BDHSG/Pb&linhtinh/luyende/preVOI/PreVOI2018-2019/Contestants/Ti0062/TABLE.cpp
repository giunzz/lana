#include <bits/stdc++.h>
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
typedef long long ll;
const int N = 305;
int n, m, t, a[N][N];
ll dp1[N][N], dp2[N][N], mxk[N], mxj[N];
void read(int &number) {
    bool negative = false; register int c;
    number = 0; c = getchar();
    while (c != '-' && (c <= 47 || c >= 58)) c = getchar();
    if (c == '-') {
		negative = 1;
		c = getchar();
	}
    while (c > 47 && c < 58) {
		number = (number << 3) + (number << 1) + c - 48;
		c = getchar();
	}
    if (negative) number = -number;
}
void calc1(int u, int v, int p, int q) {
	dp1[u][v] = a[u][v]; 
	fw (i, u, p + 1) fw (j, v, q + 1) {
		if (i == u && j == v) continue;
		dp1[i][j] = -infll;
		if (i > u) dp1[i][j] = dp1[i - 1][j];
		if (j > v) dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
		dp1[i][j] += a[i][j];
	}
}
void calc2(int u, int v, int p, int q) {
	dp2[p][q] = a[p][q];
	bw (i, p + 1, u) bw (j, q + 1, v) {
		if (i == p && j == q) continue;
		dp2[i][j] = -infll;
		if (i < p) dp2[i][j] = dp2[i + 1][j];
		if (j < q) dp2[i][j] = max(dp2[i][j], dp2[i][j + 1]);
		dp2[i][j] += a[i][j];
	}
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	//freopen("ans1.out", "w", stdout);
	#else
	inout("TABLE", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read(n), read(m), read(t);
	fw (i, 0, n) fw (j, 0, m) read(a[i][j]);
	fw (i, 0, t) {
		int u, v, p, q;
		read(u), read(v), read(p), read(q);
		u--, v--, p--, q--;
		calc1(u, v, p, q);
		calc2(u, v, p, q);
		ll ans = infll;
		fw (j, u, p + 1) mxj[j] = -infll;
		fw (k, v, q + 1) mxk[k] = -infll;
		fw (j, u, p + 1) fw (k, v, q + 1) {
			if (j == u && k == v) continue;
			if (j == p && k == q) continue;
			ll cost = -infll;
			if (j > u && k < q) {
				mxk[k + 1] = max(mxk[k + 1], dp1[j - 1][k + 1] + dp2[j - 1][k + 1] - a[j - 1][k + 1]);
				cost = max(cost, mxk[k + 1]);
			}
			if (j < p && k > v) {
				mxj[j + 1] = max(mxj[j + 1], dp1[j + 1][k - 1] + dp2[j + 1][k - 1] - a[j + 1][k - 1]);
				cost = max(cost, mxj[j + 1]);
			}
			if (cost == -infll) cost = infll;
			ans = min(ans, cost);
		}
		cout << ans << "\n";
	}
	return 0;
}
