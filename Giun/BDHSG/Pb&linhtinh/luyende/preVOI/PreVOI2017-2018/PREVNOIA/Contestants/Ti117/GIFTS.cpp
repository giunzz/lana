/*input
4 3
9 0 9 0
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 1000005
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

int n, k;
int a[N];
int sum[N];
int mxleft[N], mxright[N];

void prepLeft() {
	deque<pair<int, int> > dq;
	int cursum = 0;
	for (int i = 1; i <= n; i++) {
		cursum += a[i];
		while (!dq.empty() && dq.front().fi <= i - k) cursum -= dq.front().se, dq.pop_front();
		dq.push_back(mp(i, a[i]));
		mxleft[i] = max(mxleft[i - 1], cursum);
	}
}

void prepRight() {
	deque<pair<int, int> > dq;
	int cursum = 0;
	for (int i = n; i >= 1; i--) {
		cursum += a[i];
		while (!dq.empty() && dq.front().fi >= i + k) cursum -= dq.front().se, dq.pop_front();
		dq.push_back(mp(i, a[i]));
		mxright[i] = max(mxright[i + 1], cursum);
	}
}

void solve() {
	int ans = 1e18;
	for (int i = 1; i <= n; i++)
		ans = min(ans, max(mxleft[i - 1], mxright[min(n + 1, i + k)]));
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("GIFTS.inp", "r", stdin);
	freopen("GIFTS.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
	prepLeft(); prepRight();
	solve();
}