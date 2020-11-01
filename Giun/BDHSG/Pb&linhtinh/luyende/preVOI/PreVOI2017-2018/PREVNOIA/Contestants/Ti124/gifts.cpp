#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 6;
const ll inf = 1e16 + 6;

int n, k, a[N];

void read(int &X){
	char c;
	do {c = getchar(); } while (!isdigit(c));
	int val = c - '0';
	while (isdigit(c = getchar())) val = val * 10 + c - '0';
	X = val;
}

void enter(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("gifts.inp", "r", stdin);
	freopen("gifts.out", "w", stdout);
	
	read(n); read(k);
	for (int i = 1; i <= n; i++){
		read(a[i]);
	}
}

ll s[N], maxL[N], maxR[N];

void solve(){
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + 1LL * a[i];
	for (int i = 1; i <= n; i++){
		if (i + k - 1 > n) maxL[i] = -inf;
		else
			maxL[i] = max(maxL[i - 1], s[i + k - 1] - s[i - 1]);
	}
	
	for (int i = n; i >= 1; i--){
		if (i + k - 1 > n) maxR[i] = -inf;
		else
			maxR[i] = max(maxR[i + 1], s[i + k - 1] - s[i - 1]);
	}
	
	ll res = inf;
	
	for (int i = 1; i <= n - k + 1; i++){
		ll foo = (i + k + k - 1 <= n ? maxR[i + k] : 0);
		ll bar = (i - k >= 1 ? maxL[i - k] : 0);
		ll max1 = max(foo, bar);
		res = min(res, max1);
	}
	cout << res;
}

main(){
	enter();
	solve();
}