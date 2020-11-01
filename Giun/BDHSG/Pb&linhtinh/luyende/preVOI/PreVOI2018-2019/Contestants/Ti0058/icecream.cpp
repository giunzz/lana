#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n, mx, a[5];
int dp[207][107][57], sv[207][107][57], ans = 0;
const int mod = 1e9 + 9, add = 150, add2 = 50;

int main(){
	#ifndef Dat
		freopen("icecream.inp", "r", stdin);
		freopen("icecream.out", "w", stdout);
	#endif
	scanf("%d %d", &n, &mx);
	for(int i = 1; i <= 3; i++){
		scanf("%d", &a[i]);
	}
	if(n > 50) return cout << 0, 0;
	sv[add][add2][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 200; j++){
			int rj = j - add;
			if(rj + a[1] < 0 || rj + a[1] > mx) continue;
			for(int k = 0; k <= 100; k++){
				int rk = k - add2;
				if(rk + a[2] < 0 || rk + a[2] > mx) continue;
				for(int p = 0; p < i; p++){
					if(p + a[3] < 0 || p + a[3] > mx) continue;
					if(sv[j][k][p] == 0) continue;
					dp[j + 1][k][p] = (dp[j + 1][k][p] + sv[j][k][p]) % mod;
					if(rj + a[1] > 0) dp[j - 1][k + 1][p] = (dp[j - 1][k + 1][p] + sv[j][k][p]) % mod;
					if(rk + a[2] > 0 && rj + a[1] > 0) dp[j - 1][k - 1][p + 1] = (dp[j - 1][k - 1][p + 1] + sv[j][k][p]) % mod;
					else if(rj + a[1] >= 3) dp[j - 3][k][p + 1] = (dp[j - 3][k][p + 1] + sv[j][k][p]) % mod;
				}
			}
		}
		for(int j = 0; j <= 200; j++){
			for(int k = 0; k <= 100; k++){
				for(int p = 0; p <= 50; p++){
					sv[j][k][p] = dp[j][k][p];
					dp[j][k][p] = 0;
				}
			}
		}
	}
	for(int j = 0; j <= 200; j++){
		int rj = j - add;
		if(rj + a[1] < 0 || rj + a[1] > mx) continue;
		for(int k = 0; k <= 100; k++){
			int rk = k - add2;
			if(rk + a[2] < 0 || rk + a[2] > mx) continue;
			for(int p = 0; p <= n; p++){
				if(p + a[3] < 0 || p + a[3] > mx) continue;
				ans = (ans + sv[j][k][p]) % mod;
			}
		}
	}
	printf("%d", ans);
}

