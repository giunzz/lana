/*input
8
2 2 2 2 1 9 1 2
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int a[N], DragRight, n, low_bound;
int ans = 0, sum = 0, res = 1e18;
vector<pair<int, int> > v;

int cost(int r, int index){
	int l = r - v[index].second + 1, mid = v[index].first;
	if(l <= mid && mid <= r){
		int leftsum = (mid - l) * (mid - l + 1) >> 1;
		int rightsum = (r - mid) * (r - mid + 1) >> 1;
		return leftsum + rightsum;
	}
	if(mid <= l) return (l + r - (mid << 1)) * (r - l + 1) >> 1;
	return ((mid << 1) - (l + r)) * (r - l + 1) >> 1;
}

void solve(){
	v.clear(); DragRight = ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > more, less;
	for(int i = 1; i <= n; ++i){
		if(a[i] < low_bound){
			int cost = low_bound - a[i];
			while(!more.empty()){
				pair<int, int> u = more.top(); more.pop();
				int D = min(u.second, cost);
				cost -= D, u.second -= D, DragRight -= D;
				if(u.second != 0) more.push(u);
				if(cost == 0) break;
			}
			if(cost > 0) less.push(make_pair(i, cost));
		}
		else if(a[i] > low_bound){
			int Fee = a[i] - low_bound;
			while(!less.empty()){
				pair<int, int> u = less.top(); less.pop();
				int D = min(u.second, Fee);
				Fee -= D, u.second -= D;
				if(u.second != 0) less.push(u);
				if(Fee == 0) break;
			}
			if(Fee > 0) more.push(make_pair(i, Fee));
			DragRight += Fee;
		}
		ans += DragRight;
	}

	int m = 0;
	while(!more.empty())
		v.push_back(more.top()), more.pop(), ++m;

	for(int i = 0; i < m; ++i)
		ans -= (n + 1 - v[i].first) * v[i].second;

	vector<vector<int> > dp(n + 1, vector<int>(v.size() + 1, 1e18));
	for(int i = 1; i <= n; ++i)
		dp[i][0] = 0;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			dp[i][j] = dp[i - 1][j];
			if(i >= v[j - 1].second)
				dp[i][j] = min(dp[i][j], dp[i - v[j - 1].second][j - 1] + cost(i, j - 1));
		}
	res = min(res, ans + dp[n][m]);
}

signed main(){
	#ifndef ToMo
		freopen("arrange.inp", "r", stdin);
		freopen("arrange.out", "w", stdout);
	#endif

	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		sum += a[i];
	}

	low_bound = sum / n;
	solve();
	reverse(a + 1, a + n + 1); 
	solve();

	printf("%lld\n", res);
}