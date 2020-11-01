#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<= b; ++i)
#define FORD(i, a, b) for (int i = a; i>=b; --i)
#define REP(i, a) for (int i = 0; i<a; ++i)
#define N 5555
#define pp pair<int, int>
#define bit(S, i) (((S) >> i) & 1)
#define IO cin.tie(NULL);cout.tie(NULL);
#define taskname "TREE"
using namespace std;

int n, a[N], cntLeaf, p[N], nLeaf[N];
vector<int> e[N];
bool isLeaf[N];

void dfs(int u) {
    isLeaf[u] = true;
    for (int v : e[u]) if (v != p[u]) {
        isLeaf[u] = false;
        p[v] = u;
        dfs(v);
        nLeaf[u] += nLeaf[v];
    }
    if (isLeaf[u]) {
        cntLeaf++;
        nLeaf[u]++;
    }
}
bool used[N];
int dp[N][N];
int cal(int u, int val) {
    if (isLeaf[u]) {
        return abs(a[u] - val);
    }
    if (used[u]) return dp[u][val];
    used[u] = true;
    int cnt = 0;
    dp[u][0] = 0;
    FOR(i, 1, nLeaf[u]) dp[u][i] = 1e9;
    int tmp[nLeaf[u] + 1];
    for (int v : e[u]) if (p[u] != v) {
        FOR(p, 0, cnt + nLeaf[v]) tmp[p] = 1e9;
        FOR(p, 0, cnt + nLeaf[v]) {
            FOR(z, 0, min(p, nLeaf[v])) {
                if (p - z > cnt || (isLeaf[v] && z > 1)) continue;
                tmp[p] = min(tmp[p], dp[u][p - z] + cal(v, z));
            }
        }
        cnt += nLeaf[v];
        FOR(p, 0, cnt) dp[u][p] = tmp[p];
    }
    FOR(p, 0, cnt) dp[u][p] += abs(a[u] - p);
    return dp[u][val];
}
int main() {
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    IO;
    scanf("%d", &n);
    int u, v;
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 2, n) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    p[1] = -1;
    cntLeaf = 0;
    dfs(1);
    int ans = cal(1, cntLeaf);
    REP(i, cntLeaf) ans = min(ans, dp[1][i]);
    printf("%d", ans);
}
