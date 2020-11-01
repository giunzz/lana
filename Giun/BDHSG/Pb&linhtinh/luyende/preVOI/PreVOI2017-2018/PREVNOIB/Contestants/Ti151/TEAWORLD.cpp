#include <bits/stdc++.h>
#define sz(v) (int) v.size()
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const int maxn = 2222;

struct ball {
    int x, y, z, r;
    void input() { scanf("%d%d%d%d", &x, &y, &z, &r); }
    bool operator < (const ball &p) { return x < p.x || (x == p.x && (y < p.y || y == p.y && z < p.z)); }
};

struct store {
    int x, y, z, e;
    void input() { scanf("%d%d%d%d", &x, &y, &z, &e); }
    bool operator < (const store &p) { return x < p.x || (x == p.x && (y < p.y || y == p.y && z < p.z)); }
};

struct node {
    int x, id, type;
    node() {}
    node (int x, int id, int type) : x(x), id(id), type(type) {}
    bool operator < (const node &p) { return x < p.x || x == p.x && type < p.type; }
};

int m, n, k, xs, ys, zs, timer;
int f[maxn], mark[maxn];
store stores[22];
ball balls[2222];
vector <int> intersect[maxn];
vector <node> c;

void load() {
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; ++i) balls[i].input();
    for (int i = 1; i <= n; ++i) stores[i].input();
    scanf("%d%d%d", &xs, &ys, &zs);
}

int getL(int pos, int has) {
    if (has < 0 || pos < 0) return 0;
    if (c[pos].type == 0) {
        if (mark[c[pos].id] != timer && has <= 0) return 0;
        has -= mark[c[pos].id] != timer;
        mark[c[pos].id] = timer;
        return getL(pos - 1, has);
    } else return stores[c[pos].id].e + getL(pos - 1, has);
}

int getR(int pos, int has) {
    if (has < 0 || pos >= sz(c)) return 0;
    if (c[pos].type == 0) {
        if (mark[c[pos].id] != timer && has <= 0) return 0;
        has -= mark[c[pos].id] != timer;
        mark[c[pos].id] = timer;
        return getR(pos + 1, has);
    } else return stores[c[pos].id].e + getR(pos + 1, has);
}

void sub1() {
    for (int i = 1; i <= m; ++i) {
        c.push_back(node(balls[i].x - balls[i].r, i, 0));
        c.push_back(node(balls[i].x + balls[i].r, i, 0));
    }
    for (int i = 1; i <= n; ++i) {
        c.push_back(node(stores[i].x, i, 1));
    }
    c.push_back(node(xs, 0, 2));
    sort(c.begin(), c.end());
    int id = 0;
    REP(i, sz(c)) if (c[i].x == xs && c[i].id == 0 && c[i].type == 2) {
        id = i;
        break;
    }
    int ans = 0;
    for (int l = 0; l <= k; ++l) {
        timer++;
        int x = l, y = k - l;
        if (id > 1 && c[id - 1].type == 0 && balls[c[id - 1].id].x <= xs && balls[c[id - 1].id].x + balls[c[id - 1].id].r >= xs) {
            x++; y--;
        }
        if (id < sz(c) - 1 && c[id + 1].type == 0 && balls[c[id + 1].id].x > xs && balls[c[id + 1].id].x - balls[c[id + 1].id].r <= xs) {
            y++; x--;
        }
        ans = max(ans, getL(id - 1, x) + getR(id + 1, y));
    }
    printf("%d\n", ans);
}

bool ok(int x) {
    int cnt = 0; timer++;
    for (int i = 1; i <= n; ++i) if (x >> (i - 1) & 1) {
        for (int j = 0; j < sz(intersect[i]); ++j) if (mark[intersect[i][j]] != timer) {
            cnt++;
            mark[intersect[i][j]] = timer;
        }
    }
    return cnt <= k;
}

void sub2() {
    for (int i = 1; i <= n; ++i) {
        int A = ys - stores[i].y, B = stores[i].x - xs, C = - A * xs - B * ys;
        for (int j = 1; j <= m; ++j) {
            double dist = (A * xs + B * ys + C) / (abs(A) + abs(B));
            if (dist <= 1.0 * balls[j].r * balls[j].r) {
                intersect[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int x = 1; x < 1 << n; ++x) if (ok(x)) {
        int cur = 0;
        for (int i = 0; i < n; ++i) cur += stores[i + 1].e;
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
}
void sub3() {

}

void process() {
    bool oky = 0, okz = 0;
    for (int i = 1; i <= m; ++i) {
        if (balls[i].y > 0) oky = 1;
        if (balls[i].z > 0) okz = 1;
    }
    if (ys > 0) oky = 1;
    if (zs > 0) okz = 1;
    if (!oky && !okz) sub1();
    else if (!okz) sub2();
    else sub3();
}

int main() {
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);

    load();
    process();

    return 0;
}
