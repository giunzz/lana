/*input
8 6
1 4 5 6 7 8
1 2 1
2 3 10
3 4 1
2 5 6
2 6 6
3 7 6
3 8 6

8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 50005
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

#define ll long long
int n, k;
bool mark[N];
vector<vector<pair<int, int> > > a(N);
ll lim;

ll dfs(int u, int p) {
	vector<ll> cur;
	if (mark[u]) cur.push_back(0);
	for (int i = 0; i < a[u].size(); i++) {
		int v = a[u][i].fi; ll c = a[u][i].se;
		if (v == p) continue;
		ll rec = dfs(v, u);
		if (rec == -1) continue;
		cur.push_back(rec + c);
	}
	sort(cur.begin(), cur.end());
	if (cur.size() % 2 == 0) {
		for (int i = 0; i < cur.size() / 2; i++) {
			if (cur[i] + cur[cur.size() - 1 - i] > lim) throw 1;
		}
		return -1;
	}
	int it = cur.size() - 1;
	ll ret = -1;
	for (int i = 0; i < cur.size() / 2; i++) {
		if (cur[i] + cur[it] > lim) {
			if (ret == -1) {
				ret = cur[it]; it--;
				if (cur[i] + cur[it] > lim) throw 1;
			}
			else throw 1;
		}
		it--;
	}
	if (ret != -1) return ret;
	it = cur.size() / 2 - 1;
	for (int i = cur.size() / 2 + 1; i < cur.size(); i++) {
		if (cur[i] + cur[it + 1] > lim)
			return cur[it + 1];
	}
	return cur[0];
}

bool check(ll x) {
	lim = x;
	try {
		dfs(1, 1);
	} catch (...) {
		return false;
	}
	return true;
}

signed main() {
	freopen("BUBBLETEA.inp", "r", stdin);
	freopen("BUBBLETEA.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int t; scanf("%d", &t); mark[t] = true;
	}
	ll sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		int u, v, c; scanf("%d %d %d", &u, &v, &c); sum += c;
		a[u].push_back(mp(v, c));
		a[v].push_back(mp(u, c));
	}
	ll l = 1, r = sum;
	while (l != r) {
		ll mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l);
}