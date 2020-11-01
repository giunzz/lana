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

const int maxn = 1000000 + 15;

int n, k, a[maxn];
long s[maxn], f[maxn], g[maxn];

inline int readInt() {
    char c;
    int sign = 1;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -sign;
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res * sign;
}

void writeInt(long x) {
    if (x >= 10) writeInt(x / 10);
    putchar(x % 10 + '0');
}

void sub1() {
    long ans = LINF;
    FOR(i, 1, n - k + 1) {
        long tmp = -LINF;
        FOR(j, 1, i - k) chkmax(tmp, s[j + k - 1] - s[j - 1]);
        FOR(j, i + k, n - k + 1) chkmax(tmp, s[j + k - 1] - s[j - 1]);
        if (tmp != -LINF) {
            chkmin(ans, tmp);
        }
    }
    writeInt(ans);
}

void sub2() {
    f[0] = -LINF;
    FOR(i, 1, n) {
        if (i - k + 1 < 1) f[i] = -LINF;
        else f[i] = max(f[i - 1], s[i] - s[i - k]);
    }
    g[n + 1] = -LINF;
    FORd(i, n, 1) {
        if (i + k - 1 > n) g[i] = -LINF;
        else g[i] = max(g[i + 1], s[i + k - 1] - s[i - 1]);
    }
    long ans = LINF;
    FOR(i, 1, n - k + 1) {
        long tmp = max(f[i - 1], g[i + k]);
        if (tmp != -LINF) {
            chkmin(ans, tmp);
        }
    }
    writeInt(ans);
}

int main() {
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    n = readInt();
    k = readInt();
    FOR(i, 1, n) {
        a[i] = readInt();
        s[i] = s[i - 1] + a[i];
    }
    if (n <= 5000) sub1();
    else sub2();
    return 0;
}
