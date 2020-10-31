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

const int N = 4e3 + 2;

int x[25], arrans[25], L[N], R[N], arres[25];
int n, delta, ans = 0;

void solve() {
  int j = 0, res = 0, pre = 0;
  FOR(i, 1, n) {
    if ((x[i] == 1) && ((pre == 0) || (pre > 0 && abs(L[i] - pre) <= delta))) {
      int t = j;
      while (j <= n && R[j] != L[i]) {
        ++j;
      }
      if (j == n + 1) return;
      if (j == t) return;
      arres[++res] = L[i];
      pre = L[i];
    }
  }
  if (res > ans) {
    ans = res;
    FOR(i, 1, ans) {
      arrans[i] = arres[i];
    }
  } else if (res == ans) {
    FOR(i, 1, ans) {
      if (arrans[i] > arres[i]) return;
    }
    FOR(i, 1, ans) {
      arrans[i] = arres[i];
    }
  }
  return;
}

void backtrack(int g) {
  if (g > n) {
    solve();
    return;
  }
  FOR(i, 0, 1) {
    x[g] = i;
    backtrack(g + 1);
  }
  return;
}

void run() {
  read(n);
  read(delta);
  FOR(i, 1, n) read(L[i]);
  FOR(i, 1, n) read(R[i]);
  L[0] = 0;
  R[0] = 0;
  if (n <= 20) {
    backtrack(1);
    write(ans);
    putchar('\n');
    FOR(i, 1, ans) {
      write(arrans[i]);
      putchar(' ');
    }
    return;
  }
}

int main() {
  freopen("LIONDANCE.inp", "r", stdin);
  freopen("LIONDANCE.out", "w", stdout);
  run();
  return 0;
}
