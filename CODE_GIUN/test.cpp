#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int sol(int N, int K) 
{
    long long dp[N+7][K+1];
    for(int i = 1; i <= N; i++)dp[i][0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            int val = dp[i-1][j];
            if(j >= i)
                val = (val % MOD - dp[i-1][j-i] % MOD ) % MOD;
            dp[i][j] = (dp[i][j-1]%MOD + val % MOD) % MOD;
        }
    }
    int ans = dp[N][K];
    if(K >= 1)
        ans = (ans % MOD - dp[N][K-1]%MOD);
    return ans;
}
int main() 
{
    int N , K;
    cin >> N >> K;
    cout << sol(N,K) ;
    return 0;
}