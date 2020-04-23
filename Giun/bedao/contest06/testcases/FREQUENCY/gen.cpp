/***
Subtask 1: N, Q <= 1 000
Subtask 2: N, Q <= 100,000
Subtask 3: N, Q <= 1,000,000
***/

/***
  1. Keep a fixed length, every [L, R] where R - L < length does not have an answer
  2. Keep a fixed modulo, every [L, R] where (R - L) % mod != 1 does not have an answer
  3. All randomized
***/


#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int P = 900;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  int n = opt<int>("n");
  int q = opt<int>("q");
  int wholeSeg = opt<int>("wholeSeg");

  vector<int> a(n);
  int part = n / 3;

  /// Part 1
  {
    vector<int> vals;
    for(int i = 0; i < 12; ++i) {
      vals.push_back(rnd.next(1, 100));
    }
    int len = part / 10;
    for(int i = 0; i < part; ++i) {
      a[i] = vals[i / len];
    }
  }

  /// Part 2, all randomized
  {
    for(int i = part; i < part + part; ++i) {
      a[i] = rnd.next(1, n);
    }
  }

  /// Part 3, modulo pattern
  {
    int modun = rnd.next(3, 7);
    for(int i = part + part; i < n; i += modun) {
      int w = rnd.next(1, n);
      for(int j = i; j < min(n, i + modun); ++j) a[j] = w;
    }
  }

  vector<pair<int, int>> queries;
  if(!wholeSeg) {
    for(int i = 0; i < q; ++i) {
      int l = rnd.next(1, n - n / 5);
      int r = rnd.next(l + n / 5, n);
      queries.emplace_back(l, r);
    }
  }
  else {
    assert(n == q);
    for(int i = 1; i <= n; ++i) {
      int j = max(1, i - rnd.next(n / 10, n / 5));
      queries.emplace_back(j, i);
    }
  }

  shuffle(queries.begin(), queries.end());

  println(n);
  println(a);
  println(q);
  for(auto t : queries) println(t.first, t.second);


  return 0;
}
