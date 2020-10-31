
#define task "gifts"
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int n, k, a[maxN];
long long sum[maxN], maxL[maxN], maxR[maxN];

template<class T> inline bool maximize(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T> inline bool minimize(T& a, const T& b){ return a > b ? a = b, 1 : 0; }

int main(){
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	long long ans, tmp;

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + a[i];

	for (int i = k; i <= n; ++i) maxL[i] = max(maxL[i-1], sum[i] - sum[i-k]);
	for (int i = n-k+1; i >= 1; --i) maxR[i] = max(maxR[i+1], sum[i+k-1] - sum[i-1]);

	ans = (long long) k * (1e6) + 1;

	for (int i = 1; i <= n-k+1; ++i){
		tmp = 0;
		if (i-1-k >= 0) maximize(tmp, maxL[i-1]);
		if (i+k <= n-k+1) maximize(tmp, maxR[i+k]);
		minimize(ans, tmp);
	}

	printf("%lld\n", ans);

	return 0;
}
