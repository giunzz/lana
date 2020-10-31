/*
8 3
2 1 2 3 9 4 5 7
2 3 2 1 7 4 5 9
*/
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, del;
int l[4003];
int r[4003];
bool take[21];
int res = 0;
int ret[21];

void bacc(int pos) {
  if (pos == n+1) {
    int itb = 1;
    int cur1, cur2;
    cur1 = 0; cur2 = 0;
    for (int i = 1; i <= n; i++) {
      if (take[i]) {
        cur1++;
        while (itb <= n) {
          if (r[itb] != l[i]) {
            itb++;
          }
          else {
            cur2++;
            itb++;
            break;
          }
        }
      }
    }
    if (cur1 == cur2) {
      res = max(res, cur1);
    }
    return;
  }
  bacc(pos+1);
  take[pos] = true;
  bacc(pos+1);
  take[pos] = false;
}

void trace(int pos) {
  if (pos == n+1) {
    int itb = 1;
    int cur1, cur2;
    cur1 = 0; cur2 = 0;
    for (int i = 1; i <= n; i++) {
      if (take[i]) {
        cur1++;
        while (itb <= n) {
          if (r[itb] != l[i]) {
            itb++;
          }
          else {
            cur2++;
            itb++;
            break;
          }
        }
      }
    }
    if (res == cur1 && cur1 == cur2) {
      int cur = 0;
      bool triggered = false;
      for (int i = 1; i <= n; i++) {
        if (take[i]) {
          cur++;
          if (ret[cur] < l[i] || triggered) {
            triggered = true;
            ret[cur] = l[i];
          }
          if (!triggered && ret[cur] > l[i]) {
            break;
          }
        }
      }
    }
    return;
  }
  trace(pos+1);
  take[pos] = true;
  trace(pos+1);
  take[pos] = false;
}

int dp[3003];

signed main() {
  freopen("LIONDANCE.inp", "r", stdin);
  freopen("LIONDANCE.out", "w", stdout);
  scanf("%d%d", &n, &del);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &r[i]);
  }
  if (n <= 20) {
    bacc(1);
    cout << res << '\n';
    trace(1);
    for (int i = 1; i <= res; i++) {
      cout << ret[i] << ' ';
    }
    return 0;
  }
  else {

  }
}
