#include <bits/stdc++.h>
using namespace std;
#define nat64 unsigned __int64
#define nat unsigned __int32
#define int64 __int64

struct cord {
	nat x, y;
};

nat64 n, m, k, mx, x1, x2, y1, y2, ans, a[501][501], s[501][501];
bool block[501][501];
cord pos;

void findMax(nat x, nat y) {
	if (x == x1 && y == y1) return;
	if (x != x2 || y != y2)
		if (a[x][y] > mx) {
			mx = a[x][y];
			pos.x = x;
			pos.y = y;
		}
	if (s[x-1][y] > s[x][y-1]) findMax(x-1, y); else findMax(x, y-1);
}

void trace(nat x, nat y) {
	ans += a[x][y];
	if (x == x1 && y == y1) return;
	if (block[x-1][y]) trace(x, y-1);
	else if (block[x][y-1]) trace(x-1, y);
	else if (s[x-1][y] > s[x][y-1]) trace(x-1, y); else trace(x, y-1);
}

int main() {
	freopen("TABLE.INP", "r", stdin);
	freopen("TABLE.OUT", "w", stdout);

	cin >> n >> m >> k;
	for (nat i = 1; i <= n; i++)
		for (nat j = 1; j <= m; j++) cin >> a[i][j];

	for (nat i = 1; i <= m; i++) s[1][i] = s[1][i-1] + a[1][i];
	for (nat i = 1; i <= n; i++) s[i][1] = s[i-1][1] + a[i][1];
	for (nat i = 2; i <= n; i++)
		for (nat j = 2; j <= m; j++)
			if (s[i-1][j] > s[i][j-1]) s[i][j] = s[i-1][j] + a[i][j];
			else s[i][j] = s[i][j-1] + a[i][j];

	for (nat i = 0; i < k; i++) {
		ans = 0;
		mx = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		findMax(x2, y2);
		block[pos.x][pos.y] = 1;
		trace(x2, y2);
		block[pos.x][pos.y] = 0;
		cout << ans << '\n';
	}

	return 0;
}
