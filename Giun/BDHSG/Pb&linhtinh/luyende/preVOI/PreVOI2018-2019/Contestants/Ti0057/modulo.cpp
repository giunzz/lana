#include <bits/stdc++.h>

using namespace std;

int d[2];
int n;
long long k;

unsigned long long mod;

pair<long long, int> a[1 << 20], b[1 << 20];

void solve1() {
  int m = n / 2;
  int na = 1 << m, nb = 1 << n - m;
  for (int mask = 0; mask < na; ++mask) {
    long long modulo = 0;
    for (int i = 0; i < m; ++i) {
      modulo = (modulo * 10 + d[mask >> i & 1]) % mod;
    }
    a[mask] = {modulo, mask};
  }
  for (int mask = 0; mask < nb; ++mask) {
    long long modulo = 0;
    for (int i = 0; i < n - m; ++i) {
      modulo = (modulo * 10 + d[mask >> i & 1]) % mod;
    }
    b[mask] = {modulo, mask};
  }
  sort(b, b + nb);
  for (int i = 0; i < na; ++i) {
    long long modulo = a[i].first;
    for (int j = 0; j < n - m; ++j) {
      modulo = modulo * 10 % mod;
    }
    modulo = (k + mod - modulo) % mod;
    int j = lower_bound(b, b + nb, make_pair(modulo, 0)) - b;
    if (j < nb && b[j].first == modulo) {
      for (int k = 0; k < m; ++k) {
        printf("%d", d[a[i].second >> k & 1]);
      }
      for (int k = 0; k < n - m; ++k) {
        printf("%d", d[b[j].second >> k & 1]);
      }
      putchar('\n');
      return;
    }
  }
  puts("-1");
}

const int maxn = 63;

unsigned long long p[maxn];
unordered_set<long long> f[maxn];

inline unsigned long long mul(unsigned long long a, int b) {
  unsigned long long res = 0;
  while (b) {
    if (b & 1) {
      res = (res + a) % mod;
    }
    b >>= 1, a = (a + a) % mod;
  }
  return res;
}

bool attempt(int i, long long k) {
  if (i == n) {
    return k == ::k;
  }
  if (f[i].count(k)) {
    return false;
  }
  f[i].insert(k);
  if (attempt(i + 1, (k + mul(p[i], d[0])) % mod)) {
    printf("%d", d[0]);
    return true;
  }
  if (attempt(i + 1, (k + mul(p[i], d[1])) % mod)) {
    printf("%d", d[1]);
    return true;
  }
  return false;
}

void solve2() {
  for (int i = p[0] = 1; i < n; ++i) {
    p[i] = mul(p[i - 1], 10);
  }
  if (!attempt(0, 0)) {
    puts("-1");
  }
}

int main() {
  freopen("modulo.inp", "r", stdin);
  freopen("modulo.out", "w", stdout);
  scanf("%d%d", d, d + 1);
  scanf("%d%lld", &n, &k), mod = 1LLU << n;
  if (n <= 40) {
    solve1();
  } else {
    solve2();
  }
  return 0;
}
