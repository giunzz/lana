/*
7 4 11
1 2 1 3 1 2 1
1 2 3 1
*/
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int m, n, k, cur;
int a[3003], b[3003];
vector<int> na[3003], nb[3003];
int ret[6003];

void merge(vector<int> a, vector<int> b) {
  vector<int> ne;
  bool triggered = false;
  int ita, itb;
  ita = itb = 0;
  int cur = 0;
  while (ita < a.size() && itb < b.size()) {
    if (a[ita] > b[itb]) {
      ne.push_back(b[itb]);
      itb++;
    }
    else {
      if (a[ita] < b[itb]) {
        ne.push_back(a[ita]);
        ita++;
      }
      else {
        int l = ita;
        int r = itb;
        while (a[l] == b[r]) {
          l++;
          r++;
          if (l == a.size() || r == b.size()) break;
          if (a[l] == b[r]) {
            if (a[l] > a[l-1]) break;
          }
        }
        if (l == a.size()) {
          ne.push_back(b[itb]);
          itb++;
          continue;
        }
        if (r == b.size()) {
          ne.push_back(a[ita]);
          ita++;
          continue;
        }
        if (a[l] > b[r]) {
          ne.push_back(b[itb]);
          itb++;
          continue;
        }
        ne.push_back(a[ita]);
        ita++;
      }
    }
    if (ne[cur] < ret[cur+1] || triggered) {
      triggered = true;
      ret[cur+1] = ne[cur];
    }
    if (ne[cur] > ret[cur+1] && !triggered) {
      return;
    }
    cur++;
  }
  if (ita < a.size()) {
    for (int i = ita; i < a.size(); i++) {
      ne.push_back(a[i]);
    }
  }
  if (itb < b.size()) {
    for (int i = itb; i < b.size(); i++) {
      ne.push_back(b[i]);
    }
  }
  for (int i = 0; i < k; i++){
    if (ret[i+1] > ne[i] || triggered) {
      triggered = true;
      ret[i+1] = ne[i];
    }
    if (ret[i+1] < ne[i] && !triggered) {
      return;
    }
  }
}

signed main() {
  freopen("SEQUENCE.inp", "r", stdin);
  freopen("SEQUENCE.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    na[0].push_back(a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    nb[0].push_back(b[i]);
  }
  for (int i = 1; i <= k; i++) {
    ret[i] = INT_MAX;
  }
  for (int i = 1; i <= n; i++) {
    int killed = na[i-1].size()-1;
    for (int j = 1 ; j < na[i-1].size()-1; j++) {
      if (na[i-1][j] > na[i-1][j-1] && na[i-1][j] > na[i-1][j+1]) {
        killed = j;
        break;
      }
    }
    for (int j = 0; j < na[i-1].size(); j++) {
      if (killed != j) {
        na[i].push_back(na[i-1][j]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int killed = nb[i-1].size()-1;
    for (int j = 1 ; j < nb[i-1].size()-1; j++) {
      if (nb[i-1][j] > nb[i-1][j-1] && nb[i-1][j] > nb[i-1][j+1]) {
        killed = j;
        break;
      }
    }
    for (int j = 0; j < nb[i-1].size(); j++) {
      if (killed != j) {
        nb[i].push_back(nb[i-1][j]);
      }
    }
  }
  for (int i = 0; i <= m+n-k; i++) {
    if (i <= n && m + n - k - i <= m)
      merge(na[i], nb[m+n-k-i]);
  }
  for (int i = 1; i <= k; i++) {
    cout << ret[i] << ' ';
  }
}
