#include <bits/stdc++.h>

const int MOD = 1000000007;
const int MAXN = 20;
const int MAXS = MAXN*MAXN;
int n, a, x[MAXN], dp[2][2*MAXS];
using namespace std;
int add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
	freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    scanf("%d%d", &n, &a);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        x[i] -= a;
    }

    dp[0][MAXS] = 1;
    for(int i = 0; i < n; ++i) 
	{
        for(int j = 0; j < 2*MAXS; ++j) 
		{
            if (dp[0][j] > 0) {
			cerr << dp[0][j] << " ";
                add(dp[1][j], dp[0][j])%MOD;
                add(dp[1][j+x[i]], dp[0][j])%MOD;
            }
		}
        for(int j = 0; j < 2*MAXS; ++j) 
		{
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
		cerr << endl;
        
    }

    printf("%d", (dp[0][MAXS]-1+MOD)%MOD);

    return 0;
}