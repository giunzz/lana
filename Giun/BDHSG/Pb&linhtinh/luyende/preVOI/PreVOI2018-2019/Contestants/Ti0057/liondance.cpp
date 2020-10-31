#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000 + 5;

int n, d;
int a[maxn];
int b[maxn];

pair<int, int> f[maxn][maxn];
int g[maxn];

int main() {
  freopen("liondance.inp", "r", stdin);
  freopen("liondance.out", "w", stdout);
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  for (int i = n; i >= 1; --i) {
    int cur = 0;
    for (int j = n; j >= 1; --j) {
      f[i][j] = max(f[i + 1][j], f[i][j + 1]);
      if (a[i] == b[j]) {
        f[i][j] = max(f[i][j], {cur + 1, a[i]});
      }
      if (abs(a[i] - b[j]) <= d) {
        cur = max(cur, g[j]);
      }
      g[j] = max(g[j], f[i][j].first);
    }
  }
  int len = f[1][1].first;
  printf("%d\n", len);
  for (int i = 1, j = 1; len--; ++i, ++j) {
    int v = f[i][j].second;
    printf("%d ", v);
    while (a[i] != v) {
      i++;
    }
    while (b[j] != v) {
      j++;
    }
  }
  return 0;
}
