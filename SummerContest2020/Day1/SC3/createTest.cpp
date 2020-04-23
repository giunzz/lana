#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("SC3.INP", "w", stdout); 
  cout << 20 << endl; 
  for (int tt = 1; tt <= 20; tt++) {
    int n = rnd.next(1, 100000); 
    int m = rnd.next(1, 100000); 
    if (tt == 20) {
      n = 100000;
      m = 100000;
    }
    cout << n << ' ' << m << endl; 
    for (int i = 1; i <= n; i++) {
      int l = rnd.next(1, m); 
      int r = rnd.next(l, m); 
      cout << l << ' ' << r << endl; 
    }
  }
  return 0; 
}