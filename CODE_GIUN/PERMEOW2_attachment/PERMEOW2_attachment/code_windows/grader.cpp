#include "permeow2.h"
#include <vector>
#include <cstdio>

int main() {
  freopen()
  int n;
  scanf("%d", &n);

  std::vector<int> p(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }

  int answer = count_permutation(p);
  printf("%d\n", answer);
}
