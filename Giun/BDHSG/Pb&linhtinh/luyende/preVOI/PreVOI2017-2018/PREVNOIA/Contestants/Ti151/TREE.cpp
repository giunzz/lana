#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5555;

int n;
int a[maxn], b[maxn];
vector <int> adj[maxn];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int dfs(int u, int p) {
    int cost = 0, sum = 0; bool ok = 0;
    for (int i = 0; i < (int) adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        cost += dfs(v, u);
        sum += b[v];
        ok = 1;
    }
    if (ok) {
        cost += abs(sum - b[u]);
        b[u] = sum;
    }
    return cost;
}

void sub1() {
    int cnt = 0;
    vector <int> leaf;
    for (int i = 1; i <= n; ++i) if (adj[i].size() == 1 && i != 1) {
        cnt++;
        leaf.push_back(i);
        //cerr << i << "\n";
    }
    int ans = 1e9 + 7;
    for (int x = 0; x < 1 << cnt; ++x) {
        for (int i = 1; i <= n; ++i) b[i] = a[i];
        int cur = 0;
        for (int i = 0; i < cnt; ++i) {
            cur += abs(b[leaf[i]] - (x >> i & 1));
            b[leaf[i]] = x >> i & 1;
        }
        cur += dfs(1, 1);
        ans = min(ans, cur);
    }
    printf("%d\n", ans);
}

void process() {
    if (n <= 300) {
        sub1();
    }
}

int main() {
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);

    load();
    process();

    return 0;
}
