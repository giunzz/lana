#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 33; 
const long long MOD = 1000000007; 
int n, p; 
int c[MAX_N]; 
int dp[2][MAX_N][MAX_N][MAX_N]; 
long long C[MAX_N][MAX_N]; 
long long odd[MAX_N], even[MAX_N]; 
long long pw[MAX_N]; 

void init() {
  pw[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    pw[i] = (pw[i - 1] * 2LL) % MOD; 
  }
  for (int i = 0; i < MAX_N; i++) {
    C[i][0] = 1LL;
    C[i][i] = 1LL; 
  }
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j <= i; j += 2) {
      (even[i] += C[i][j]) %= MOD; 
    }
    for (int j = 1; j <= i; j += 2) {
      (odd[i] += C[i][j]) %= MOD; 
    }
  }
}

int main () {
  freopen("SC6.INP", "r", stdin);
  freopen("SC6.OUT", "w", stdout);
  init();
  int test; 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &c[i]); 
    }
    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1])); 
    dp[0][0][0][0] = 1LL; 
    for (int i = 0; i < n; i++) {
      int now = i & 1; 
      int nxt = !now; 
      memset(dp[nxt], 0, sizeof(dp[nxt])); 
      for (int ew = 0; ew <= i; ew++) {
        for (int eb = 0; eb + ew <= i; eb++) {
          for (int ow = 0; eb + ew + ow <= i; ow++) {
            if (dp[now][ew][eb][ow] == 0) {
              continue; 
            }
            long long v = dp[now][ew][eb][ow]; 
            int ob = i - ew - eb - ow;
            if (c[i + 1] != 0) {
              (dp[nxt][ew][eb][ow] += ((v * pw[eb + ob + ew]) % MOD * even[ow]) % MOD) %= MOD; 
              (dp[nxt][ew][eb + 1][ow] += ((v * pw[eb + ob + ew]) % MOD * odd[ow]) % MOD) %= MOD; 
            } 
            if (c[i + 1] != 1) {
              (dp[nxt][ew][eb][ow + 1] += ((v * pw[ew + ow + eb]) % MOD * even[ob]) % MOD) %= MOD; 
              (dp[nxt][ew + 1][eb][ow] += ((v * pw[ew + ow + eb]) % MOD * odd[ob]) % MOD) %= MOD; 
            }
          }
        }
      }
    }
    long long res = 0LL; 
    for (int ew = 0; ew <= n; ew++) {
      for (int eb = 0; eb + ew <= n; eb++) {
        for (int ow = 0; eb + ew + ow <= n; ow++) {
          int ob = n - ew - eb - ow; 
          if ((ow + ob) % 2 == p) {
            (res += dp[n & 1][ew][eb][ow]) %= MOD; 
          }
        }
      }
    }
    printf("%lld\n", res); 
  }
  return 0; 
}