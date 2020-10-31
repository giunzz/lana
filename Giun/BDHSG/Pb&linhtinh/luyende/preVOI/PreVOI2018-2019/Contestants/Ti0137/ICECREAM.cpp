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

const int mod = 1e9 + 9;
int ans = 0;
int x[30];
int n, mmax, m50, m1, m2;

void solve() {
  int M50 = m50, M1 = m1, M2 = m2;
  FOR(i, 1, n) {
    if (x[i] == 1) {
      if (M50 + 1 <= mmax) {
        M50++;
        continue;
      } else {
        return;
      }
    } else if (x[i] == 2) {
      if (M1 + 1 <= mmax && M50 > 0) {
        M1++;
        M50--;
        continue;
      } else {
        return;
      }
    } else if (x[i] == 3) {
      if (M2 + 1 <= mmax && M1 > 0 && M50 > 0) {
        M2++;
        M1--;
        M50--;
        continue;
      } else if (M2 + 1 <= mmax && M50 >= 3) {
        M2++;
        M50 -= 3;
        continue;
      } else {
        return;
      }
    }
  }
  ++ans;
  if (ans >= mod) ans %= mod;
  return;
}

void backtrack(int g) {
  if (g > n) {
    solve();
    return;
  }
  FOR(i, 1, 3) {
    x[g] = i;
    backtrack(g + 1);
  }
  return;
}

void run() {
  read(n);
  read(mmax);
  read(m50);
  read(m1);
  read(m2);
  if (n <= 15 && mmax <= 10) {
    backtrack(1);
    write(ans);
    return;
  }
}

int main() {
  freopen("ICECREAM.inp", "r", stdin);
  freopen("ICECREAM.out", "w", stdout);
  run();
  return 0;
}
