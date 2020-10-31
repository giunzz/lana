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

const int maxn = 5000 + 15;
const int maxa = 5000 + 15;

int n, a[maxn], child[maxn];
long f[35][35 * maxa], ff[maxn][maxn];
vector<int> g[maxn];

void dfs(int u, int p) {
    child[u] = a[u];
    vector<int> ver;
    FOR(i, 0, sz(g[u]) - 1) {
        int v = g[u][i];
        if (v == p) continue;
        ver.pb(v);
        dfs(v, u);
        child[u] += child[v];
    }
    if (sz(ver) == 0) {
        f[u][0] = a[u];
        f[u][1] = abs(a[u] - 1);
    }
    if (sz(ver) == 1) {
        int v = ver[0];
        FOR(i, 0, child[u]) {
            chkmin(f[u][i], f[v][i] + abs(a[u] - i));
        }
    }
    if (sz(ver) == 2) {
        int v1 = ver[0];
        int v2 = ver[1];
        FOR(i, 0, child[u]) {
            FOR(x, 0, i) {
                chkmin(f[u][i], f[v1][x] + f[v2][i - x] + abs(a[u] - i));
            }
        }
    }
}

void dfs1(int u, int p) {
    child[u] = 1;
    vector<int> ver;
    FOR(i, 0, sz(g[u]) - 1) {
        int v = g[u][i];
        if (v == p) continue;
        ver.pb(v);
        dfs1(v, u);
        child[u] += child[v];
    }
    if (sz(ver) == 0) {
        ff[u][0] = a[u];
        ff[u][1] = abs(a[u] - 1);
    }
    if (sz(ver) == 1) {
        int v = ver[0];
        FOR(i, 0, child[u]) {
            chkmin(ff[u][i], ff[v][i] + abs(a[u] - i));
        }
    }
    if (sz(ver) == 2) {
        int v1 = ver[0];
        int v2 = ver[1];
        FOR(i, 0, child[u]) {
            FOR(x, 0, i) {
                chkmin(ff[u][i], ff[v1][x] + ff[v2][i - x] + abs(a[u] - i));
            }
        }
    }
}

void sub1() {
    int sum = 0;
    FOR(i, 1, n) sum += a[i];
    FOR(i, 1, n) FOR(j, 0, sum) f[i][j] = LINF;
    dfs(1, 1);
    long ans = LINF;
    FOR(i, 0, sum) {
        chkmin(ans, f[1][i]);
    }
    cout << ans;
}

void sub2() {
    FOR(i, 1, n) FOR(j, 0, n) ff[i][j] = LINF;
    dfs1(1, 1);
    long ans = LINF;
    FOR(i, 0, n) {
        chkmin(ans, ff[1][i]);
    }
    cout << ans;
}

int main() {
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int sum = 0;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    FOR(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (n <= 30) sub1();
    else sub2();
    return 0;
}
