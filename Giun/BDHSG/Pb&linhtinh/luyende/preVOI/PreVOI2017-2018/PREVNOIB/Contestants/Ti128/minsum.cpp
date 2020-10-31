/*input
3
4 5
3231 303120
4 6
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ToMo
		freopen("minsum.inp", "r", stdin);
		freopen("minsum.out", "w", stdout);
	#endif

	int t; scanf("%d", &t);
	while(t--){
		int a, b; scanf("%d%d", &a, &b);

		int d = __gcd(a, b), ans = 2e9;
		pair<int, int> save;
		a /= d, b /= d;

		for(int i = 2; i * i <= max(a, b); ++i){
			while(a % (i * i) == 0) a /= i * i;
			while(b % (i * i) == 0) b /= i * i;
		}
		ans = (a + b), save = make_pair(a, b);

		for(int i = 2; i * i <= a; ++i){
			if(a % i != 0) continue;

			int64_t A = a / i, B = 1ll * b * i;
			if(A + B < ans){
				ans = A + B;
				save = make_pair(A, B);
			}

			A = i, B = 1ll * b * a / i;
			if (A + B < ans){
				ans = A + B;
				save = make_pair(A, B);
			}
		}

		for(int i = 2; i * i <= b; ++i){
			if(b % i != 0) continue;

			int64_t A = 1ll * a * i, B = b / i;
			if(A + B < ans){
				ans = A + B;
				save = make_pair(A, B);
			}

			A = 1ll * a * b / i, B = i;
			if (A + B < ans){
				ans = A + B;
				save = make_pair(A, B);
			}
		}

		printf("%d %d\n", save.first, save.second);
	}
}