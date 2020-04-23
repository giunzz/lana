/***
  Subtask 1: T <= 5, n <= 10, r <= 3
  Subtask 2: T <= 5, n <= 100, r <= 100
  Subtask 3: T <= 1000000, n <= 1000000, r <= 10
  Subtask 4: T <= 1000000, n <= 1000000, r <= 1000000
***/

#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int maxn = 1000005;

int pcount[maxn];

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int t = opt<int>("t");
  int n = opt<int>("n");
  int r = opt<int>("r");

  int best = 0;
  for(int i = 2; i < maxn; ++i) {
    if(!pcount[i]) {
      for(int j = i; j < maxn; j += i) pcount[j]++;
    }
    if(i <= n && pcount[i] > pcount[best]) best = i;
  }

  println(t);
  for(int i = 0; i < t; ++i) {
    int a = rnd.next(0, r);
    int b = (rnd.next(0, 1) ? best : rnd.next(1, n));
    println(a, b);
  }

  return 0;
}
