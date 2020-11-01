#include <bits/stdc++.h>
using namespace std;

#define y1 sdjfgkjd
#define x1 fjdhff

const int M = (int) 2e3 + 5;
const int N = 20;

struct TBall {
	double x, y, z, r;
	TBall() { x = y = z = r = 0; }
	TBall(double x, double y, double z, double r) : x(x), y(y), z(z), r(r) {}
} b[M];

struct TTea {
	double x, y, z, e;
	TTea() { x = y = z = e = 0; }
	TTea(double x, double y, double z, double e) : x(x), y(y), z(z), e(e) {}
} t[N];

struct TPoint {
    double x, y;
    TPoint() {}
    TPoint(double x, double y) : x(x), y(y) {}
};

struct TVector {
    double tx, ty;
    TVector() {}
    TVector(double tx, double ty) : tx(tx), ty(ty) {}
};

int m, n, k;
double xs, ys, zs;

inline double sqr(double x) {
	return x * x;
}

inline double dist(double x, double y, double u, double v) {
	return sqr(x - u) + sqr(y - v);
}

inline double dot_product(TVector u, TVector v)  {
    return u.tx * v.tx + u.ty * v.ty;

}

inline double cross_product(TVector u, TVector v) {
    return u.tx * v.ty - u.ty * v.tx;
}

inline bool point_in_seg(const TPoint &A, const TPoint &M, const TPoint &N) {
    double C = cross_product(TVector(M.x - A.x, M.y - A.y), TVector(N.x - A.x, N.y - A.y));
    double D =   dot_product(TVector(M.x - A.x, M.y - A.y), TVector(N.x - A.x, N.y - A.y));
    return (C == 0 && D <= 0);
}

inline bool cut(const int &i, const int &j) { // i: qua cau / j : cua hang
	if (dist(xs, ys, b[i].x, b[i].y) <= b[i].r && dist(t[j].x, t[j].y, b[i].x, b[i].y) <= b[i].r) return false;
	double a1 = t[j].y - ys, b1 = -(t[j].x - xs), c1 = -xs * (t[j].y - ys) + ys * (t[j].x - xs);
	if (a1 == 0 && b1 == 0) return false;
	if (a1 == 0) {
		double y = -c1 / b1;
		double tmp = sqr(b[i].r) - sqr(y - b[i].y);
		if (tmp < 0) return false;
		double x1 = sqrtl(tmp) + b[i].x;
		double x2 = -sqrtl(tmp) + b[i].x;
		if (point_in_seg(TPoint(x1, y), TPoint(xs, ys), TPoint(t[j].x, t[j].y)) ||
			point_in_seg(TPoint(x2, y), TPoint(xs, ys), TPoint(t[j].x, t[j].y))) return true;
		else return false;
	} else if (b1 == 0) {
		double x = -c1 / a1;
		double tmp = sqr(b[i].r) - sqr(x - b[i].x);
		if (tmp < 0) return false;
		double y1 = sqrtl(tmp) + b[i].y;
		double y2 = -sqrtl(tmp) + b[i].y;
		if (point_in_seg(TPoint(x, y1), TPoint(xs, ys), TPoint(t[j].x, t[j].y)) ||
			point_in_seg(TPoint(x, y2), TPoint(xs, ys), TPoint(t[j].x, t[j].y))) return true;
		else return false;
	} else {
		double a2 = sqr(b1) + sqr(a1);
		double b2 = a1 * 2 * b[i].x * b1 - 2 * b[i].y * a1;
		double c2 = a1 * 2 * b[i].x * c1 + sqr(c1) + sqr(b[i].x) * sqr(a1) + sqr(b[i].y) * sqr(a1) - sqr(b[i].r) * sqr(a1);
		double denta = sqr(b2) - 4 * a2 * c2;
		if (denta < 0) return false;
		if (denta == 0) {
			double y = -b2 / (2 * a2);
			double x = (-c1 - b1 * y) / a1;
			if (point_in_seg(TPoint(x, y), TPoint(xs, ys), TPoint(t[j].x, t[j].y))) return true;
			else return false;
		} else {
			double y1 = (-b2 - sqrtl(denta)) / (2 * a2), x1 = (-c1 - b1 * y1) / a1;
			double y2 = (-b2 + sqrtl(denta)) / (2 * a2), x2 = (-c1 - b1 * y2) / a1;
			if (point_in_seg(TPoint(x1, y1), TPoint(xs, ys), TPoint(t[j].x, t[j].y)) ||
				point_in_seg(TPoint(x2, y2), TPoint(xs, ys), TPoint(t[j].x, t[j].y))) return true;
			else return false;
		}
	}
}

bool f[M][N];

int main() {
	freopen("TEAWORLD.inp", "r", stdin); freopen("TEAWORLD.out", "w", stdout);
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z, r; cin >> x >> y >> z >> r;
		b[i] = TBall(x, y, z, r);
	}
	for (int i = 1; i <= n; i++) {
		int x, y, z, e; cin >> x >> y >> z >> e; 
		t[i] = TTea(x, y, z, e);
	}
	cin >> xs >> ys >> zs;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) 
			if (cut(i, j)) f[i][j] = true;
	long long ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		long long tmp = 0;
		vector <int> tea;
		for (int i = 1; i <= n; i++)
			if ((mask >> (i - 1)) & 1) {
				tea.push_back(i);
				tmp += t[i].e;
			}
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < tea.size(); j++) {
				if (f[i][tea[j]]) {
					cnt++;
					break;
				}
			}
			if (cnt > k) break;
		}
		if (cnt <= k) ans = max(ans, tmp);
	}
	cout << ans << "\n";
	return 0;
}

/*
1 2 0
0 0 0 1
-1 0 0 5
2 0 0 100
1 0 0

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