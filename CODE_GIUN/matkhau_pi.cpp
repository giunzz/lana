
#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> r(n);
	for (int &x : r) cin >> x;
	int m;
	cin >> m;
	vector<int> b(m);
	for (int &x : b) cin >> x;
	partial_sum(r.begin(), r.end(), r.begin());
	partial_sum(b.begin(), b.end(), b.begin());
	cout << max(0, *max_element(r.begin(), r.end())) + max(0, *max_element(b.begin(), b.end())) << '\n';
}

int main() {
	int t;
    giuncute;
    freopen("matkhau.inp","r",stdin);
    freopen("matkhau.out","w",stdout);
	cin >> t;
	while (t--) solve();
}
