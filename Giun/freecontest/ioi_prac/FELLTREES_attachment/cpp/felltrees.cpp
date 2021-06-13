#include "felltrees.h"

std::vector<int> fell_trees(int n, int q,
                            std::vector<int> x,
                            std::vector<int> h,
                            std::vector<int> l,
                            std::vector<int> r) {
  std::vector<int> answer(q);
  for (int i = 0; i < q; ++i) {
    answer[i] = 0;
  }
  return answer;
}
