#include <bits/stdc++.h>

using namespace std;

int main () {
  freopen("SC4.INP", "r", stdin);
  freopen("output.txt", "w", stdout); 
  int test; 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    long long x, n, M;
    cin >> x >> n >> M;
    long long res = 0LL;
    long long mul = 1LL;
    for (int i = 1; i <= n; i++) {
      (res += mul) %= M;
      (mul *= x) %= M;   
    } 
    (res += mul) %= M;
    cout << res << endl;
  }
  return 0; 
}