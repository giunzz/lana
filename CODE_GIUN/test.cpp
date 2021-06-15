#include<bits/stdc++.h>
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
    for (int j = l[i] ; j <= r[i] ; j++)
    {
      if ( (x[j] - h[j] < x[j-1]) || (x[j-1] < x[j] + h[j] ) )
      {
        if ( (x[j]-h[j] < x[0] ) || ( x[j] + h[j] > x[n-1] ) ) continue;
        answer[i]++;
        if (tmp.size() == 0) continue;
        int u = tmp.front();    
        while (u >= 1) 
        {
           if((x[u] - h[u] < x[u-1]) || (x[u-1] < x[u] + h[u]) )
          {
            answer[i]++ , tmp.pop_back();
            break;
          } 
          u--;
        }
      }
      else tmp.push_back(j);
    }
  }
  return answer;
}

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