#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {

  registerGen(argc, argv, 1);

  int n = opt<int>("n");
  int m = opt<int>("m");

  vector<int> perm(n);
  for(int i = 0; i < n; ++i) perm[i] = i;
  shuffle(perm.begin(), perm.end());

  println(n, m);
  for(int i = 1; i < n; ++i) {
    int u = perm[i] + 1;
    int v = perm[rnd.next(0, i - 1)] + 1;
    if(rnd.next(0, 1)) v = perm[rnd.next(0, (i - 1) / 5)] + 1;
    if(rnd.next(0, 1)) println(u, v);
    else println(v, u);
  }

  return 0;
}
