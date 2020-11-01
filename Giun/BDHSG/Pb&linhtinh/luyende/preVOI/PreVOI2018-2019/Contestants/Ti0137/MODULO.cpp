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

int a, b, n, x[25];
bool flag = false;
string ANS = "";
unsigned long long k, mod = 1;

void solve() {
  unsigned long long r = 0;
  FOR(i, 1, n) {
    r = r * 10 + x[i];
    if (r >= mod) r %= mod;
  }
  if (r == k) {
    flag = true;
    FOR(i, 1, n) {
      ANS = ANS + (char) (x[i] + '0');
    }
  }
  return;
}

void backtrack(int g) {
  if (flag) return;
  if (g > n) {
    solve();
    return;
  }
  FOR(i, 0, 1) {
    if (i == 0) x[g] = a;
    else if (i == 1) x[g] = b;
    backtrack(g + 1);
  }
  return;
}

struct bignum {
  int deg;
  char d[500];
};

void scan(bignum &x) {
  scanf("%s", x.d);
  int k = strlen(x.d);
  reverse(x.d, x.d + k);
  x.deg = strlen(x.d) - 1;
}

void print(bignum &x) {
  for(int i = x.deg; i >= 0; i--) printf("%c", x.d[i]);
}

int cmp(bignum x, bignum y) {
  if (x.deg < y.deg) return -1;
  if (x.deg > y.deg) return 1;
  for(int i = x.deg; i >= 0; i--) {
    if (x.d[i] < y.d[i]) return -1;
    if (x.d[i] > y.d[i]) return 1;
  }
  return 0;
}

void gan(int64_t k, bignum &x) {
  sprintf(x.d, "%d", k);
  int z = strlen(x.d);
  reverse(x.d, x.d + z);
  x.deg = strlen(x.d) - 1;
}

bignum operator + (bignum x, bignum y) {
  bignum z;
  z.deg = max(x.deg, y.deg);
  for(int i = x.deg + 1; i <= z.deg; i++) x.d[i] = '0';
  for(int i = y.deg + 1; i <= z.deg; i++) y.d[i] = '0';
  int nho = 0;
  for(int i = 0; i <= z.deg; i++) {
    int tong = x.d[i] + y.d[i] - 96 + nho;
    z.d[i] = tong % 10 + 48;
    nho = tong / 10;
  }
  if (nho) z.d[++z.deg] = '1';
  return z;
}

bignum operator * (int k, bignum x) {
  bignum z;
  z.deg = x.deg;
  int nho = 0;
  for(int i = 0; i <= z.deg; i++) {
    int tich = (x.d[i] - 48) * k + nho;
    z.d[i] = tich % 10 + 48;
    nho = tich / 10;
  }
  while (nho) {
    z.d[++z.deg] = nho % 10 + 48;
    nho /= 10;
  }
  while (z.deg && z.d[z.deg] == '0') z.deg--;
  return z;
}

bignum operator * (bignum x, bignum y) {
  bignum z;
  z.deg = x.deg + y.deg;
  for(int i = x.deg + 1; i <= z.deg; i++) x.d[i] = '0';
  for(int i = y.deg + 1; i <= z.deg; i++) y.d[i] = '0';
  int nho = 0;
  for(int k = 0; k <= z.deg; k++) {
    int tong = nho;
    for(int i = 0; i <= k; i++) tong += (x.d[i] - 48) * (y.d[k - i] - 48);
    z.d[k] = tong % 10 + 48;
    nho = tong / 10;
  }
  while (nho) {
    z.d[++z.deg] = nho % 10 + 48;
    nho /= 10;
  }
  while (z.deg && z.d[z.deg] == '0') z.deg--;
  return z;
}

void optimize() {
  bignum g, u, t, K, f;
  gan(k, K);
  gan(1, f);
  gan(1, g);
  gan(0, u);
  for (int i = 1; i <= n; ++i) g = 2 * g;
  do {
    t = g * u + K;
    if (t.deg + 1 < n) {
      u = u + f;
      continue;
    }
    if (t.deg  + 1 > n) break;
    for (int i = 0; i < t.deg; ++i) {
      if ((t.d[i] - '0') != a && ((t.d[i] - '0') != b)) {
        goto XXX;
      }
    }
    print(t);
    return;
    XXX: u = u + f;
  } while (t.deg <= n);
  cout << -1;
  return;
}

void run() {
  read(a);
  read(b);
  read(n);
  read(k);
  FOR(i, 1, n) mod *= 2;
  if (n <= 20) {
    backtrack(1);
    if (flag == false) {
      write(-1);
      return;
    }
    cout << ANS;
    return;
  } else {
    optimize();
    return;
  }
}

int main() {
  freopen("MODULO.inp", "r", stdin);
  freopen("MODULO.out", "w", stdout);
  run();
  return 0;
}
