#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int n, m, m5, m1, m2;
int res = 0;

void bacc(int pos, int cur1, int cur2, int cur50) {
  if (pos == n+1) {
    res++;
    if (res > mod) res -= mod;
    return;
  }
  if (cur50 > 0 && cur1 < m) {
    bacc(pos+1, cur1+1, cur2, cur50-1);
  }
  if (cur50 > 0 && cur1 > 0 && cur2 < m) {
    bacc(pos+1, cur1-1, cur2+1, cur50-1);
  }
  if (!cur1 && cur50 > 2 && cur2 < m) {
    bacc(pos+1, cur1, cur2+1, cur50-3);
  }
  if (cur50 < m) {
    bacc(pos+1, cur1, cur2, cur50+1);
  }
}

signed main() {
  freopen("ICECREAM.inp", "r", stdin);
  freopen("ICECREAM.out", "w", stdout);
  scanf("%d%d%d%d%d", &n, &m, &m5, &m1, &m2);
  if (n <= 15) {
    bacc(1, m1, m2, m5);
    cout << res;
  }
  else {
    bacc(1, m1, m2, m5);
  }
}
