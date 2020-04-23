#include <bits/stdc++.h>

using namespace std;

long long POW(long long x, long long n, long long MOD) {
  if (n == 0) {
    return 1LL; 
  }
  long long tmp = POW(x, n >> 1, MOD); 
  (tmp *= tmp) %= MOD; 
  if (n & 1) {
    (tmp *= x) %= MOD; 
  }
  return tmp; 
}

long long calc(long long x, long long n, long long MOD) {
  long long res = 0LL;
  if (n == 0) {
    return 1LL; 
  }
  if (n % 2 == 0) {
    (res += POW(x, n, MOD)) %= MOD;
    (res += calc(x, n - 1, MOD)) %= MOD; 
  }  
  else {
    long long mul = (1 + POW(x, n / 2 + 1, MOD)) % MOD; 
    (mul *= calc(x, n / 2, MOD)) %= MOD;
    res = mul;  
  }
  return res; 
}

int main () {
  freopen("SC4.INP", "r", stdin);
  freopen("SC4.OUT", "w", stdout); 
  int test; 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    long long x, n, M;
    cin >> x >> n >> M;
    cout << calc(x, n, M) << endl; 
  }
  return 0; 
}