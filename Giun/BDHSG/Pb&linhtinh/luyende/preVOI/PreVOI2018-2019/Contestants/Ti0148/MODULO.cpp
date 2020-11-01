/*
7 2
3 5
*/
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int a, b, n;
long long k;
long long mod;
multiset<long long> s[3];

long long rel(long long a, int b) {
  if (a + b > mod) {
    return a + b - mod;
  }
  return a + b;
}

long long mul(long long a) {
  if (1ull * a * 10 >= mod) {
    if (1ull * a * 10 == mod) return 0ll;
    return 1ull * a * 10 % mod;
  }
  return a * 10;
}

void bacc(int sta, int en, int p, long long cur) {
  if (sta == en + 1) {
    s[p].insert(cur);
    return;
  }
  bacc(sta+1, en, p, rel(mul(cur), a));
  bacc(sta+1, en, p, rel(mul(cur), b));
}

int dig[41];
bool doe[3];

void trace(int sta, int en, long long val, long long cur, int p, int ini){
  if (doe[p]) return;
  if (sta == en+1) {
    if (cur == val) {
      doe[p] = true;
      for (int i = ini; i <= en; i++) {
        cout << dig[i];
      }
    }
    return;
  }
  dig[sta] = a;
  trace(sta+1, en, val, rel(mul(cur), a), p, ini);
  dig[sta] = b;
  trace(sta+1, en, val, rel(mul(cur), b), p, ini);
}

signed main() {
  freopen("MODULO.inp", "r", stdin);
  freopen("MODULO.out", "w", stdout);
  scanf("%d%d%d%lld", &a, &b, &n, &k);
  mod = (1ll<<n);
  if (n <= 40) {
    memset(doe, false, sizeof(doe));
    bacc(1, n/2, 1, 0);
    bacc(n/2+1, n, 2, 0);
    long long ado = 1;
    for (int i = n/2+1; i <= n; i++) {
      ado = mul(ado);
    }
    long long l, r;
    l = r = -1;
    for (auto v : s[1]) {
      if (s[2].find((k + mod - ado * v % mod) % mod) != s[2].end()) {
        l = v;
        r = (k + mod - ado * v % mod) % mod;
        break;
      }
    }
    if (l == r && l == -1) {
      cout << -1;
      return 0;
    }
    trace(1, n/2, l, 0, 1, 1);
    trace(n/2+1, n, r, 0, 2, n/2+1);
    return 0;
  }
  else {
    cout << -1;
  }
}
