#include "felltrees.h"
#include <bits/stdc++.h>
using namespace std;
std::vector<int> fell_trees(int n, int q,
                            std::vector<int> x,
                            std::vector<int> h,
                            std::vector<int> l,
                            std::vector<int> r) {
  std::vector<int> answer(q);
  vector<int> tmp ; 
  for (int i = 0; i < q; ++i) 
  {
    tmp.clear();
    for (int j = l[i] ; j < r[i] ; j++)
    {
      if ( (x[j] - h[j] < x[j-1]) || (x[j-1] < x[j] + h[j] ) )
      {
        answer[i]++;
        int u = tmp.front();    
        while (u > 1) 
        {
          if((x[u] - h[u] < x[u-1]) || (x[u-1] < x[u] + h[u]) )
          {
            answer[i]++ , tmp.pop_back();
            break;
          } 
          u--;
        }
      }
      else tmp.push_back(i);
    }
  }
  return answer;
}
