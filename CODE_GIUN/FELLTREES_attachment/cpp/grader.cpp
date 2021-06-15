#include "felltrees.h"
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, q;
  assert(scanf("%d%d", &n, &q) == 2);
  vector<int> x(n), h(n), l(q), r(q);
  for (int i = 0; i < n; ++i) {
    assert(scanf("%d%d", &x[i], &h[i]) == 2);
  }
  for (int i = 0; i < q; ++i) {
    assert(scanf("%d%d", &l[i], &r[i]) == 2);
  }
  fclose(stdin);

  vector<int> answer = fell_trees(n, q, x, h, l, r);
  for (size_t i = 0; i < answer.size(); ++i) {
    printf("%d\n", answer[i]);
  }
  fclose(stdout);

  return 0;
}