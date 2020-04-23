#include <bits/stdc++.h>  
#include "testlib.h"

using namespace std; 
string toString(int x) {
  string res = ""; 
  while (x > 0) {
    int r = x % 10;
    x /= 10;
    res += (char) (r + '0'); 
  } 
  reverse(res.begin(), res.end()); 
  if ((int) res.size() == 1) {
    res = "0" + res; 
  }
  return res; 
}

void print(string name, int len) {
  cout << name << ": "; 
  for (int i = 0; i < len; i++) {
    cout << rnd.next(0, 9); 
  }
  cout << endl; 
}

int main (int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("SC1.INP", "w", stdout);
  cout << 20 << endl; 
  for (int tt = 1; tt <= 20; tt++) {
    for (int i = 0; i < 6; i++) {
      cout << rnd.next(0, 9);
    }
    cout << endl; 
    print("Giai_dac_biet", 6);
    print("Giai_nhat", 5);
    print("Giai_nhi", 5);
    print("Giai_ba", 5);
    print("Giai_tu", 5);
    print("Giai_nam", 4);
    print("Giai_sau", 4);
    print("Giai_bay", 3);
    print("Giai_tam", 2);
  }
  return 0; 
}