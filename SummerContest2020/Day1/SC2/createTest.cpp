#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("SC2.INP", "w", stdout); 
  cout << 20 << endl; 
  for (int tt = 1; tt <= 20; tt++) {
    int n = rnd.next(1, 30); 
    int k = rnd.next(1, n); 
    cout << n << ' ' << k << endl;
  }
  return 0; 
}