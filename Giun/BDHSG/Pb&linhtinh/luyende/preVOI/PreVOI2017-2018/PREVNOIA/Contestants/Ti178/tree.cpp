#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], par[5005], pre_ans = 0, d[5005], ans = 1e15;
int x_1[55], d_1[55], a_1[55];
vector <int> v[5005];
void dfs(int u) {
    for (int i = 0; i < v[u].size(); i++) {
        int x = v[u][i];
        par[x] = u;
        dfs(x);
        d[u] += d[x];
    }
    if (!v[u].size()) d[u] = a[u];
}
void update(int u, int val) {
    d_1[u] += val;
    if (u == 1) return;
    update(par[u], val);
}
void check_1() {
   // for (int i = 1; i <= n; i++) a_1[i] = a[i];
    for (int i = 1; i <= n; i++) d_1[i] = d[i];
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (x_1[i] == 0) update(i, 1);
        else if (x_1[i] == 1) update(i, -1);
        if (x_1[i] != 2) tmp++;
    }
    for (int i = 1; i <= n; i++) tmp += abs(a[i] - d_1[i]);
    ans = min(ans, pre_ans + tmp);
}
void Try_1(int i) {
    for (int j = 0; j <= 2; j++) {
        if (v[i].size() == 0 && a[i] == 0 && j == 1) continue;
        if (v[i].size() == 0 && a[i] == 1 && j == 0) continue;
        x_1[i] = j;
        if (i == n) check_1();
        else Try_1(i + 1);
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size()) continue;
        if (a[i] > 1) {
            pre_ans += a[i] - 1;
            a[i] = 1;
        }
    }
    dfs(1);
    Try_1(1);
//    for (int i = 1; i <= n; i++) d_1[i] = d[i];
//    update(4, 1);
//    for (int i = 1; i <= n; i++) cout << d_1[i] << " ";
    cout << ans;
    return 0;
}
