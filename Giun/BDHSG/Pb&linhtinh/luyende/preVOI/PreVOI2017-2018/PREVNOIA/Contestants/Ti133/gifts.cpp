#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, k;
int a[N];
long long val[N];
long long sum[N];
multiset < long long > f;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	else{
		freopen("gifts.inp", "r", stdin);
		freopen("gifts.out", "w", stdout);
	}

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}

	for(int i = 0; i < k; ++i){
		val[i] = 1e18;
	}

	for(int i = k; i <= n; ++i){
		val[i] = sum[i] - sum[i - k];
	}

	for(int i = n; i >= k + k; --i){
		f.insert(val[i]);
	}

	long long ans = 1e18;

	for(int i = k; i <= n; ++i){
		if(i > k) f.insert(val[i - k]);
		if(i + k <= n) f.erase(f.find(val[i + k]));
		ans = min(ans, *f.rbegin());
	}

	cout << ans;

	return 0;
}