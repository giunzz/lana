#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define II pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
const int N = 3005;
int m, n, k, a[N], b[N], visit[105][105][105];
vector<int> dp[105][105][105], rong;
vector<int> calc(int len, int i, int j)
{
	if(len == 0) return rong;
	if(visit[len][i][j]) return dp[len][i][j]; 
	visit[len][i][j] = 1;
	int min_a = 2 * 1e9, min_b = 2 * 1e9, id_a = 0, id_b = 0;
	for(int ii = i + 1; ii <= m && len - 1 <= m - ii + n - j; ii ++)
		if(a[ii] < min_a){
			min_a = a[ii];
			id_a = ii;
		}
	for(int jj = j + 1; jj <= n && len - 1 <= m - i + n - jj; jj ++)
		if(b[jj] < min_b){
			min_b = b[jj];
			id_b = jj;
		}
	if(min_a < min_b){
		auto tmp = calc(len - 1, id_a, j);
		dp[len][i][j].pb(min_a);
		for(int val : tmp) dp[len][i][j].pb(val);
	}
	else if(min_b < min_a){
		auto tmp = calc(len - 1, i, id_b);
		dp[len][i][j].pb(min_b);
		for(int val : tmp) dp[len][i][j].pb(val);
	}
	else{
		auto tmp = min(calc(len - 1, id_a, j), calc(len - 1, i, id_b));
		dp[len][i][j].pb(min_a);
		for(int val : tmp) dp[len][i][j].pb(val);
	}
	return dp[len][i][j];
}
int main()
{
	freopen("SEQUENCE.inp", "r", stdin);
	freopen("SEQUENCE.out", "w", stdout);
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n >> k;
	for(int i = 1; i <= m; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> b[i];
	calc(k, 0, 0);
	for(int i : dp[k][0][0]) cout << i << ' ';
}