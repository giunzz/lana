#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int a, b;
long long n, k, pw = 1, rem, hal;
int ok[1 << 22];

void print(int mask1, int mask2){
	for(int i = 0; i < hal; i++){
		if(mask1 & (1 << i)) printf("%d", b);
		else printf("%d", a);
	}
	for(int i = 0; i < rem; i++){
		if(mask2 & (1 << i)) printf("%d", b);
		else printf("%d", a);
	}
	exit(0);
}

int main(){
	#ifndef Dat
		freopen("modulo.inp", "r", stdin);
		freopen("modulo.out", "w", stdout);
	#endif
	scanf("%d %d", &a, &b);
	scanf("%lld %lld", &n, &k);
	if(n == 1){
		if(a % k == 0) cout << a;
		else if(b % k == 0) cout << b;
		else cout << -1;
		return 0;
	}
	for(int i = 1; i <= n; i++) pw *= 2LL;
	if(n > 42){
		cout << -1;
		return 0;
	}
	memset(ok, -1, sizeof(ok));
	hal = (n + 1) / 2;
	for(int mask = 0; mask < (1 << hal); mask++){
		long long cur = 0;
		for(int i = 0; i < hal; i++){
			cur = cur * 10 % pw;
			if(mask & (1 << i)){
				cur = (cur + b) % pw;
			}
			else cur = (cur + a) % pw;
		}
		for(int i = hal; i < n; i++) cur = (cur * 10LL) % pw;
		ok[cur] = mask;
	}
	rem = n - hal;
	for(int mask = 0; mask < (1 << rem); mask++){
		long long cur = 0;
		for(int i = 0; i < rem; i++){
			cur = cur * 10 % pw;
			if(mask & (1 << i)){
				cur = (cur + b) % pw;
			}
			else cur = (cur + a) % pw;
		}
		if(cur <= k && ok[k - cur] != -1) print(ok[k - cur], mask);
		else if(cur > k && ok[pw - cur + k] != -1) print(ok[pw - cur + k], mask);
	}
	printf("-1");
}
