#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

inline double det(double a, double b, double c, double d) {
    return a * d - b * c;
}
struct Point {
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    double length() {
        return sqrt(x * x + y * y + z * z);
    }
    Point operator*(double s) {
        return Point(x * s, y * s, z * s);
    }
    double operator * (Point a) const { return x*a.x + y*a.y + z*a.z; }
    Point operator + (Point a) { return Point(x+a.x, y+a.y, z+a.z); }
    Point operator - (Point a) { return Point(x-a.x, y-a.y, z-a.z); }
    Point operator %(const Point &op) const {
        return Point(det(y, z, op.y, op.z), -det(x, z, op.x, op.z), det(x, y,
                op.x, op.y));
    }
};


ostream &operator<<(ostream &os, Point p) {
    return os << p.x << ' ' << p.y << ' ' << p.z;
}
struct Space {
    double a, b, c, d;
    Space(Point p0, Point p1, Point p2) {
        a = p0.y * (p1.z - p2.z) + p1.y * (p2.z - p0.z) + p2.y * (p0.z - p1.z);
        b = p0.z * (p1.x - p2.x) + p1.z * (p2.x - p0.x) + p2.z * (p0.x - p1.x);
        c = p0.x * (p1.y - p2.y) + p1.x * (p2.y - p0.y) + p2.x * (p0.y - p1.y);
        d = -p0.x * (p1.y * p2.z - p2.y * p1.z) - p1.x * (p2.y * p0.z - p0.y * p2.z) 
- p2.x * (p0.y * p1.z - p1.y * p0.z);
    }
};
Point projection(Point v, Point u) { // Chiếu vector v lên vector u
    double scalar = (v * u) / (u * u);
    return u * scalar;
}
Point projection(Point p, Point a, Point b, Point c) { // Chiếu điểm p lên mặt phẳng ABC
    Point u = (b - a) % (c - a), v = p - a;
    double scalar = (v * u) / (u * u);
    return p - (u * scalar);
}

bool kk(double a, double b, double c) {
    if ((a <=b && b <= c) || (a >= b && b >= c)) return 1;
    return 0;
}


double sq(double x) { return x * x; }
double dist(Point a, Point b) {
    return sqrt(sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z));
}
double dist(Point p, Point b, Point a) { // Khoảng cách từ p tới đường thẳng AB
    Point _p = p;
    p = p - a;
    Point proj = projection(p, b - a);
    b = b - a; a = a - a;
    if (kk(proj.x, a.x, b.x) && kk(proj.y, a.y, b.y) && kk(proj.z, a.z, b.z))
        return min(dist(p, a), dist(p, b));
    swap(a, b);
    if (kk(proj.x, a.x, b.x) && kk(proj.y, a.y, b.y) && kk(proj.z, a.z, b.z))
        return min(dist(p, a), dist(p, b));
    return dist(p, proj);
}

typedef long long ll;
typedef pair<int, int> ii;
const int maxn = 2005;

int N, M, R;
struct ball {
	Point p;
	double t;
} Ball[maxn];
struct light {
	Point p;
	int t;
} Light[maxn];

int dst[maxn];

Point E;

bitset<2000> Need[maxn];

bool check(int ball, int light) {
    if (dist(Ball[ball].p, E) <= Ball[ball].t
        && dist(Ball[ball].p, Light[light].p) <= Ball[ball].t)
            return 0;
        // cout << Ball[ball].p << ' ' << Light[light].p << ' ' << E << endl;
    // cout << ball << ' ' << light << ' ' << dist(Ball[ball].p, Light[light].p, E) << ' ' << Ball[ball].t << endl;
    return dist(Ball[ball].p, Light[light].p, E) <= Ball[ball].t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> N >> M >> R && (N || M || R)) {
        for (int i = 0; i < N; ++i)
            cin >> Ball[i].p.x >> Ball[i].p.y >> Ball[i].p.z >> Ball[i].t;
        for (int i = 0; i < M; ++i) {
            Need[i] = 0;
            cin >> Light[i].p.x >> Light[i].p.y >> Light[i].p.z >> Light[i].t;
        }
        cin >> E.x >> E.y >> E.z;
        for (int i = 0; i < M; ++i) {
            dst[i] = Light[i].t;
            for (int j = 0; j < N; ++j) {
                if (check(j, i)) Need[i][j] = 1;
            }
        }
        int ans = 0;
        for (int m = 0; m < (1 << M); ++m) {
            int x = 0;
            bitset<2000> k;
            for (int i = 0; i < M; ++i) if (m & (1 << i))
                k |= Need[i];
            // if (!(m & (m - 1))) cout << m << ' ' << k.count() << endl;
            if (k.count() > R) continue;
            for (int i = 0; i < M; ++i) if (m & (1 << i))
                x += dst[i];
            ans = max(ans, x);
        }
        cout << ans << "\n";
    }
}