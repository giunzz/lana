#include <bits/stdc++.h>
#define llint long long
#define fi first
#define se second
#define db(x) cout << #x << " = " << x << endl;
using namespace std;

void openFile() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Tr___
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
#endif
}

const int maxn = 5e3 + 5;
const int maxm = 1e6 + 5;
const llint inf = 1e9 + 7;

int N;
int a[maxn];
vector<int> vertex[maxn];
int f[maxn][maxn];
int d[maxn];
//nx1: so tren moi thang <= N
//nx2: O(N^2) :))

void enter() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= N - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }
}

int dfs(int u, int p) {
    int szu = 1;
    int lef = -1, rig = -1;
    for (int v : vertex[u]) {
        if (v == p) continue;
        //dfs(v, u);

        if (lef == -1) lef = v;
        else rig = v;
    }

    if (lef != -1) {
        if (rig == -1) {
            int sl = dfs(lef, u);

            for (int i = 0; i <= sl; ++i) {
                f[u][i] = f[lef][i];
            }
            szu = sl;
        }
        else {
            int sl = dfs(lef, u), sr = dfs(rig, u);
            for (int i = 0; i <= sl; ++i) {
                for (int j = 0; j <= sr; ++j) {
                    f[u][i + j] = min(f[u][i + j], f[lef][i] + f[rig][j]);
                }
            }

            szu = sl + sr;
        }
    }

    if (lef == -1 && rig == -1) {
        f[u][0] = a[u];
        f[u][1] = abs(a[u] - 1);
    }
    else {
        for (int i = 0; i <= szu; ++i) {
            f[u][i] = f[u][i] + abs(a[u] - i);
        }
    }
    return szu;
}

void solve() {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            f[i][j] = inf;
        }
    }
    dfs(1, 0);

    int res = inf;
    for (int i = 0; i <= N; ++i) {
        res = min(res, f[1][i]);
    }
    printf("%d", res);
}

int main() {
    openFile();
    enter();
    solve();
    return 0;
}
