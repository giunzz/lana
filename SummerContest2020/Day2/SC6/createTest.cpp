#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("SC6.INP", "w", stdout); 
  cout << 20 << endl; 
  for (int tt = 1; tt <= 20; tt++) {
    int n = rnd.next(2, 30);
    int p = rnd.next(0, 1); 
    cout << n << ' ' << p << endl; 
    for (int i = 1; i <= n; i++) {
      cout << rnd.next(0, 1) << ' '; 
    }
    cout << endl;
  }
  return 0; 
}