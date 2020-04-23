#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("SC4.INP", "w", stdout); 
  cout << 20 << endl;
  for (int tt = 1; tt <= 20; tt++) {
    int x = rnd.next(1, 1000000000); 
    int n = rnd.next(1, 1000000000); 
    int M = rnd.next(1, 1000000000);
    cout << x << ' ' << n << ' ' << M << endl;
  }
  return 0; 
}