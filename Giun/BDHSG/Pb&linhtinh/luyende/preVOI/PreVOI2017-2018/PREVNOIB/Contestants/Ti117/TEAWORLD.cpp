/*input
12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define X fi
#define Y se
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}

ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

int gcd(int a , int b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}

struct Circle {
	int Cx, Cy, r;
	bool ign = false;
	Circle(int _Cx, int _Cy, int _r): Cx(_Cx), Cy(_Cy), r(_r) {};
};

struct spam {
	int x, y, z, t;
	spam(int _x, int _y, int _z, int _t): x(_x), y(_y), z(_z), t(_t) {};
};

struct Line {
	int a, b, c;
	Line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {};
	Line(pair<int, int> l1, pair<int, int> l2) {
		if (l1.X == l2.X) {
			a = 1; b = 0; c = l1.X;
			return;
		}
		if (l1.Y == l2.Y) {
			a = 0; b = 1; c = l1.Y;
			return;
		}
		a = l2.Y - l1.Y; b = l1.X - l2.X;
		c = 0 - a * l1.X - b * l1.Y;
		int z = gcd(a, b); z = gcd(z, c);
		a /= z; b /= z; c /= z;
		a = -a; b = -b; c = -c;
	}
};

bool intersect(Line l1, Circle l2) {
	if (l2.ign == true) return 0;
	if (l1.a == 0) {
		int zy = -l1.c;
		if (l2.Cy - l2.r > zy || l2.Cy + l2.r < zy) return 0;
		return 1;
	}
	if (l1.b == 0) {
		int zx = -l1.c;
		if (l2.Cx - l2.r > zx || l2.Cx + l2.r < zx) return 0;
		return 1;
	}
	int fx2 = 1; int fx = -2 * l2.Cx - l1.a; int fy2 = 1; int fy = -2 * l2.Cy - l1.b;
	int free = l1.c + l2.r - l2.Cx * l2.Cx - l2.Cy * l2.Cy;
	free = -free;
	int z = l1.a * l1.a;
	fx2 *= z; fx *= z; fy2 *= z; fy *= z; free *= z;
	l1.c = -l1.c;
	fy2 += l1.b * l1.b;
	fy += -2 * l1.b * l1.c;
	free += l1.c * l1.c;
	free += fx / l1.a * l1.c;
	fy += -fx / l1.a * l1.b;
	int delta = fy * fy - 4 * fy2 * free;
	if (delta >= 0) return 1;
	return 0;
}

ostream& operator << (ostream &os, Line x) {
	os << x.a << sp << x.b << sp << x.c << sp;
	return os;
}

int m, n, k;
vector<Circle> circle;
vector<spam> inp;
pair<int, int> pos;
vector<Line> line;
bitset<2005> inter[25];

void prepCircle() {
	for (int i = 0; i < m; i++) {
		bool ok = false;
		for (int j = 0; j < inp.size(); j++) {
			int dis = (inp[j].x - circle[i].Cx) * (inp[j].x - circle[i].Cx) + (inp[j].y - circle[i].Cy) * (inp[j].y - circle[i].Cy);
			if (dis <= circle[i].r) ok = true;
		}
		if (!ok) circle[i].ign = true;
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("TEAWORLD.inp", "r", stdin);
	freopen("TEAWORLD.out", "w", stdout);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z, t; cin >> x >> y >> z >> t;
		if (z != 0) return 0;
		circle.push_back(Circle(x, y, t * t));
	}
	for (int i = 1; i <= n; i++) {
		int x, y, z, t; cin >> x >> y >> z >> t;
		if (z != 0) return 0;
		inp.push_back(spam(x, y, z, t));
	}
	cin >> pos.fi >> pos.se;
	inp.push_back(spam(pos.fi, pos.se, 0, 0));
	prepCircle();
	for (int i = 0; i < n; i++)
		line.push_back(Line(pos, mp(inp[i].x, inp[i].y)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (intersect(line[i], circle[j])) {
				inter[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int mask = (1 << n) - 1; mask >= 0; mask--) {
		bitset<2005> x;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (bit(mask, i)) x |= inter[i], sum += inp[i].t;
		}
		if (x.count() > k) continue;
		ans = max(ans, sum);
	}
	cout << ans << endl;
}