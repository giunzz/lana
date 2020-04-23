#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 32;  
int test, n, K, T; 
int a[MAX_N], sum[MAX_N];
int dp[MAX_N][MAX_N][MAX_N]; 

int main () {
  freopen("SPC4.INP", "r", stdin);
  freopen("SPC4.OUT", "w", stdout);
  scanf("%d", &test);
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> K >> T;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];  
    }
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int cur = 0; cur < MAX_N; cur++) {
        for (int op = 0; op < MAX_N; op++) {
          dp[i][cur][op] = 0; 
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int cur = 0; cur < MAX_N; cur++) {
        for (int op = 0; op < MAX_N; op++) {
          for (int x = 0; x <= cur && x <= i - 1; x++) {
            dp[i][cur][op] = max(dp[i][cur][op], sum[i] - dp[i - 1 - x][op][cur - x]); 
          }
        }
      }   
    }
    int first = dp[n][K][T]; 
    int second = sum[n] - first;
    if (first < second) {
      cout << "LOSE";
    }
    else if (first > second) {
      cout << "WIN";
    }
    else {
      cout << "DRAW"; 
    }
    cout << endl;
  } 
  return 0; 
}