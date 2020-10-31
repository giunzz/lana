/*input
8 3
2 1 2 3 9 4 5 7
2 3 2 1 7 4 5 9
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int l[N], r[N], dp[N][N], n, D, x, Ans = 0;
pair<int, int> trace[N][N], save;

int main(){
	#ifndef ToMo
		freopen("liondance.inp", "r", stdin);
		freopen("liondance.out", "w", stdout);
	#endif // ToMo

	scanf("%d%d", &n, &D);
	for(int i = 1; i <= n; ++ i) scanf("%d", &l[i]);
	for(int i = 1; i <= n; ++ i) scanf("%d", &r[i]);
	reverse(l + 1, l + n + 1), reverse(r + 1, r + n + 1);

	memset(dp, -63, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= n; ++ i) for(int j = 0; j <= n; ++ j) {
		if(l[i] != r[j]) continue;
		if(i && j && dp[i][j] < 0) dp[i][j] = 1;
		for(int k = i + 1; k <= n; ++ k) if(abs(l[i] - l[k]) <= D)
				for(int h = j + 1; h <= n; ++ h)
					if((l[k] == r[h]) && 
						(dp[k][h] < dp[i][j] + 1 || ((dp[k][h] == dp[i][j] + 1) && (l[trace[k][h].first] < l[i])))) {
						dp[k][h] = dp[i][j] + 1;
						trace[k][h] = make_pair(i, j);
					}
		if(Ans < dp[i][j] || (Ans == dp[i][j] && x <= l[i])) save = make_pair(i, j), Ans = dp[i][j], x = l[i];
	}

	vector<int> v;
	while(save != pair<int, int>(0, 0)) {
		v.emplace_back(l[save.first]);
		save = trace[save.first][save.second];
	}

	cout << Ans << endl;
	for(auto x : v) cout << x << ' ';
		cout << endl;
}