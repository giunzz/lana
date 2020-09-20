#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX_L = 12;
const int MAX_K = 85;
const int MOD = 1000000007;

int dp[MAX_L][MAX_K][MAX_K][MAX_K][3];
string N;
int K;

void init() {
  for (int i = 0; i < MAX_L; i++) {
    for (int rSum = 0; rSum < MAX_K; rSum++) {
      for (int rMul = 0; rMul < MAX_K; rMul++) {
        for (int r = 0; r < MAX_K; r++) {
          for (int status = 0; status < 3; status++) {
            dp[i][rSum][rMul][r][status] = 0;
          }
        }
      }
    }
  }
}

void DynamicProgramming(const string &N, int K) {
  if (K > MAX_K) {
    cout << 0 << endl;
    return;
  }
  init();
  int len = (int) N.size();
  for (int x = 1; x <= 9; x++) {
    int sta = 0;
    if (x == N[0] - '0') {
      sta = 1;
    }
    else if (x > N[0] - '0') {
      sta = 2;
    }
    dp[1][x % K][x % K][x % K][sta]++;
  }
  for (int i = 1; i < len; i++) {
    for (int rSum = 0; rSum < K; rSum++) {
      for (int rMul = 0; rMul < K; rMul++) {
        for (int r = 0; r < K; r++) {
          for (int status = 0; status <= 2; status++) {
            if (dp[i][rSum][rMul][r][status] == 0) {
              continue;
            }
            int val = dp[i][rSum][rMul][r][status];
            for (int dig = 0; dig <= 9; dig++) {
              int nxtrSum = (rSum + dig) % K;
              int nxtrMul = (rMul * dig) % K;
              int nxtr = (r * 10 + dig) % K;
              int nxtStatus = status;
              if (status == 1) {
                if (dig > N[i] - '0') {
                  nxtStatus = 2;
                }
                else if (dig < N[i] - '0') {
                  nxtStatus = 0;
                }
              }
              (dp[i + 1][nxtrSum][nxtrMul][nxtr][nxtStatus] += val) %= MOD;
            }
          }
        }
      }
    }
  }
  int res = (dp[len][0][0][0][0] + dp[len][0][0][0][1]) % MOD;
  for (int i = 1; i < len; i++) {
    (res += dp[i][0][0][0][0]) %= MOD;
    (res += dp[i][0][0][0][1]) %= MOD;
    (res += dp[i][0][0][0][2]) %= MOD;
  }
  cout << res << endl;
}

int main () {
  freopen("WC1.INP", "r", stdin);
  freopen("WC1.ans", "w", stdout);
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N >> K;
    DynamicProgramming(N, K);
  }
  return 0;
}