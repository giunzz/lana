/*input
10 2
1 2 4 5 2 4 6 6 2 6
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k, a[N];
int64_t sum[N], l[N], r[N];

int main(){
	#ifndef ToMo
		freopen("gifts.inp", "r", stdin);
		freopen("gifts.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}

	for(int i = k; i <= n; ++i)
		l[i] = max(l[i - 1], sum[i] - sum[i - k]);
	for(int i = n - k + 1; i > 0; --i)
		r[i] = max(r[i + 1], sum[i + k - 1] - sum[i - 1]);

	int64_t ans = 1e18;
	for(int i = 1; i + k - 1 <= n; ++i)
		ans = min(ans, max(l[i - 1], r[i + k]));
	cout << ans << '\n';
}
