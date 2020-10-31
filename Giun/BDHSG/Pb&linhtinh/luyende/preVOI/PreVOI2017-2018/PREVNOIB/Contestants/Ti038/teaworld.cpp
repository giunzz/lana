#include <bits/stdc++.h>

using namespace std;

#define task                        "teaworld"
#define int                         long long
#define ft							first
#define nd							second
#define left                        _left
#define right                       _right
#define FOR(i, a, b)                for(int i = a; i <= b; ++i)
#define FORD(i, a, b)               for(int i = a; i >= b; --i)
#define REP(i, a, b)                for(int i = a; i < b; ++i)
#define REPD(i, a, b)               for(int i = (int)a-1; i >= b; --i)
#define ___unique(a)                sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end())-a.begin());
#define fast                        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CLR(a, x)                   memset(a, x, sizeof a);

typedef pair < int, int > ii;
typedef long double ldb;
//--------------------------------------------------------------
inline int read()
{
    int sign = 1;
    char c;
    do
    {
        c = getchar();
        if (c == '-') sign = -sign;
    } while (c < '0' || c > '9');
    int res;
    for (res = 0; c >= '0' && c <= '9'; c = getchar()) res = res * 10 + (c - '0');
    return res * sign;
}
void write(long long x)
{
    if (x < 0) { putchar('-'); write(abs(x)); }
    if (x > 9) write(x / 10);
    putchar(char(x % 10 + '0'));
}
//--------------------------------------------------------------
const int N = 2010;
const ldb EPS = 1e-9;
struct TVector
{
    int x, y, z, r;
    TVector(){};
    TVector(int x, int y, int z, int r = 0) : x(x), y(y), z(z), r(r) {};
} circle[N], store[N], pvh;
int m, n, k;
int res;
bool mark[N];
bool ok[N][N];

void Enter()
{
    m = read(), n = read(), k = read();
    FOR(i, 1, m)
    {
        int x, y, z, r;
        x = read(), y = read(), z = read(), r = read();
        circle[i] = {x, y, z, r};
    }
    FOR(i, 1, n)
    {
        int x, y, z, r;
        x = read(), y = read(), z = read(), r = read();
        store[i] = {x, y, z, r};
    }
    int xs, ys, zs;
    xs = read(), ys = read(), zs = read();
    pvh = {xs, ys, zs};
}
ldb bp(ldb a) { return a * a; }
ldb dist(TVector a, TVector b)
{
    ldb S = bp(a.x - b.x) + bp(a.y - b.y) + bp(a.z - b.z);
    return sqrt(S);
}
int distbp(TVector a, TVector b)
{
    int S = bp(a.x - b.x) + bp(a.y - b.y) + bp(a.z - b.z);
    return S;
}
bool inCircle(TVector a, TVector b)
{
    if (distbp(a, b) <= bp(b.r)) return true;
    return false;
}
ldb S(ldb a, ldb b, ldb c)
{
    ldb p = (a + b + c) / 2;
    p = p * (p - a) * (p - b) * (p - c);
    return p;
}
bool check(int i, int j)
{
    bool ok1 = inCircle(pvh, circle[i]), ok2 = inCircle(store[j], circle[i]);
    if (ok1 && ok2) return false;
    if (ok1 && !ok2) return true;
    if (!ok1 && ok2) return true;
    ldb AB, BC, AC;
    AB = dist(pvh, store[j]);
    AC = dist(pvh, circle[i]);
    BC = dist(store[j], circle[i]);
    ldb ss = S(AB, BC, AC);
    if (ss * 4 > bp(circle[i].r) * bp(AB)) return false;
    ldb h = ss * 4 / bp(AB);
    ldb x1 = sqrt(fabs(bp(BC) - h)), x2 = sqrt(fabs(bp(AC) - h));
    if (fabs(x1 +x2 - AB) <= EPS) return true;
    return false;
}
void backtrack(int i, int num, int now)
{
    if (num > k) return;
    if (i == n)
    {
        res = max(res, now);
        return;
    }
    int cnt = 0;
    vector < int > v;
    FOR(j, 1, m) if (ok[j][i+1] && !mark[j]) cnt ++, mark[j] = true, v.push_back(j);
    backtrack(i +1, num +cnt, now +store[i+1].r);
    REP(j, 0, v.size()) mark[v[j]] = false;
    backtrack(i +1, num, now);
}
void Solve()
{
    FOR(i, 1, m) FOR(j, 1, n)
        ok[i][j] = check(i, j);

   // FOR(i, 1, m) {
     //   cout << "check # " << i << '\n';
    //    FOR(j, 1, n) cout << j << ' ' << ok[i][j] << '\n';
    //}
    backtrack(0, 0, 0);
    write(res);
}
main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    fast;

    Enter();

    //cout << dist(pvh, circle[2]) << '\n';
    //cout << inCircle(store[1], circle[2]) << '\n';
    //cout << check(2, 1) << '\n';
    Solve();

    return 0;
}
/*1
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
/*
1 2 0
0 0 0 1
-1 0 0 5
2 0 0 100
1 0 0
*/
