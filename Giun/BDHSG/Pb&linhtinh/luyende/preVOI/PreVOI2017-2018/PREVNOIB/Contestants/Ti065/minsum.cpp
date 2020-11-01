#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll A, B, re1, re2;
int t = 0;
int T;
const int nmax = 100000 + 7;
const ll oo = 1000000000 + 7;
bool c[nmax], ind = true;
ll max_ = oo;

void snt() {
  memset(c, true, sizeof(c));
  c[1] = false;
  for (int i = 2;i <= nmax;++ i) {
    if (c[i]) {
      int k = 2;
      while (i * k <= nmax) {
        c[i * k] = false;
        k ++;
      }
    }
  }
}

bool check(ll a, ll b) {
  if (a == 1 && c[b]) return true;
  if (b == 1 && c[a]) return true;
  if (c[a] && c[b]) return true;
  return false;
}

void input() {
  cin >> T;
}

void rek(ll A, ll B) {
  ++ t;
  if (t == 1000) return;
//  cout << A << " " << B << "\n";
  if (check(A, B)) {
    cout << A << " " << B << "\n";
    ind = true;
    return;
  }
  else {
    ll gc = __gcd(A, B);
    if (A < B) swap(A, B);
    if (gc != 1) {
      if (A / gc + B / gc < max_) {
        re1 = A / gc, re2 = B / gc;
        max_ = re1 + re2;
        rek(A / gc, B / gc);
      }
    }
    else {
      for (int i = 2;i <= sqrt(A);++ i) {
        if (A % i == 0) {
          if (A / i + B * i < max_) {
            re1 = A / i, re2 = B * i;
            max_ = A / i + B * i;
            rek(A / i, B * i);
          }
          if (A / (A / i) + B * (A / i) < max_) {
            re1 = A / (A / i), re2 = B * (A / i);
            max_ = A / (A / i) + B * (A / i);
            rek(A / (A / i), B * (A / i));
          }
        }
      }
      for (int i = 2;i <= sqrt(B);++ i) {
        if (B % i == 0) {
          if (B / i + A * i < max_) {
            max_ = B / i + A * i;
            re1 = B / i, re2 = A * i;
            rek(B / i, A * i);
          }
          if (B / (B / i) + A * (B / i) < max_) {
            max_ = B / (B / i) + A * (B / i);
            re1 = B / (B / i), re2 = A * (B / i);
            rek(B / (B / i), A * (B / i));
          }
        }
      }
      if (A / A + B * A < max_) {
        max_ = A / A + B * A;
        re1 = A / A, re2 = A * B;
        rek(A / A, B * A);
      }
//      if (B / B + B * A < max_) {
//        max_ = B / B + B * A;
//        re2 = 1, re1 = B * A;
//        rek(B / B, A * B);
//      }
    }
  }
}

void solve() {
  while (T --) {
    cin >> A >> B;
    if (A > 100000 || B > 100000) {
      cout << A << " " << B << "\n";
      continue;
    }
    max_ = oo;
    ind = false;
    rek(A, B);
    if (ind == false) cout << re1 << " " << re2 << "\n";
  }
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  freopen("minsum.inp", "r", stdin);
  freopen("minsum.out", "w", stdout);
  snt();
  input();
  solve();
  return 0;
}
