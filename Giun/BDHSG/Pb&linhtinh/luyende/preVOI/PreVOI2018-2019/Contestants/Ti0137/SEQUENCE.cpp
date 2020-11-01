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

const int N = 3003;

int m, n, k, a[N], b[N];

void run() {
  read(m); read(n); read(k);
  FOR(i, 1, m) read(a[i]);
  FOR(i, 1, n) read(b[i]);
  b[n + 1] = 2e9;
  if (k == m + n) {
    int i = 1, j = 1;
    FOR(z, 1, k) {
      if (i <= m && a[i] <= b[j]) {
        write(a[i]);
        ++i;
      } else {
        write(b[j]);
        ++j;
      }
      putchar(' ');
    }
    return;
  } else {
    FOR(i, 1, k) write(i), putchar(' ');
  }
  return;
}

int main() {
  freopen("SEQUENCE.inp", "r", stdin);
  freopen("SEQUENCE.out", "w", stdout);
  run();
  return 0;
}
