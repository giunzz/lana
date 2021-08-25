#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 998244353;
const int MAX_N = 40;
const int MAX_D = MAX_N;
int dp[MAX_N][MAX_D][3][MAX_D][3][MAX_D][3];
bool skill[MAX_N][2];
int n, d;
int numTest;

void update(int &a, int b) {
  (a += b) %= MOD;
}

void dynamicProgramming() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int dRemain = 0; dRemain <= d + 1; dRemain++) {
      for (int friendRemain = 0; friendRemain <= 2; friendRemain++) {
        for (int dSing = 0; dSing <= d + 1; dSing++) {
          for (int friendSing = 0; friendSing <= 2; friendSing++) {
            for (int dDance = 0; dDance <= d + 1; dDance++) {
              for (int friendDance = 0; friendDance <= 2; friendDance++) {
                if (dp[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance] == 0) {
                  continue;
                }
                int curValue = dp[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance];
                if (friendRemain == 0) {
                  update(dp[i + 1][0][1][min(dSing + 1, d + 1)][friendSing][min(dDance + 1, d + 1)][friendDance], curValue);
                }
                if (friendRemain == 1 && dRemain < d) {
                  update(dp[i + 1][0][2][min(dSing + 1, d + 1)][friendSing][min(dDance + 1, d + 1)][friendDance], curValue);
                }
                if (friendRemain == 2) {
                  if (dRemain < d) {
                    update(dp[i + 1][0][2][min(dSing + 1, d + 1)][friendSing][min(dDance + 1, d + 1)][friendDance], curValue);
                  }
                  else {
                    update(dp[i + 1][0][1][min(dSing + 1, d + 1)][friendSing][min(dDance + 1, d + 1)][friendDance], curValue);  
                  }
                }
                if (skill[i + 1][0] == true) {
                  if (friendSing == 0) {
                    update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][0][1][min(dDance + 1, d + 1)][friendDance], curValue);
                  }
                  if (friendSing == 1 && dSing < d) {
                    update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][0][2][min(dDance + 1, d + 1)][friendDance], curValue);
                  }
                  if (friendSing == 2) {
                    if (dSing < d) {
                      update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][0][2][min(dDance + 1, d + 1)][friendDance], curValue);
                    }
                    else {
                      update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][0][1][min(dDance + 1, d + 1)][friendDance], curValue);
                    }
                  }
                }
                if (skill[i + 1][1] == true) {
                  if (friendDance == 0) {
                    update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][min(dSing + 1, d + 1)][friendSing][0][1], curValue);
                  }
                  if (friendDance == 1 && dDance < d) {
                    update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][min(dSing + 1, d + 1)][friendSing][0][2], curValue);
                  }
                  if (friendDance == 2) {
                    if (dDance < d) {
                      update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][min(dSing + 1, d + 1)][friendSing][0][2], curValue);
                    }
                    else {
                      update(dp[i + 1][min(dRemain + 1, d + 1)][friendRemain][min(dSing + 1, d + 1)][friendSing][0][1], curValue);
                    }
                  } 
                }
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int dRemain = 0; dRemain <= d + 1; dRemain++) {
    for (int dSing = 0; dSing <= d + 1; dSing++) {
      for (int dDance = 0; dDance <= d + 1; dDance++) {
        update(ans, dp[n][dRemain][0][dSing][2][dDance][2]);
        update(ans, dp[n][dRemain][2][dSing][2][dDance][2]);
      }
    }
  }
  cout << ans << endl;
}

int main () {
  freopen("ac2.inp", "r", stdin);
  freopen("ac2.ans", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      skill[i][0] = false;
      skill[i][1] = false;
    }
    int numSing, numDance;
    cin >> numSing;
    for (int i = 1; i <= numSing; i++) {
      int id;
      cin >> id;
      skill[id][0] = true;
    }
    cin >> numDance;
    for (int i = 1; i <= numDance; i++) {
      int id;
      cin >> id;
      skill[id][1] = true;
    }
    dynamicProgramming();
  }
  return 0; 
}