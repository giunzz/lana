#include <bits/stdc++.h>
using namespace std;

const int N = 35000;
typedef pair<int,int> ii;

int d[N];
int A, B;
vector<int> pr;
map<int, int> mp;

void sieve() {
	d[0] = d[1] = 1;
	for (int i = 2; i < N; ++i) if (!d[i]) {
		for (int j = i; j < N; j += i) d[j] = i;
		pr.push_back(i);
	}
}

void calc(int x) {
	int tmp = x;
	for (int i = 0; i < pr.size() && 1LL * pr[i] * pr[i] <= x; ++i) {
		if (tmp % pr[i]) continue;
		while(tmp % pr[i] == 0) tmp /= pr[i], mp[pr[i]]++;
	}
	if (tmp > 1) mp[tmp]++;
}

void solve() {
	mp.clear();
	cin >> A >> B;
	calc(A);
	calc(B);
	vector<int> vals;
	long long val = 1;
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		if (it->second % 2 == 0) continue;
		vals.push_back(it->first);
		val = val * vals.back();
	}
	
	vector<long long> dvs;
	dvs.push_back(1);

	long long mn = val + 1;
	long long ax = 1, ay = val;
	for (int i = 0; i < vals.size(); ++i) {
		int sz = dvs.size();
		for (int j = 0; j < sz; ++j) {
			long long cur = 1LL * vals[i] * dvs[j];
			if (cur + val / cur < mn) {
				mn = cur + val / cur;
				ax = cur; ay = val / cur;
			}
		}	
	}

	printf("%lld %lld\n", ax, ay);
}

int main() {
	freopen("MINSUM.inp", "r", stdin);
	freopen("MINSUM.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();

	int tt; cin >> tt;
	while(tt--) {
		solve();
	}
}