/*input
5
5 1 3 0 1
1 2
1 3
3 4
3 5
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 5005
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}
const int INF = 1e9;
int n;
int val[N];
int leaf[N];
int dp[5005][5005];
vector<vector<int> > a(N);

void dfs(int u) {
	if (a[u].size() == 0) leaf[u]++;
	for (int i = 0; i < a[u].size(); i++) {
		int v = a[u][i];
		dfs(v);
		leaf[u] += leaf[v];
	}
}

void rdfs(int u) {
	if (a[u].size() == 0) {
		dp[u][0] = val[u];
		dp[u][1] = abs(1 - val[u]);
		return;
	}
	if (a[u].size() == 1) {
		int v = a[u].front();
		rdfs(v);
		for (int i = 0; i <= leaf[u]; i++) dp[u][i] = dp[v][i] + abs(val[u] - i);
		return;
	}
	int v = a[u][0]; int z = a[u][1];
	rdfs(v); rdfs(z);
	for (int i = 0; i <= leaf[v]; i++) {
		for (int j = 0; j <= leaf[z]; j++) {
			dp[u][i + j] = min(dp[u][i + j], dp[v][i] + dp[z][j] + abs(val[u] - i - j));
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dp[i][j] = INF;
	}
	dfs(1);
	rdfs(1);
	int ans = INF;
	for (int i = 0; i <= leaf[1]; i++) ans = min(ans, dp[1][i]);
	cout << ans << endl;
}