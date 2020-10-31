/*input
3 4 2
5 2 4 2
3 2 6 8
7 8 9 3
1 1 3 4
1 2 2 4
*/
#include <bits/stdc++.h>
using namespace std;

#define cin fin
#define cout fout
ifstream fin("table.inp");
ofstream fout("table.out");

const int N = 305;
int a[N][N], Back[N][N], To[N][N], n, m, k;
int diag[N << 1][N << 1], Top[N << 1], pref[N << 1], suf[N << 1];

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= m; ++ j) cin >> a[i][j];
	while(k --) {
		int u, v, p, q; cin >> u >> p >> v >> q;

		memset(To, 0, sizeof To), memset(Back, 0, sizeof Back), memset(Top, 0, sizeof Top);
		for(int i = u; i <= v; ++ i) for(int j = p; j <= q; ++ j) 
			To[i][j] = max(To[i - 1][j], To[i][j - 1]) + a[i][j];
		for(int i = v; i >= u; -- i) for(int j = q; j >= p; -- j) 
			Back[i][j] = max(Back[i + 1][j], Back[i][j + 1]) + a[i][j];
		for(int i = u; i <= v; ++ i) for(int j = p; j <= q; ++ j)
			diag[i - u + j - p][Top[i - u + j - p] ++] = To[i][j] + Back[i][j] - a[i][j];

		int Ans = 2e9;
		for(int i = 1; i < q - p + v - u; ++ i) {
			suf[Top[i]] = 0;
			for(int j = 0; j < Top[i]; ++ j) pref[j] = max(j ? pref[j - 1] : 0, diag[i][j]);
			for(int j = Top[i] - 1; j >= 0; -- j) suf[j] = max(suf[j + 1], diag[i][j]);
			for(int j = 0; j < Top[i]; ++ j) Ans = min(Ans, max(suf[j + 1], j ? pref[j - 1] : 0));
		}
		cout << Ans << '\n';
	}
}