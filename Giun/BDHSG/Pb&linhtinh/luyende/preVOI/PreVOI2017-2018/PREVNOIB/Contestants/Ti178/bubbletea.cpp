#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, b[50005];
typedef pair <int, int> ii;
vector <ii> a[50005];
int lv[50005], M[50005][25], visit[50005], d[50005];
int val_1[20][20], x_1[20], use_1[20], ans_1 = 1e18;
void dfs(int u) {
    visit[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].second;
        int w = a[u][i].first;
        if (visit[v]) continue;
        M[v][0] = u;
        d[v] = d[u] + w;
        lv[v] = lv[u] + 1;
        dfs(v);
    }
}
void make_lca() {
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            M[i][j] = M[M[i][j - 1]][j - 1];
        }
    }
}
int lca(int u, int v) {
    for (int i = 20; i >= 0; i--) if (lv[M[u][i]] >= lv[v]) u = M[u][i];
    for (int i = 20; i >= 0; i--) if (lv[M[v][i]] >= lv[u]) v = M[v][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) {
        if (M[u][i] != M[v][i]) {
            u = M[u][i];
            v = M[v][i];
        }
    }
    return M[u][0];
}
int dis(int u, int v) {
    return d[u] + d[v] - 2 * d[lca(u, v)];
}
void solve_1() {
    int ok_1[20];
    for (int i = 1; i <= k / 2; i++) ok_1[i] = 0;
    int maxx = 0;
    for (int i = 1; i <= k; i++) {
        if (!ok_1[x_1[i]]) ok_1[x_1[i]] = i;
        else maxx = max(maxx, val_1[i][ok_1[x_1[i]]]);
    }
    ans_1 = min(ans_1, maxx);
}
void Try_1(int i) {
    for (int j = 1; j <= k / 2; j++) {
        if (use_1[j] == 2) continue;
        use_1[j]++;
        x_1[i] = j;
        if (i == k) solve_1();
        else Try_1(i + 1);
        use_1[j]--;
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("bubbletea.inp", "r", stdin);
    freopen("bubbletea.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back(ii(w, v));
        a[v].push_back(ii(w, u));
    }
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            lv[i] = 1;
            dfs(i);
        }
    }
    make_lca();
    if (k <= 10) {
        for (int i = 1; i <= k; i++) {
            for (int j = i + 1; j <= k; j++) {
                val_1[i][j] = dis(b[i], b[j]);
                val_1[j][i] = val_1[i][j];
            }
        }
        Try_1(1);
        cout << ans_1;
    }
    else {
        int minn = 1e18;
        for (int i = 1; i <= k; i++) {
            for (int j = i + 1; j <= k; j++) minn = min(minn, dis(b[i], b[j]));
        }
        cout << minn;
    }
    return 0;
}
