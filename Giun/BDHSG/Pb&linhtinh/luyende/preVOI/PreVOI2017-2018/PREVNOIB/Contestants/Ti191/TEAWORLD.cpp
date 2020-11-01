#include <bits/stdc++.h>
using namespace std;

const int M = 2005;
const int N = 16;

int n, m, k;
int ans;

struct Point {
	double x; double y; double z;
	Point(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}
} a[M], shop[16], pivot;
double r[M];
int e[N];
int state[M];

bool inside(int c, int s) { // c : circle, s : shop
	double x = shop[s].x, y = shop[s].y, z = shop[s].z;
	double u = a[c].x, v = a[c].y, w = a[c].z;

	x -= u, y -= v; z -= w;
	return x * x + y * y + z * z <= r[c] * r[c];
}

bool intersect(int c, int s) { // c : circle, s : shop
	double x = shop[s].x, y = shop[s].y, z = shop[s].z;
	double u = a[c].x, v = a[c].y, w = a[c].z;
	bool flag1 = (u * u + v * v + w * w <= r[c] * r[c]);
	bool flag2 = inside(c, s);
	if (flag1 && flag2) return false;

	//cerr << x << ' ' << y << ' ' << z << endl;
	//cerr << u << ' ' << v << ' ' << w << endl;

	double A = x * x + y * y + z * z;
	double B = -2 * (u * x + v * y + w * z);
	double C = u * u + v * v + z * z - r[c] * r[c];
	if (A == 0) return false;
	if (A < 0) A = -A, B = -B, C = -C;

	double delta = B * B - 4 * A * C;
	if (delta < 0) return false;

	double r1 = (-B + sqrt(delta)) / (2 * A);
	double r2 = (-B - sqrt(delta)) / (2 * A);

	if ((0 <= r1 && r1 <= 1) || (0 <= r2 && r2 <= 1)) return true;
	return false;
}

int main() {
	freopen("TEAWORLD.inp", "r", stdin);
	freopen("TEAWORLD.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; ++i) cin >> a[i].x >> a[i].y >> a[i].z >> r[i];
	for (int i = 0; i < n; ++i) cin >> shop[i].x >> shop[i].y >> shop[i].z >> e[i];
	cin >> pivot.x >> pivot.y >> pivot.z;

	for (int i = 1; i <= m; ++i) a[i].x -= pivot.x, a[i].y -= pivot.y, a[i].z -= pivot.z;
	for (int i = 0; i < n; ++i) shop[i].x -= pivot.x, shop[i].y -= pivot.y, shop[i].z -= pivot.z;
	
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < n; ++j) if (intersect(i, j)) state[i] |= (1 << j);
	}
	
	for (int mask = 0; mask < (1 << n); ++mask) {
		int sum = 0, del = 0;
		for (int i = 0; i < n; ++i) if (mask >> i & 1) sum += e[i];
		if (sum < ans) continue;
		for (int i = 1; i <= m; ++i) if (state[i] & mask) {
			++del; if (del > k) break;
		}
		if (del > k) continue;
		ans = max(ans, sum);
	}

	cout << ans << endl;
}