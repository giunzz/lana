#include <bits/stdc++.h> 

using namespace std;

int main () {
  freopen("SC2.INP", "r", stdin); 
  freopen("output.txt", "w", stdout); 
  int test; 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    int n, k; 
    cin >> n >> k; 
    long long mul = 1LL;
    for (int i = 1; i <= n; i++) {
      mul *= 1LL * i; 
    }
    for (int i = 1; i <= k; i++) {
      mul /= 1LL * i;
    }
    for (int i = 1; i <= n - k; i++) {
      mul /= 1LL * i;
    }                                           
    int res = 0; 
    while (mul % 10 == 0) {
      res++;
      mul /= 10; 
    }
    cout << res << endl;
  }
  return 0; 
}