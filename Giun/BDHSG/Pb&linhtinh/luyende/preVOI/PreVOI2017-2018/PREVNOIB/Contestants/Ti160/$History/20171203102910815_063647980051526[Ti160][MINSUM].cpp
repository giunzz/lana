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

const int maxv = 50 * 50 + 100;
const int maxn = 40000 + 15;

int t, a, b, markID, mark[maxv][maxv];
queue<pi> q;

int eratos[maxn];
vector<long> p;

void init() {
    eratos[1] = 1;
    for (int i = 2; i * i < maxn; ++i) if (!eratos[i])
        for (int j = i * i; j < maxn; j += i) eratos[j] = 1;
    FOR(i, 1, maxn - 1) if (!eratos[i]) p.pb(i);
}

map<long, int> fact(long n) {
    map<long, int> ret;
    for (int i = 0; i < sz(p) && p[i] * p[i] <= n; ++i) {
        while (n % p[i] == 0) {
            ret[p[i]]++;
            n /= p[i];
        }
    }
    if (n > 1) ret[n]++;
    return ret;
}

void solve() {
    long g = __gcd(a, b);
    a /= g;
    b /= g;
    map<long, int> va = fact(a);
    map<long, int> vb = fact(b);
    vector<long> v;
    FORall(it, va) {
        it->second %= 2;
        if (it->second == 1) v.pb(it->first);
    }
    FORall(it, vb) {
        it->second %= 2;
        if (it->second == 1) v.pb(it->first);
    }
    long mn = LINF;
    long xx = 0;
    long yy = 0;
    FOR(i, 0, sz(v) - 1) {
        long x = 1;
        long y = 1;
        FOR(j, 0, i) x *= v[j];
        FOR(j, i + 1, sz(v) - 1) y *= v[j];
        if (chkmin(mn, x + y)) {
            xx = x;
            yy = y;
        }
    }
    cout << xx << ' ' << yy << endl;
}

void add(int x, int y) {
    if (mark[x][y] < markID) {
        mark[x][y] = markID;
        q.push(mp(x, y));
    }
}

void addx(int x, int y, int d) {
    if (y % d == 0) add(x / d, y / d);
    else add(x / d, y * d);
}

void addy(int x, int y, int d) {
    if (x % d == 0) add(x / d, y / d);
    else add(x * d, y / d);
}

void sub1() {
    markID++;
    while (sz(q)) q.pop();
    q.push(mp(a, b));
    mark[a][b] = markID;
    int ans = INF;
    int xx = 0;
    int yy = 0;
    while (sz(q)) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        if (chkmin(ans, x + y)) {
            xx = x;
            yy = y;
        }
        for (int i = 1; i * i <= x; ++i) if (x % i == 0) {
            addx(x, y, i);
            addx(x, y, x / i);
        }
        for (int i = 1; i * i <= y; ++i) if (y % i == 0) {
            addy(x, y, i);
            addy(x, y, y / i);
        }
    }
    cout << xx << ' ' << yy << '\n';
}

void sub2() {
    int g = __gcd(a, b);
    int x = a / g;
    int y = b / g;
    int mn = INF;
    int xx = 0;
    int yy = 0;
    if (chkmin(mn, a + b)) {
        xx = a;
        yy = b;
    }
    if (chkmin(mn, x + y)) {
        xx = x;
        yy = y;
    }
    if (chkmin(mn, a + 1)) {
        xx = a;
        yy = 1;
    }
    if (chkmin(mn, 1 + b)) {
        xx = 1;
        yy = b;
    }
    cout << xx << ' ' << yy << '\n';
}

int main() {
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    cin >> t;
    markID = 0;
    FOR(i, 1, t) {
        cin >> a >> b;
        if (t <= 100 && a <= 50 && b <= 50) sub1();
        else solve();
    }
    return 0;
}
