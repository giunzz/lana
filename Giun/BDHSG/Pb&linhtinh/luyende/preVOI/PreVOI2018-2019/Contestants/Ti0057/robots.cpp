#include <bits/stdc++.h>

using namespace std;

const int maxm = (int)1e4 + 5;
const int inf = 0x3f3f3f3f;

int m, n;

struct point {
  int x, y;

  point() { }

  point(int x, int y)
  : x(x), y(y) { }

  inline void read() {
    scanf("%d%d", &x, &y);
  }

  void get(int &u, int &v) {
    u = x - y;
    v = x + y;
  }

  void get(int n, int &x1, int &y1, int &x2, int &y2) {
    point(x - n, y).get(x1, y1);
    point(x + n, y).get(x2, y2);
  }
} p[maxm];

template<typename T>
inline void minimize(T &target, const T &value) {
  if (target > value) {
    target = value;
  }
}

template<typename T>
inline void maximize(T &target, const T &value) {
  if (target < value) {
    target = value;
  }
}

bool check(int d) {
  int minx, miny, maxx, maxy;
  minx = miny = inf;
  maxx = maxy = -inf;
  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    p[i].get(d, x1, y1, x2, y2);
    minimize(minx, x1);
    minimize(miny, y1);
    maximize(maxx, x2);
    maximize(maxy, y2);
  }
  minx--, miny--;
  vector<vector<int>> a(maxx - minx + 2, vector<int>(maxy - miny + 2));
  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    p[i].get(d, x1, y1, x2, y2);
    x1 -= minx;
    x2 -= minx;
    y1 -= miny;
    y2 -= miny;
    a[x1][y1]++;
    a[x1][y2 + 1]--;
    a[x2 + 1][y1]--;
    a[x2 + 1][y2 + 1]++;
  }
  for (int i = 1; i < a.size(); ++i) {
    for (int j = 1; j < a[i].size(); ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  int x1, y1, x2, y2;
  p[m].get(n, x1, y1, x2, y2);
  x1 = max(x1, minx);
  y1 = max(y1, miny);
  x2 = min(x2, maxx + 1);
  y2 = min(y2, maxy + 1);
  x1 -= minx, x2 -= minx;
  y1 -= minx, y2 -= minx;
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      if (a[i][j] == 0) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  freopen("robots.inp", "r", stdin);
  freopen("robots.out", "w", stdout);
  scanf("%d%d", &m, &n);
  for (int i = 0; i <= m; ++i) {
    p[i].read();
  }
  int low = 0, high = 1000;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    if (check(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  printf("%d\n", high);
  return 0;
}
