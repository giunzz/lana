#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

const int mxN=2e5;
int n, a[mxN];
ll b[mxN+1], ans;
map<ll, int> mp;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    fi;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b[i+1]=b[i]+a[i];
	}
    for (int i = 0; i <= n; i++) cerr << mp[b[i]] << " " << b[i] << " " << i << endl;
    cerr << endl;
	for(int i=0, j=0; i<=n; ++i) {
		++mp[b[i]];
        cerr << mp[b[i]] << " " << b[i] << " " << i << endl;
		while(mp[b[i]]>1) {
			--mp[b[j++]];
		}
		ans+=i-j;
	}
	cout << ans;
}