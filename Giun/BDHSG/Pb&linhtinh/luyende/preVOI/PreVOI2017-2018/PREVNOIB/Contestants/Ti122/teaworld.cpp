#include <bits/stdc++.h>
#define FOR(i, a, b)    for (int i = a; i <= b; ++i)
#define LL              long long
#define BIT(x, t)       (((x) >> (t - 1)) & 1)
#define ii              pair <int, int>
#define x               first
#define y               second
using namespace std;
void cass() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
}
const int N = 16, M = 2e3 + 3;
int m, n, k;
struct ds {
    int x, y, z, r;
    ds() {}; ds(int x, int y, int z, int r) : x(x), y(y), z(z), r(r) {};
} A[M], B[N], gs;
int ins[M][N];

bool ok1() {
    FOR(i, 1, n) if (B[i].y != 0 || B[i].z != 0) return false;
    FOR(i, 1, m) if (A[i].y != 0 || A[i].z != 0) return false;
    return true;
}
bool ok2() {
    FOR(i, 1, n) if (B[i].z != 0) return false;
    FOR(i, 1, m) if (A[i].z != 0) return false;
    return true;
}

void sub1() {
    FOR(i, 1, m) FOR(j, 0, n)
        if (A[i].x - A[i].r <= B[j].x && B[j].x <= A[i].x + A[i].r) ins[i][j] = 1;
    LL ans = 0;
    FOR(mask, 1, (1 << n) - 1) {
        int dem = 0;
        FOR(i, 1, m) {
            FOR(j, 1, n)
                if (BIT(mask, j) && (ins[i][0] != ins[i][j])) { ++ dem; break; }
        }
        if (dem > k) continue;
        LL sum = 0;
        FOR(j, 1, n) sum += BIT(mask, j) * B[j].r;
        ans = max(ans, sum);
    }
    cout << ans;
}

int ccw(ii a, ii o, ii b) {
    return (o.x - a.x) * (b.y - o.y) - (o.y - a.y) * (b.x - o.x);
}
LL sqr(int x) { return 1LL * x * x; }
bool cut(int i, int j) {
    //cerr << ins[i][0] << ' ' << ins[i][j] << '\n';
    ii s = ii(A[i].x, A[i].y), t = ii(B[j].x, B[j].y), q = ii(B[0].x, B[0].y);
    //cerr << s.x << ' ' << s.y << ' ' << t.x << ' ' << t.y << ' ' << q.x << ' ' << q.y << '\n';
    LL sqrS = sqr(ccw(s, t, q));
    LL canh = sqr(B[j].x - B[0].x) + sqr(B[j].y - B[0].y);
    //cerr << sqrS << ' ' << canh << ' ' << sqr(A[i].r) << ' ';
    if (canh == 0 || sqrS == 0) return false;
    return sqrS/(double) canh <= (double) sqr(A[i].r);
}
void sub2() {
    FOR(i, 1, m) FOR(j, 0, n)
        if (sqr(A[i].r) >= sqr(A[i].x - B[j].x) + sqr(A[i].y - B[j].y)) ins[i][j] = 1;
    LL ans = 0;

    FOR(mask, 1, (1 << n) - 1) {
        int dem = 0;
        FOR(i, 1, m) {
            FOR(j, 1, n)
                if (BIT(mask, j) && (ins[i][0] != ins[i][j] || (!ins[i][0] && !ins[i][j] && cut(i, j)))) {
                    ++ dem; break;
                }
        }
        if (dem > k) continue;
        LL sum = 0;
        FOR(j, 1, n) sum += BIT(mask, j) * B[j].r;
        ans = max(ans, sum);
    }
    cout << ans;
}

void sol() {
    cin >> m >> n >> k;
    int x, y, z, r;
    FOR(i, 1, m) cin >> x >> y >> z >> r, A[i] = ds(x, y, z, r);
    FOR(i, 1, n) cin >> x >> y >> z >> r, B[i] = ds(x, y, z, r);
    cin >> x >> y >> z, gs = B[0] = ds(x, y, z, 0);

    if (ok1()) sub1();
    else if (ok2()) sub2();
}

int main() {
    cass(); sol();
}
