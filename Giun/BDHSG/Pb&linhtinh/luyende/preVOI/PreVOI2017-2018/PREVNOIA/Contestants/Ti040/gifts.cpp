#include <bits/stdc++.h>
using namespace std;

#define task "gifts"
#define maxN 1123456

int n,k;
int a[maxN];
long long res = 1123456789012345;
long long s[maxN],l[maxN],r[maxN];

int main() {
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for (int i=1; i<=k; ++i) s[i] = s[i-1] + a[i]; 
	l[k] = s[k];
	for (int i=k+1; i<=n; ++i) {
		//cerr << i << " ";
		s[i] = s[i-1] + a[i] - a[i-k];
		l[i] = max(l[i-1],s[i]);
	}
	for (int i=n; i>=n-k+1; --i) s[i] = s[i+1] + a[i];
	r[n-k+1] = s[n-k+1];
	for (int i=n-k; i>=1; --i) {
		s[i] = s[i+1] + a[i] - a[i+k];
		r[i] = max(r[i+1],s[i]);
	}
	for (int i=1; i<=n-k+1; ++i) { 
		res = min(res,max(l[i-1],r[i+k]));
		// cerr << i << " " << res << endl;
	}
	// for (int i=1; i<=n; ++i) cerr << l[i] << endl;
	printf("%lld\n", res);
}