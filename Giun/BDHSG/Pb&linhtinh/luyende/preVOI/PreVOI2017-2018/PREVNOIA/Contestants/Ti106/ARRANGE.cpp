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

const int maxn = 100000 + 15;

int n;
long a[maxn], s[maxn], m, b[maxn];

long sub1(int n, long a[]) {
    if (n == 0) return 0;
    long sum = 0;
    long avg = 0;
    FOR(i, 1, n) {
        sum += a[i];
        s[i] = s[i - 1] + a[i];
    }
    if (sum % n != 0) return LINF;
    avg = sum / n;
    long ret = 0;
    FOR(i, 1, n) {
        if (a[i] < avg) {
            long need = avg - a[i];
            FOR(j, i + 1, n) if (s[j] - s[i] >= need) {
                FOR(k, i + 1, j - 1) {
                    ret += 1LL * (k - i) * a[k];
                    need -= a[k];
                    a[k] = 0;
                }
                a[j] -= need;
                ret += 1LL * (j - i) * need;
                break;
            }
        }
        if (a[i] > avg) {
            long have = a[i] - avg;
            a[i + 1] += have;
            a[i] = avg;
            ret += have;
        }
    }
    return ret;
}

long sub2() {
    long ret = LINF;
    long sum = 0;
    FOR(i, 1, n) sum += a[i];
    FOR(k, 1, n) {
        if ((sum + k) % n == 0) {
            long x = (sum + k) / n - 1;
            m = 0;
            FOR(i, 1, k) b[++m] = a[i];
            long tmp = sub1(m, b);
            m = 0;
            FOR(i, k + 1, n) b[++m] = a[i];
            tmp += sub1(m, b);
            chkmin(ret, tmp);
        }
    }
    return ret;
}

int main() {
    freopen("ARRANGE.INP", "r", stdin);
    freopen("ARRANGE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    long sum = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n == 0) cout << sub1(n, a);
    else {
        long ans = sub2();
        reverse(a + 1, a + 1 + n);
        chkmin(ans, sub2());
        cout << ans;
    }
    return 0;
}
