#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<= b; ++i)
#define FORD(i, a, b) for (int i = a; i>=b; --i)
#define REP(i, a) for (int i = 0; i<a; ++i)
#define N 2222
#define pp pair<int, int>
#define bit(S, i) (((S) >> i) & 1)
#define IO cin.tie(NULL);cout.tie(NULL);
#define taskname "TEAWORLD"
using namespace std;
#define esp 1e-6

struct pt {
    int x, y, z, r, e;
}s[N], t[N], GS;

double f(pt a, pt vt, pt c, double x) {
    double X = x * vt.x + a.x - c.x;
    double Y = x * vt.y + a.y - c.y;
    double Z = x * vt.z + a.z - c.z;
    return sqrt(X*X+Y*Y+Z*Z);
}

double dis(pt a, pt c) {
    double X = a.x - c.x;
    double Y = a.y - c.y;
    double Z = a.z - c.z;
    return sqrt(X*X+Y*Y+Z*Z);
}

bool Straight(pt a, pt b, pt c) {
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int z1 = a.z - b.z;
    int z2 = a.z - c.z;
    return (x1 * y2 == x2 * y1) && (x1 * z2 == x2 * z1);
}
bool Cut(pt a, pt b, pt c){
    if (dis(a, c) <= c.r && dis(b, c) <= c.r) return false;
    if (dis(a, c) <= c.r || dis(b, c) <= c.r) return true;
    if (Straight(a, b, c)) {
        if (abs(dis(c, b) + dis(c, a) - dis(a, b)) <= esp) return true;
        return false;
    }
    pt vt = {b.x - a.x, b.y - a.y, b.z - a.z, 0, 0};
    double l = 0;
    double r = 1;
    REP(i, 200) {
        double m1 = (l + l + r) / 3;
        double m2 = (l + r + r) / 3;
        if (f(a, vt, c, m1) > f(a, b, c, m2)) {
            l = m1;
        } else r = m2;
    }
    return c.r - f(a, vt, c, l) >= esp;
}
bitset<N> check, bs[20];
int m, n, k;
int main() {
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    IO;
    scanf("%d %d %d", &m, &n, &k);
    REP(i, m) scanf("%d %d %d %d", &s[i].x, &s[i].y, &s[i].z, &s[i].r);
    REP(i, n) scanf("%d %d %d %d", &t[i].x, &t[i].y, &t[i].z, &t[i].e);
    scanf("%d %d %d", &GS.x, &GS.y, &GS.z);
    REP(j, n)
        REP(i, m)
         {
            if (Cut(GS, t[j], s[i]))
                bs[j].set(i);
        }
    long long ans = 0;
    REP(S, 1 << n) {
        long long energy = 0;
        check.reset();
        REP(i, n) if (bit(S, i)) {
            energy += t[i].e;
            check |= bs[i];
        }
        if (check.count() <= k) {
            ans = max(ans, energy);
        }
    }
    printf("%lld", ans);
}
