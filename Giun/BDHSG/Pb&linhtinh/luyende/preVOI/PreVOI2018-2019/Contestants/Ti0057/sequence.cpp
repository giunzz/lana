#include <bits/stdc++.h>

using namespace std;

const int maxm = 3000 + 5;
const int maxn = 3000 + 5;

int m, n, k;
int a[maxm];
int b[maxn];
int c[maxm + maxn];
int d[maxm + maxn];

int main() {
  freopen("sequence.inp", "r", stdin);
  freopen("sequence.out", "w", stdout);
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  memset(c, 0x3f, sizeof(c));
  vector<int> u(m + 1), v(n + 1);
  for (int x = 0; x <= m; ++x) {
    int y = k - x;
    if (0 <= y && y <= n) {
      u.clear(), v.clear();
      for (int i = 1; i <= m; ++i) {
        while (u.size() && u.back() > a[i] && u.size() + m - i >= x) {
          u.pop_back();
        }
        u.push_back(a[i]);
      }
      for (int i = 1; i <= n; ++i) {
        while (v.size() && v.back() > b[i] && v.size() + n - i >= y) {
          v.pop_back();
        }
        v.push_back(b[i]);
      }
      while (u.size() > x) {
        u.pop_back();
      }
      while (v.size() > y) {
        v.pop_back();
      }
      u.push_back(0), v.push_back(0);
      vector<int> f(x + 1), g(y + 1);
      for (int i = x - 1; i >= 0; --i) {
        f[i] = u[i] == u[i + 1] ? f[i + 1] : u[i + 1];
      }
      for (int i = y - 1; i >= 0; --i) {
        g[i] = v[i] == v[i + 1] ? g[i + 1] : v[i + 1];
      }
      for (int i = 0, j = 0, k = 0; k < ::k;) {
        if (i < x && j < y) {
          if (u[i] == v[j]) {
            if (f[i] < g[j]) {
              d[k++] = u[i++];
            } else {
              d[k++] = v[j++];
            }
          } else {
            if (u[i] < v[j]) {
              d[k++] = u[i++];
            } else {
              d[k++] = v[j++];
            }
          }
        } else {
          if (i < x) {
            d[k++] = u[i++];
          } else {
            d[k++] = v[j++];
          }
        }
      }
      bool r = false;
      for (int i = 0; i < k; ++i) {
        if (c[i] != d[i]) {
          r = c[i] > d[i];
          break;
        }
      }
      if (r) {
        for (int i = 0; i < k; ++i) {
          c[i] = d[i];
        }
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    printf("%d ", c[i]);
  }
  return 0;
}
