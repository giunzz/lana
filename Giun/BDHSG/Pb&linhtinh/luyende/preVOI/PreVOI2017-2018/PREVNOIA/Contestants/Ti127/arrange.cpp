#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define st first
#define nd second

const int N = 1e5 + 5;

int n, a[N], cnt1, cnt2;
long long ans = 1e18, s[N], f[2][N];

void upd(long long &x, long long y) {
	x = min(x, y);
}

int main() {
	freopen("arrange.inp", "r", stdin);
	freopen("arrange.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
	int x = s[n] / n;
	cnt2 = s[n] - x * n;
	cnt1 = n - cnt2;
	for(int i = 0; i <= 1; ++i) for(int j = 0; j <= cnt2; ++j) f[i][j] = 1e18;
	f[0][0] = 0;
	for(int i = 0; i <= cnt1; ++i) {
		for(int j = 0; j <= cnt2; ++j) f[(i + 1) & 1][j] = 1e18;
		for(int j = 0; j <= cnt2; ++j) {
			upd(f[(i + 1) & 1][j], f[i & 1][j] + abs(s[i + j + 1] - x * (i + 1) - (x + 1) * j));
			upd(f[i & 1][j + 1], f[i & 1][j] + abs(s[i + j + 1] - x * i - (x + 1) * (j + 1)));
		}
	}
	cout << f[cnt1 & 1][cnt2];
}