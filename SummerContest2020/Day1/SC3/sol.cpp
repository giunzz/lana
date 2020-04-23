#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 10000005; 
int test; 
vector <pair <int, int> > save; 
bool isCover[MAX_N << 2]; 

void update(int index, int L, int R, int l, int r) {
  if (r < L || l > R) {
    return;
  }    
  if (isCover[index] == 1) {
    return; 
  }
  if (l <= L && R <= r) {
    isCover[index] = 1; 
    if (L != R) {
      int mid = (L + R) >> 1; 
      update(2 * index, L, mid, l, r);
      update(2 * index + 1, mid + 1, R, l, r);
    }
    return; 
  }
  if (L != R) {
    int mid = (L + R) >> 1; 
    update(2 * index, L, mid, l, r); 
    update(2 * index + 1, mid + 1, R, l, r); 
    isCover[index] = isCover[2 * index] & isCover[2 * index + 1]; 
  }
}

int isCovered(int index, int L, int R, int l, int r) {
  if (l > R || r < L) {
    return 1; 
  }
  if (l <= L && R <= r) {
    return isCover[index]; 
  }
  int mid = (L + R) >> 1; 
  int v1 = isCovered(2 * index, L, mid, l, r); 
  int v2 = isCovered(2 * index + 1, mid + 1, R, l, r); 
  return (v1 & v2); 
}

int main () {
  freopen("SC3.INP", "r", stdin);
  freopen("SC3.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    int n, m;
    cin >> n >> m; 
    save.clear(); 
    int L = MAX_N;
    int R = -1; 
    for (int i = 1; i <= n; i++) {
      int l, r; 
      cin >> l >> r; 
      L = min(L, l);
      R = max(R, r); 
      save.push_back(make_pair(l, r));
    }                         
    memset(isCover, 0, sizeof(isCover));  
    int res = 0; 
    for (int i = n - 1; i >= 0; i--) {
      if (isCovered(1, L, R, save[i].first, save[i].second) == 0) {
        res++;
        update(1, L, R, save[i].first, save[i].second); 
      }    
    }                               
    cout << res << endl; 
  }
  return 0; 
}