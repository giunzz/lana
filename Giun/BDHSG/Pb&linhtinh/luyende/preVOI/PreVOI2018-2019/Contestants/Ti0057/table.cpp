#include <bits/stdc++.h>

using namespace std;

const int maxm = 305;
const int maxn = 305;

int m, n, k;
int a[maxm][maxn];
int u, v, p, q;

int f[maxm][maxn];
int g[maxm][maxn];
int d[maxm][maxn];
int e[maxm][maxn];

void solve() {
  scanf("%d%d%d%d", &u, &v, &p, &q);
  memset(f, 0xc0, sizeof(f));
  memset(g, 0xc0, sizeof(g));
  memset(d, 0xc0, sizeof(d));
  memset(e, 0xc0, sizeof(e));
  f[u - 1][v] = g[p + 1][q] = 0;
  for (int i = u; i <= p; ++i) {
    for (int j = v; j <= q; ++j) {
      f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);
    }
  }
  for (int i = p; i >= u; --i) {
    for (int j = q; j >= v; --j) {
      g[i][j] = a[i][j] + max(g[i + 1][j], g[i][j + 1]);
    }
  }
  for (int i = p; i >= u; --i) {
    for (int j = v; j <= q; ++j) {
      d[i][j] = max(d[i + 1][j], d[i][j - 1]);
      if (i < p && j > v) {
        d[i][j] = max(d[i][j], a[i + 1][j - 1] + g[i + 1][j] + f[i][j - 1]);
      }
    }
  }
  int ans = 2e9;
  for (int i = u; i <= p; ++i) {
    for (int j = q; j >= v; --j) {
      e[i][j] = max(e[i - 1][j], e[i][j + 1]);
      if (i > u && j < q) {
        e[i][j] = max(e[i][j], a[i - 1][j + 1] + f[i - 1][j] + g[i][j + 1]);
      }
      if ((i != u || j != v) && (i != p || j != q)) {
        ans = min(ans, max(e[i][j], d[i][j]));
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  freopen("table.inp", "r", stdin);
  freopen("table.out", "w", stdout);
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  while (k--) {
    solve();
  }
  return 0;
}
