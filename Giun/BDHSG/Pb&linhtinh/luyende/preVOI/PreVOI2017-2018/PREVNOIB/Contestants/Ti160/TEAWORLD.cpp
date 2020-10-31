#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORd(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define ms(x, n) memset(x, n, sizeof(x))
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define prec(x) fixed << setprecision((x))
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define long long long
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "------\n";
template<class T> inline int chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template<class T> inline int chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
typedef pair<int, int> pi;
const int INF = (int) 1e9;
const long LINF = (long) 1e18;
const double EPS = (double) 1e-8;
#define bitcount(x) __builtin_popcount((x))

const int maxn = 15 + 15;
const int maxm = 2000 + 15;
const int maxv = 500 + 15;
const int offset = 500;

int sign(double x) { return x < -EPS ? -1 : x > EPS;}
int sign(double x, double y) { return sign(x - y);}

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
    int operator == (const Point& rhs) const { return sign(x, rhs.x) == 0 && sign(y, rhs.y) == 0; }
    Point operator + (const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator * (double c) const { return Point(x * c, y * c); }
    Point operator / (double c) const { return Point(x / c, y / c); }
};

double dot(Point p, Point q) { return p.x * q.x + p.y * q.y; }

int m, n, k, mark[maxm];
int xmm[maxm], ymm[maxm], zmm[maxm], r[maxm];
int xnn[maxn], ynn[maxn], znn[maxn], e[maxn];
int sx, sy, sz;

int bit(int x, int i) { return (x >> i) & 1; }

vector<Point> intersect(Point a, Point b, Point c, double r) {
    vector<Point> ret;
    b = b - a;
    a = a - c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r * r;
    double D = B * B - A * C;
    if (D < -EPS) return ret;
    ret.pb(c + a + b * (-B + sqrt(D + EPS)) / A);
    if (D > EPS) ret.pb(c + a + b * (-B - sqrt(D)) / A);
    return ret;
}

double check(Point p, Point a, Point b) {
    double lx = min(a.x, b.x);
    double rx = max(a.x, b.x);
    double ly = min(a.y, b.y);
    double ry = max(a.y, b.y);
    return sign(p.x, lx) >= 0 && sign(p.x, rx) <= 0 && sign(p.y, ly) >= 0 && sign(p.y, ry) <= 0;
}

int calc(vector<int> v) {
    FOR(i, 1, m) mark[i] = 0;
    FOR(i, 0, sz(v) - 1) {
        FOR(j, 1, m) if (!mark[j]) {
            int id = v[i];
            if (r[j] == 0) {
                if (!check(Point(xmm[j], ymm[j]), Point(sx, sy), Point(xnn[id], ynn[id]))) continue;
                if (Point(sx, sy) == Point(xnn[id], ynn[id])) continue;
                mark[j] = 1;
            } else {
                vector<Point> pts = intersect(Point(sx, sy), Point(xnn[id], ynn[id]), Point(xmm[j], ymm[j]), r[j]);
                if (sz(pts) == 0) continue;
                if (sz(pts) == 1) mark[j] = 1;
                if (sz(pts) == 2) {
                    if (pts[0] == Point(sx, sy) && pts[1] == Point(xnn[id], ynn[id])) continue;
                    if (pts[0] == Point(xnn[id], ynn[id]) && pts[1] == Point(sx, sy)) continue;
                    if (check(pts[0], Point(sx, sy), Point(xnn[id], ynn[id])) ||
                        check(pts[1], Point(sx, sy), Point(xnn[id], ynn[id]))) {
                        mark[j] = 1;
                    }
                }
            }
        }
    }
    int ret = 0;
    FOR(j, 1, m) ret += mark[j];
    return ret;
}

void sub2() {
    int maxbit = (1 << n) - 1;
    long ans = 0;
    FOR(x, 0, maxbit) {
        vector<int> v;
        long sum = 0;
        FOR(i, 0, n - 1) if (bit(x, i)) {
            v.pb(i + 1);
            sum += e[i + 1];
        }
        if (calc(v) <= k) {
            chkmax(ans, sum);
        }
    }
    cout << ans;
}

void sub3() {
    long ans = 0;
    FOR(i, 1, n) ans += e[i];
    cout << ans;
}

int main() {
    freopen("TEAWORLD.INP", "r", stdin);
    freopen("TEAWORLD.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> k;
    int mxy = -INF;
    int mxz = -INF;
    FOR(i, 1, m) {
        cin >> xmm[i] >> ymm[i] >> zmm[i] >> r[i];
        chkmax(r[i], 0);
        chkmax(mxy, ymm[i]);
        chkmax(mxz, zmm[i]);
    }
    FOR(i, 1, n) {
        cin >> xnn[i] >> ynn[i] >> znn[i] >> e[i];
        chkmax(mxy, ynn[i]);
        chkmax(mxz, znn[i]);
    }
    cin >> sx >> sy >> sz;
    chkmax(mxy, sy);
    chkmax(mxz, sz);
    if (mxz == 0) sub2();
    else sub3();
    return 0;
}
