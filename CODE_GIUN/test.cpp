#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (1e5 + 7)
#define MASK (int) 16
#define INF (long long) (1e9)

int n; 
int arr[5][MAX_N];
long long dp[MAX_N][MASK] = {-INF};
int maximum = -INF;
bool oke = false;
long long check[16] = {0 , 1 , 2 , 4 , 5 , 8 , 9 , 10};
string pl[16] = {"0000" , "0001" , "0010" , "0100" , "0101" , "1000" , "1001" , "1010"};

void calc() {
	for (int mask = 0 ; mask < 8 ; mask ++) 
		dp[0][check[mask]] = 0;
	for (int i = 1 ; i <= n ; i++) 
		for (int mask = 0 ; mask < 8 ; mask ++) {
			for (int mask1 = 0 ; mask1 < 8 ; mask1 ++) 
				if ((check[mask] & check[mask1]) == 0) {
					long long val = 0;
					for (int k = 0 ; k < 4 ; k++) {
						if (pl[mask][k] == '1') {
							val += arr[k + 1][i];
						}
					} 
					if (dp[i][check[mask]] < dp[i - 1][check[mask1]] + val) {
						dp[i][check[mask]] = dp[i - 1][check[mask1]] + val;
						oke = true;

					}
					//dp[i][check[mask]] = max(dp[i][check[mask]] , dp[i - 1][check[mask1]] + val);
				}
		}
	long long ans = maximum;
	if (!oke) {
		cout << maximum;
		return;
	}
	for (int go = 0 ; go < 8 ; go ++){
		//cout << dp[n][check[go]] << " ";
		ans = max(ans , dp[n][check[go]]);
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= 4 ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> arr[i][j];
			if (arr[i][j] < 0) 
				maximum = max(maximum , arr[i][j]);
		}
	}
	calc();
	return 0;
}