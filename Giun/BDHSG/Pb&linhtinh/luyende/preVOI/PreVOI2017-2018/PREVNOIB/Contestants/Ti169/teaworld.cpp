#include <bits/stdc++.h>
#define llint long long
#define fi first
#define se second
#define db(x) cout << #x << " = " << x << endl;
#define sqr(x) ((x) * (x))
using namespace std;

void openFile() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Tr___
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("teaworld.inp", "r", stdin);
    freopen("teaworld.out", "w", stdout);
#endif
}

const int maxn = 15 + 5;
const int maxm = 2e3 + 5;
const int inf = 1e9 + 7;
const double eps = 1e-12;

int M, N, K;
struct point {
    double x, y, z;
    void read() {
        cin >> x >> y >> z;
    }
    point() {}
    point(double x, double y, double z): x(x), y(y), z(z) {}
};
struct circle {
    point p;
    double r;

    void read() {
        p.read(); cin >> r;
    }
} C[maxm];

struct tea {
    point p;
    int e;
    
    void read() {
        p.read(); cin >> e;
    }
} T[maxm];
point s;

void enter() {
    cin >> M >> N >> K;
    for (int i = 1; i <= M; ++i) {
        C[i].read();
    }

    for (int i = 1; i <= N; ++i) {
        T[i].read();
    }
    s.read();
}

double distance(point s, point t) {
    return sqr(s.x - t.x) + sqr(s.y - t.y) + sqr(s.z - t.z);
}

double minDist(point c, point s, point t, double percent) {
    point m = s;
    m.x += (t.x - s.x) * percent / 100;
    m.y += (t.y - s.y) * percent / 100;
    m.z += (t.z - s.z) * percent / 100;

    return distance(c, m);
}

bool inside[maxn][maxm];
bool rem[maxm];
void solve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            //find mindist from C[j] to (s->T[i])

            double lef, rig;
            lef = distance(C[j].p, s);
            rig = distance(C[j].p, T[i].p);

            if (lef < sqr(C[j].r) + eps && rig < sqr(C[j].r) + eps) {
                inside[i][j] = false;
            }
            else if (lef < sqr(C[j].r) + eps) {
                inside[i][j] = true;
            }
            else if (rig < sqr(C[j].r) + eps) {
                inside[i][j] = true;
            }
            else {
                double lo = 0, hi = 100, ml, mr;
                for (int slope = 1; slope <= 500; ++slope) {
                    ml = lo + (hi - lo) / 3;
                    mr = hi - (hi - lo) / 3;
                    
                    if (minDist(C[j].p, s, T[i].p, ml) < minDist(C[j].p, s, T[i].p, mr)) {
                        hi = mr;
                    }
                    else {
                        lo = ml;
                    }
                }

                inside[i][j] = minDist(C[j].p, s, T[i].p, lo) < sqr(C[j].r) + eps;
                //cout << i << " " << j << " " << inside[i][j] << endl;
            }
        }
    }

    int res = 0;
    for (int state = 0; state < (1<<N); ++state) {
        int cur = 0;
        for (int i = 1; i <= M; ++i) rem[i] = true;

        for (int i = 1; i <= N; ++i) if ((state>>(i - 1)) & 1) {
            cur = cur + T[i].e;
            for (int j = 1; j <= M; ++j) {
                if (inside[i][j]) rem[j] = false;
            }
        }

        int sl = 0;
        for (int i = 1; i <= M; ++i) {
            sl = sl + (!rem[i]);
        }
        if (sl <= K) {
            res = max(res, cur);
        }
    }

    cout << res << endl;
}

int main() {
    openFile();
    enter();
    solve();
    return 0;
}
