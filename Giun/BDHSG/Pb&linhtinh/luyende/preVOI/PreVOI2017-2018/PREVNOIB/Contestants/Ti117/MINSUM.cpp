/*input
2
100 102
4 6
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
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

map<int, int> cnt;
map<int, int>::iterator it;

void fact(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			while (x % i == 0) {
				cnt[i]++; x /= i;
			}
		}
	}
	if (x > 1) cnt[x]++;
}

vector<int> a;
vector<int> b[2];
int ans = 1e18;
pair<int, int> order;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("MINSUM.inp", "r", stdin);
	freopen("MINSUM.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		ans = 1e18; b[0].clear(); b[1].clear(); a.clear(); cnt.clear();
		int A, B; cin >> A >> B;
		fact(A); fact(B);
		int prod = 1;
		for (it = cnt.begin(); it != cnt.end(); it++) {
			if (it->se % 2 == 1) a.push_back(it->fi), prod *= it->fi;
		}
		int z = a.size() / 2;
		for (int mask = 0; mask < (1 << z); mask++) {
			int ret = 1;
			for (int i = 0; i < z; i++) if (bit(mask, i)) ret = (ret * a[i]);
			b[0].push_back(ret);
		}
		for (int mask = 0; mask < (1 << (a.size() - z)); mask++) {
			int ret = 1;
			for (int i = 0; i < a.size() - z; i++) if (bit(mask, i)) ret = (ret * a[z + i]);
			b[1].push_back(ret);
		}
		sort(b[0].begin(), b[0].end()); sort(b[1].begin(), b[1].end());
		for (int i = 0; i < b[0].size(); i++) {
			int rem = prod / b[0][i];
			vector<int>::iterator it = upper_bound(b[1].begin(), b[1].end(), rem);
			if (it != b[1].begin()) it--;
			int curans = b[0][i] * (*it) + prod / (b[0][i] * (*it));
			if (ans > curans) {
				ans = curans;
				order = mp(b[0][i] * (*it), prod / (b[0][i] * (*it)));
			}
		}
		cout << order << endl;
	}

}