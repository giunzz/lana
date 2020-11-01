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

const int maxn = 50000 + 15;

int n, k, mark[maxn];
long sum[maxn], d[maxn / 10][maxn / 10];
vector<pi> g[maxn];

void dfs(int u, int p, int st) {
    FOR(i, 0, sz(g[u]) - 1) {
        int v = g[u][i].fi;
        int w = g[u][i].se;
        if (v == p) continue;
        d[st][v] = d[st][u] + w;
        dfs(v, u, st);
    }
}

void calc(int st) {
    d[st][st] = 0;
    dfs(st, st, st);
}

int check(long mx) {
    FOR(i, 1, n) mark[i] = 0;
    int cnt = 0;
    FOR(u, 1, n) if (!mark[u]) {
        vector<pair<long, int> > ver;
        FOR(v, 1, n) if (u != v && !mark[v]) {
            ver.pb(mp(-d[u][v], v));
        }
        if (sz(ver) && -ver[0].fi <= mx) {
            mark[u] = 1;
            mark[ver[0].se] = 1;
            cnt++;
        }
    }
    return cnt == k / 2;
}

void sub2(long l, long r) {
    FOR(i, 1, n) calc(i);
    long ans = LINF;
    while (l <= r) {
        long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans;
}

void sub3() {
    FOR(i, 1, n) calc(i);
    long ans = LINF;
    FOR(i, 1, n) FOR(j, 1, n) if (i != j) chkmin(ans, d[i][j]);
    cout << ans;
}

int main() {
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    long l = 0;
    long r = 0;
    FOR(i, 1, n - 1) {
        int u, v, c; cin >> u >> v >> c;
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
        sum[u] += c;
        sum[v] += c;
        r += c;
    }
    if (k == n) sub2(l, r);
    else sub3();
    return 0;
}
