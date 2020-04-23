#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("SC5.INP", "w", stdout); 
  cout << 20 << endl; 
  for (int tt = 1; tt <= 20; tt++) {
    int n = rnd.next(1, 100000); 
    int a = rnd.next(1, 100000);
    int b = rnd.next(1, 100000); 
    cout << n << ' ' << a << ' ' << b << endl; 
  }
  return 0; 
}