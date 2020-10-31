#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define REP(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

template <class T> inline void read(T &x) {
  x = 0;
  bool flag = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) {
    flag = ch == '-';
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) {
    x = (x << 1) + (x << 3) + ch - '0';
  }
  flag ? x = - x : 0;
}

template <class T> inline void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}

const int N = 307;

int m, n, k, a[N][N];
int64_t f[N][N];

int64_t calc(int U, int V, int P, int Q, int X, int Y) {
  FOR(i, U - 1, P) FOR(j, V - 1, Q) f[i][j] = 0;
  FOR(i, U, P) FOR(j, V, Q) {
    if ((i - 1) == X && (j == Y)) {
      f[i][j] = f[i][j - 1] + a[i][j];
    } else if (i == X && (j - 1) == Y) {
      f[i][j] = f[i - 1][j] + a[i][j];
    } else {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
    }
  }
  return f[P][Q];
}

bool chk(int i, int j, int U, int V, int P, int Q) {
  if (i == U && j == V) return false;
  if (i == P && j == Q) return false;
  return true;
}
pair<int, int> id[N][N];
pair<int, int> dp(int U, int V, int P, int Q) {
  FOR(i, U, P) FOR(j, V, Q) f[i][j] = 0, id[i][j] = {i, j};
  id[U - 1][V] = {0, 0};
  id[U][V - 1] = {0, 0};
  id[U][V] = {0, 0};
  id[P][Q] = {0, 0};
  FOR(i, U, P) FOR(j, V, Q) {
    f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
    if (f[i - 1][j] == f[i][j - 1]) {
      pair<int, int> t;
      if (a[id[i - 1][j].first][id[i - 1][j].second] > a[id[i][j - 1].first][id[i][j - 1].second]) {
        t = id[i - 1][j];
      } else {
        t = id[i][j - 1];
      }
      if (a[id[i][j].first][id[i][j].second] < a[t.first][t.second]) {
        id[i][j] = t;
      }
    } else if (f[i - 1][j] > f[i][j - 1]) {
      if (a[id[i][j].first][id[i][j].second] < a[id[i - 1][j].first][id[i - 1][j].second]) {
        id[i][j] = id[i - 1][j];
      }
    } else if (f[i][j - 1] > f[i - 1][j]) {
      if (a[id[i][j].first][id[i][j].second] < a[id[i][j - 1].first][id[i][j - 1].second]) {
        id[i][j] = id[i][j - 1];
      }
    }
  }
  return id[P][Q];
}

void run() {
  read(m); read(n); read(k);
  FOR(i, 1, m) FOR(j, 1, n) read(a[i][j]);
  if (m <= 30 && n <= 30 && k <= 30) {
    int U, V, P, Q;
    while (k--) {
      read(U); read(V); read(P); read(Q);
      int64_t ans = 1e18;
      FOR(i, U, P) FOR(j, V, Q) {
        if ((i == U && j == V) || (i == P && j == Q)) continue;
        ans = min(ans, calc(U, V, P, Q, i, j));
      }
      write(ans);
      putchar('\n');
    }
  } else {
    a[0][0] = -2e9;
    while (k--) {
      int U, V, P, Q;
      read(U); read(V); read(P); read(Q);
      dp(U, V, P, Q);
      int64_t ans = f[P][Q];
      ans = min(ans, calc(U, V, P, Q, id[P][Q].first, id[P][Q].second));
      write(ans);
      putchar('\n');
    }
  }
}

int main() {
  freopen("TABLE.inp", "r", stdin);
  freopen("TABLE.out", "w", stdout);
  run();
  return 0;
}
