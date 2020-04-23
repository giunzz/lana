#include <bits/stdc++.h> 

using namespace std;
vector <pair <int, int> > save; 
int n, m, test; 
const int MAX_N = 100005; 
int mark[MAX_N];
bool check[MAX_N];

int main () {
  freopen("SC3.INP", "r", stdin);
  freopen("SC3.OUT", "w", stdout); 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> m;
    for (int i = 1; i < MAX_N; i++) {
      mark[i] = 0;
      check[i] = false; 
    }
    for (int i = 1; i <= n; i++) {
      int l, r; 
      cin >> l >> r; 
      for (int j = l; j <= r; j++) {
        mark[j] = i; 
      }
    }
    int res = 0;
    for (int i = 1; i < MAX_N; i++) {
      if (mark[i] != 0 && check[mark[i]] == false) {
        check[mark[i]] = true; 
        res++; 
      }
    }
    cout << res << endl; 
  }
  return 0; 
}