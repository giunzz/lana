#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

long long read(){
	char p;
	while((p = getchar())){
		if(p < '0' || p > '9') continue;
		break;
	}
	long long ret = p - '0';
	while((p = getchar())){
		if(p >= '0' && p <= '9'){
			ret *= 10LL;
			ret += p - '0';
		}
		else break;
	}
	return ret;
}

int n, delta, l[4007], r[4007];
int dp[4007][4007], trace[4007][4007];
vector <int> ans;

int main(){
	#ifndef Dat
		freopen("liondance.inp", "r", stdin);
		freopen("liondance.out", "w", stdout);
	#endif
	n = read();
	delta = read();
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i <= n; i++) l[i] = read();
	for(int i = 1; i <= n; i++) r[i] = read();
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= n - i + 1; j++){
			if(j == 1){
				for(int k = n; k >= 1; k--){
					if(r[k] == l[i]){
						dp[i][j] = k;
						break;
					}
				}
				continue;
			}
			int mx = -1, sv = -1;
			for(int k = n; k > i; k--){
				if(dp[k][j - 1] != -1 && l[k] > l[i] && l[k] - l[i] <= delta){
					if(mx < dp[k][j - 1]) mx = dp[k][j - 1], sv = k;
				}
			}
			if(mx == -1) continue;
			for(int k = mx; k >= 1; k--){
				if(r[k] == l[i]){
					dp[i][j] = k;
					trace[i][j] = sv;
					break;
				}
			}
		}
	}
	int mx = 0;
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] != -1) mx = max(mx, j);
		}
	}
	int cur = -1;
	for(int i = 1; i <= n; i++){
		if(dp[i][mx] != -1){
			cur = i;
			break;
		}
	}
	while(mx > 0){
		ans.pb(l[cur]);
		cur = trace[cur][mx];
		mx--;
	}
	printf("%d\n", (int)ans.size());
	for(int x : ans) printf("%d ", x);
}
