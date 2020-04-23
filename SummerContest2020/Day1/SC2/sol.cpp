#include <bits/stdc++.h> 

using namespace std;

int calc(int n, int x) {
  int res = 0; 
  for (int i = 1; i <= n; i *= x) {
    res += n / i; 
  }
  return res; 
}

int main () {
  freopen("SC2.INP", "r", stdin);
  freopen("SC2.OUT", "w", stdout);
  int test; 
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    int n, k;
    cin >> n >> k;
    int res = min(calc(n, 2) - calc(n - k, 2) - calc(k, 2), calc(n, 5) - calc(n - k, 5) - calc(k, 5));
    cout << res << endl; 
  }
  return 0; 
}