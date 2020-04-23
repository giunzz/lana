#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7, maxv = 50*1e3 + 7;
int n, w[maxn], v[maxn], c, dp[maxn][maxv] = {{0}}, mav = 0, vj = 0;

void enter(){
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> v[i], mav += v[i];
    for (int i = 1; i <= n; i++) cin >> w[i], dp[i][v[i]] = w[i], vj = max(vj, v[i]);
}

void supsol(int i, int j){
    //if (i == 48 && j == 6) cerr << 1;
    if (dp[i][j] == 0) dp[i][j] = dp[i - 1][j];
    else if (dp[i - 1][j]) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
}

void sol(){
    int num;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= mav; j++){
            //dp[i][j] = dp[i - 1][v[i - 1]];
            if (j >= v[i]){
                //if (i == 4) cerr << j << " ";
                if (dp[i - 1][j - v[i]] + w[i] <= c && dp[i - 1][j - v[i]] != 0){ 
                    num = dp[i - 1][j - v[i]] + w[i];
                    if (dp[i][j] != 0) dp[i][j] = min(dp[i][j], num);
                    else dp[i][j] = num;
                    vj = max(vj, j);
                }
                else{
                    supsol(i, j);
                }
            }
            else supsol(i, j);
        }
    }
    //cout << vj << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("knapsack.inp", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    enter();
    sol();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= mav; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << vj;
    //cerr << mav;
    return 0;
}